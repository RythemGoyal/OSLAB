#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define max 20
int current = 1;
int is_even = 1;
int evenn = 2, oddd = 1;

void even(){
    while(current <= max){
            printf("Even : %d \n",evenn);
            current++;
            evenn = evenn+2;
    }
}

void odd(){

    while(current <= max){
            printf("Odd  : %d \n",oddd);
            current++;
            oddd = oddd + 2;
    }
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,even,NULL);
    pthread_create(&t2,NULL,odd,NULL);

    pthread_join(&t1,NULL);
    pthread_join(&t2,NULL);
    return 0;
}