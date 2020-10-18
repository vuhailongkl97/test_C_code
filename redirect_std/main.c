#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    int out = open("out.log", O_RDONLY);
    int save_out = 0;

    if (-1 == out)
    {
        perror("opening cout.log");
        exit(EXIT_FAILURE);
    }

    save_out = dup(fileno(stdout));

    if (-1 == dup2(out, fileno(stdout)))
    {
        perror("cannot redirect stdout");
        exit(EXIT_FAILURE);
    }

    dup2(save_out, fileno(stdout));
    close(save_out);

    exit(EXIT_SUCCESS);
}
