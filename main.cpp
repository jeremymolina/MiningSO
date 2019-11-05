#include <iostream>
#include <sys/resource.h>
#include "mem.h"
#include "cpu.h"
#include <unistd.h>
#include <sys/wait.h>
#define ERROR -1

static int collectMemData() {
    return getMemUsage();
}


static int collectCpuData() {
    return getCpuUsage();
}

static int collectNetData() {
    return 1;
}

static int collectDiskData() {
    return 1;
}

int main()
{

    printf("> Initializing parent [%d] \n\n", getpid());

    for(int i=0;i<4;i++)
    {
        if(fork() == 0)
        {
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());


            switch (i) {
                case 0:

                    printf(">> Running Child task [%d] PID=%ld  \n ", i, getpid());
                    printf("<<< childMem: %u KB, VS: %u KB.\n", collectMemData());
                    break;

                case 1:
                    printf(">> Running Child task [%d] PID=%ld  \n ", i, getpid());
                    printf("<<< childCpu: %u B.\n", collectCpuData());
                    break;

                case 2:
                    printf(">> Running Child task [%d] PID=%ld  \n ", i, getpid());
                    printf("<<< childNet: %u.\n", collectNetData());
                    break;

                case 3:
                    printf(">> Running Child task [%d] PID=%ld  \n ", i, getpid());
                    printf("<<< childDisk: %u.\n", collectDiskData());
                    break;

            }

            printf("<< Closing Child task [%d] \n\n", getpid());

            exit(EXIT_SUCCESS);


        }

    }

    for(int i=0;i<4;i++)
        wait(0);

    printf("< Finalizing parent [%d] \n\n", getpid());
    exit(EXIT_SUCCESS);

}