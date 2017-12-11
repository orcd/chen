/*22.【代码题】
父子进程通过信号通信，实现交替数数。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
pid_t pid;
void func_son()
{
    static int i =1;
    printf("son - %d\n",i);
    i+=2;
    sleep(2);
    kill(getppid(),SIGUSR2);

}
void func_dad()
{
    static int i =0;
    printf("dad - %d\n",i);
    i+=2;
    sleep(2);
    kill(pid,SIGUSR1);
}

int main()
{
    pid =fork();
    if (pid < 0)
    {
        printf("---fork error---\n");
    }
    else if(pid ==0)
    {
        printf("---this is son---\n");
        signal(SIGUSR1,func_son);
        //raise(3);
    }
    else
    {
        printf("---this is dad---\n");
        signal(SIGUSR2,func_dad);
        raise(SIGUSR2);
    }
    while(1);
    return 0;
}
