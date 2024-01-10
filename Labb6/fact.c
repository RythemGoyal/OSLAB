#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(int argc ,char *argv[]){
    pid_t pid;
    if(argc != 2){
        printf("Arguments missing\n");
        exit(0);
    }
    int x = atoi(argv[1]);
    if(x < 0){
        printf("Negative number error\n");
        exit(0);
    }
    pid = fork();

    if(pid < 0){
        printf("Failed to create a child process\n");
    }
    else if(pid == 0){
        printf("Inside child process\n");
        int n = atoi(argv[1]);
        int ans = 0, k = 2;
        int arr[n], sum[n];
        arr[0] = 1;
        for(int i=1; i<n; i++){
            arr[i] = arr[i-1] * k;
            k++; 
        }
        for(int j=0; j<n; j++){
            sum[j] = 0;
            
            for(int i=0; i<=j; i++){
                sum[j] = sum[j] + arr[i];
                printf("%d\t",arr[i]);
            }
            printf("\n");
        }
        for(int i=0; i<n; i++){
            printf("%d\t", sum[i]);
        }
    }
    else{
        wait(NULL);
        printf("Child process executed!\n");
    }
}