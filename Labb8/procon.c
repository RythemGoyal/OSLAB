#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

pthread_t tid[10],tic[10];
pthread_mutex_t mutex;
sem_t full,empty;
int buffer[10];
int counter;

int readd();
void writee();

void initialize(){
    counter = 0;
    sem_init(&full,0,0);
    sem_init(&empty,0,10);
    pthread_mutex_init(&mutex,NULL);
}

void *producer(void *prod){
    int item;
    do{
        item = rand() % 10;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        writee(item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1000);
    }while(1);
    
}

void writee(int x){
    if(counter >= 9){
        printf("No more space left\n");
    }
    else{
        buffer[counter++] = x;
        printf("Producer added : %d \n", x);
    }
}

void *consumer(void *cons){
    int item;
    do{
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = readd();
        printf("Consumer consumed : %d \n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(1000);
    }while(1);
    
}

int readd(){
    if(counter <= 0){
        printf("No item to return\n");
    }
    else{
        return buffer[--counter];
    }
}

void main(){
    int n1,n2;
    initialize();
    printf("Enter number of producer processes\n");
    scanf("%d",&n1);
    printf("Enter number of consumer processes\n");
    scanf("%d",&n2);
    for(int i=0; i<n1; i++){
        pthread_create(&tid[i],NULL,producer,NULL);
    }
    for(int i=0; i<n2; i++){
        pthread_create(&tic[i],NULL,consumer,NULL);
    }
    for(int i=0; i<n1; i++){
        pthread_join(&tid[i],NULL);
    }
    for(int i=0; i<n2; i++){
        pthread_join(&tic[i],NULL);
    }
}