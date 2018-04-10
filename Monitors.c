#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5

#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+1)%N
#define RIGHT (ph_num+1)%N



struct  monitor {
int state[N];
};
sem_t S[N],mutex;

struct monitor m;
int phil_num[N]={0,1,2,3,4};
void * philospher(void *num);
void take_fork(int);
void put_fork(int);
void test(int);
void initailise()
{
    int i;
    for(i=0;i<N;i++)
    {
        m.state[i]=0;
    }
}
int main()
{
	int i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    initailise();
    for(i=0;i<N;i++)
        sem_init(&S[i],0,0);
    printf("Creating Threads\n");
    for(i=0;i<N;i++)
    {
    	pthread_create(&thread_id[i],NULL,philospher,&phil_num[i]);
         printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++)
    {
    	pthread_join(thread_id[i],NULL);
    }


}

void *philospher(void *num)
{
	int *phil =num;
	sleep(1);
	take_fork(*phil);
	sleep(0);//Eating
	put_fork(*phil);
}


void take_fork(int phil)
{
	sem_wait(&mutex);
	m.state[phil]=HUNGRY;
	printf("Philosopher %d is Hungry\n",phil+1);
	test(phil);
	sem_post(&mutex);
	// if(m.state[phil]!=EATING)
	sem_wait(&S[phil]);
}



void test(int ph_num)
{
	if(m.state[ph_num] == HUNGRY && m.state[LEFT] != EATING && m.state[RIGHT] != EATING)
	{
		m.state[ph_num] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n",ph_num+1,LEFT+1,ph_num+1);
        printf("Philosopher %d is Eating\n",ph_num+1);
        sem_post(&S[ph_num]);
	}
}


void put_fork(int ph_num)
{
    sem_wait(&mutex);
    m.state[ph_num] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n",ph_num+1,LEFT+1,ph_num+1);
    printf("Philosopher %d is thinking\n",ph_num+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}
