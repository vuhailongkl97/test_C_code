#include <stdio.h>
#include <syslog.h>


int main(void)
{
    openlog("my program", LOG_CONS | LOG_PID | LOG_PERROR, LOG_SYSLOG);
    syslog(LOG_ERR, "TEST from LONG%d12", 97);
    closelog();
    return 0;
}

