#include <stdio.h>
#include <ctype.h>
#include <string.h>

int check_domain_name(const char *dn)
{
    int ret = -1;
    char *ptok = NULL;
    char *dncp = strdup(dn);
    char *tmp;
    int i = 0;

    if(dn[0] && dn[0] != '-' && strchr(dn, '.'))
    {
        ptok = strtok(dncp, ".");
        while(NULL != ptok)
        {
            printf("ptok %s\n", ptok);
            if(!ptok)
               goto out;

            for(i = 0; i < strlen(ptok); i++)
            {
                if(isalnum(*(ptok +i)) || '-' == *(ptok +i))
                    continue;
                else 
                    goto out;

            }
            if( i > 0 && *(ptok + i -1 ) == '-')
                goto out;

            ptok = strtok(NULL, ".");
        }

        ret = 0;
    }
out:
    free(dncp);

    return ret;
}

int main(int argc , char *argv[])
{
    if(argc < 2 ) 
    {
        printf("error ./a.out <domain.name>\n");
        return -1;
    }
    printf("return value : %s\n", !check_domain_name((const char*)argv[1]) ? "okay" : "no" );
    
    return 0;
}
    
