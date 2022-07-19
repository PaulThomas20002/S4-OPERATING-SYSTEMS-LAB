#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
void *fun1();

void *fun2();
int shared=1;
sem_t s;
int main()
{
sem_init(&s,0,1);
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun1, NULL);
pthread_create(&thread2, NULL, fun2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);
printf("Final value of shared is %d\n",shared); }
void *fun1()
{
int x;
sem_wait(&s);
x=shared;
printf("Thread1 reads the value as %d\n",x);
x++;
printf("Local updation by Thread1: %d\n",x);
sleep(1);
shared=x;
printf("Value of shared variable updated by Thread1 is: %d\n",shared);
sem_post(&s);
return 0;
}

void *fun2()

{
int y;
sem_wait(&s);
y=shared;
printf("Thread2 reads the value as %d\n",y);
y--;
printf("Local updation by Thread2: %d\n",y);
sleep(1);
shared=y;
printf("Value of shared variable updated by Thread2 is: %d\n",shared);
sem_post(&s);
return 0;
}
