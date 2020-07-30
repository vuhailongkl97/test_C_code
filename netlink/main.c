/*
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

 */

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <net/if.h>
int main(void)
{
    struct {
        struct nlmsghdr hdr;
        struct ifaddrmsg msg;
    } req;
    struct sockaddr_nl addr;
    int sock[2];

    memset(&addr, 0, sizeof(addr));
    memset(&req, 0, sizeof(req));

    if ((sock[0] = socket(PF_NETLINK, SOCK_RAW, NETLINK_ROUTE)) == -1) {
        return -1;
    }

    addr.nl_family = AF_NETLINK;
    addr.nl_groups = RTMGRP_IPV6_IFADDR;// |RTMGRP_IPV6_IFADDR;
    if ((bind(sock[0], (struct sockaddr_in6 *)&addr, sizeof(addr))) == -1) {
        return -1;
    }

    //netlink_event.fd = sock[0];
    if ((sock[1] = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_ROUTE)) == -1) {
        return -1;
    }

    req.hdr.nlmsg_len = NLMSG_LENGTH(sizeof(struct ifaddrmsg));
    req.hdr.nlmsg_flags = NLM_F_REQUEST | NLM_F_ROOT;
    req.hdr.nlmsg_type = RTM_GETADDR;
    req.msg.ifa_family = AF_INET6;

    if ((send(sock[1], &req, req.hdr.nlmsg_len, 0)) == -1) {
        return -1;
    }

    struct nlmsghdr *nlh;
    char buffer[BUFSIZ];
    int msg_size;

    memset(&buffer, 0, sizeof(buffer));

    nlh = (struct nlmsghdr *)buffer;
    if ((msg_size = recv(sock[1], nlh, BUFSIZ, 0)) == -1) {
        return;
    }

    while (msg_size > sizeof(*nlh)) {
        int len = nlh->nlmsg_len;
        int req_len = len - sizeof(*nlh);

        if (req_len < 0 || len > msg_size) {
            return;
        }

        if (!NLMSG_OK(nlh, msg_size)) {
            return;
        }

        if (nlh->nlmsg_type == RTM_NEWADDR) {
            printf("new addr \n");
            struct ifaddrmsg *ifa = (struct ifaddrmsg *) NLMSG_DATA(nlh);
            struct rtattr *rth = IFA_RTA(ifa);
            int rtl = IFA_PAYLOAD(nlh);
            char if_name[IFNAMSIZ], if_addr[INET6_ADDRSTRLEN];
            char *c;
            struct in6_addr *in6p;

            memset(&if_name, 0, sizeof(if_name));
            memset(&if_addr, 0, sizeof(if_addr));

            while (rtl && RTA_OK(rth, rtl)) {
                printf("rth->rta_type %d \n", rth->rta_type);
                in6p = (struct in6_addr *)RTA_DATA(rth);
                if (rth->rta_type != IFA_LOCAL) {
                    printf("########NOT IFA_LOCAL ############\n");
                    rth = RTA_NEXT(rth, rtl);
                    continue;
                }
                printf("======IFA_LOCAL======\n");
                rth = RTA_NEXT(rth, rtl);                   
            }
        }   
        msg_size -= NLMSG_ALIGN(len);
        nlh = (struct nlmsghdr*)((char*)nlh + NLMSG_ALIGN(len));
    }
    return 0;
}
