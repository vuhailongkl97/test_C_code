	#include <stdio.h>
#include <string.h>


typedef struct _serv2port{
        char name[10];
        char port[10];
}serv2port_t;

const serv2port_t serv2port[] =
{
     {"WEB",    "80 443"},
     {"TELNET", "24"},
     {"SSH",    "22"},
     {"SNMP",   "161"},
     {"TELNET", "24"},
     {"FTP",    "21"},
     {"TFTP",   "69"},
     {"CWMP",    "9091"},
     {"NULL" ,     "0"},
};

const char* server2port(const char *input)
{
     int i = 0;
     while ( 0 != strcmp(serv2port[i].name, "NULL"))
     {
	     if (0 == strcmp(input, serv2port[i].name))
		     return serv2port[i].port;
	     i++;
     }
     return "";
}

int service2port_str(const char *input, char *output)
{
    if( NULL == output)
		return -1;
    char* token = strtok(input, ",");
    const char *tmp_port;

    while (token != NULL) {
        tmp_port = server2port(token); 
	printf("tmp port %s\n", tmp_port);
	strcat(output, tmp_port);
        token = strtok(NULL, ",");
	if (token != NULL)
	    strcat(output, " ");
    }
    return 0;

}
int check_service_in_config(const char *service, const char *input)
{
    char *tmp =server2port(service); 

    if (0 != strcmp(tmp,"") && (NULL != strstr(input, tmp)))
	    return 1;

    return 0;
}

#include <netdb.h>


//struct servent *getservbyname(const char *name, const char *proto);
int main(int argc , char *argv[])
{
    char str[] = "TFTP,SSH,WEB";
    char output[100] = {0};
    struct servent *serven = NULL;

    if ( argc <2 )
    {
	    puts("argument incorrectly");
	    return 0;
    }
    serven = malloc(sizeof(struct servent));
    serven = getservbyname(argv[1], "tcp");;

    if (serven != NULL)
    {
	    printf("services %s with port %d\n", serven->s_name, serven->s_port);
    }


#if 0
    bzero(output, sizeof(output));
    service2port_str(str,output);

    printf("output is \"%s\" is in buf \n", output );

    printf("output have ssh %d\n" ,check_service_in_config("SSH", output));
    
#endif

    return 0;
}

