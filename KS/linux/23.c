/*
 * 22.【代码题】
 编程实现多个生产者和多个消费者模型（条件变量）。（3个生产者，5个消费者）
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>


int num;
pthread_cond_t cond; //条件变量
pthread_mutex_t mutex;

void* customer()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(num==0)
        {
           pthread_cond_wait(&cond,&mutex);

        }
        else
        {
            num--;
        }
         pthread_mutex_unlock(&mutex);
        printf("customer -num:%d\n",num);
        sleep(rand()%3);
    }
}
void *producter()
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        num++;
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        printf("productor -num:%d\n",num);
        sleep(rand()%3);
    }
}

int main()
{
    int i =0;
    num =10;
    pthread_t tid[8];
    srand((unsigned int)time(NULL));
    int ret=pthread_cond_init(&cond,NULL);
    if (ret)
    {
        printf("条件变量失败");
        return 0;
    }
    ret=pthread_mutex_init(&mutex,NULL);
    if (ret)
    {
        printf("互斥锁失败");
        return 0;
    }
    for(;i<3;i++)
    {
        pthread_create(&(tid[i]),NULL,producter,NULL);
    }
    for(;i<8;i++)
    {
        pthread_create(&(tid[i]),NULL,customer,NULL);
    }

    for(i = 0; i < 3; i++) {                                    //回收线程资源
        pthread_join(tid[i], NULL);
    }
    for(; i < 8; i++) {
        pthread_join(tid[i], NULL);
    }

    //while(1);
    return 0;
}
