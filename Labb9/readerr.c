#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t readerss[10],writerss[10];
int readercount = 0;
pthread_mutex_t mutex;
sem_t wrt;

void initialize(){
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);
}

void *writer(void *id){
    long tid = (long)id;
    while(1){
        sem_wait(&wrt);
        printf("Writing is done of threadId %ld\n",tid);
        sem_post(&wrt);
        sleep(1000);
    }
}

void *reader(void *id){
    long tid = (long)id;
    while(1){
        pthread_mutex_lock(&mutex);
        readercount++;
        if(readercount == 1)
            sem_wait(&wrt);
        pthread_mutex_unlock(&mutex);
        printf("Reader is reading of threadId : %ld\n",tid);
        pthread_mutex_lock(&mutex);
        readercount--;
        if(readercount == 0)
            sem_post(&wrt);
        pthread_mutex_unlock(&mutex);
        sleep(1000);
    }
}

int main(){
    int n1,n2;
    initialize();
    printf("Enter number of readers\n");
    scanf("%d",&n1);
    printf("Enter number of writers\n");
    scanf("%d",&n2);
    for(int i=0; i<n1; i++){
        pthread_create(&readerss[i],NULL,reader,(void *)&readerss[i]);
    }
    for(int i=0; i<n2; i++){
        pthread_create(&writerss[i],NULL,writer,(void *)&writerss[i]);
    }
    for(int i=0; i<n1; i++){
        pthread_join(&readerss[i],NULL);
    }
    for(int i=0; i<n2; i++){
        pthread_join(&writerss[i],NULL);
    }
}

//gcc main.c -o main
//gcc main 5
// gcc main.c -lpthread