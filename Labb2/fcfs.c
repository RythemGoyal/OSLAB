#include<stdio.h>
#include<stdlib.h>
struct pro{
    char pname[5];
    int at,bt,wt,tat,st,ct,id;
    
}p[5];
float atat,awt;

void start_time(){
    int i = 0;
    p[i].st = 0;
    for(i=1; i<5; i++){
        p[i].st = p[i-1].st + p[i-1].bt;
    }
}

void completion_time(){
    for(int i=0; i<5; i++){
        p[i].ct = p[i].bt + p[i].st;
    }
}

void turnaround_time(){
    for(int i=0; i<5; i++){
        p[i].tat = p[i].ct - p[i].at;
        atat = atat + p[i].tat;
    }
}

void waiting_time(){
    for(int i=0; i<5; i++){
        p[i].wt = p[i].tat - p[i].bt;
        awt = awt + p[i].wt;
    }
}

int main(){
    FILE *fp1,*fp2;
    fp1 = fopen("file.txt","r");
    fp2 = fopen("output.txt","w");

    if(fp1 == NULL){
        printf("File not found!");
        exit(0);
    }
    fprintf(fp2,"PiD\t\tPName\t\tBT\t\tAT\t\tST\t\tWT\t\tTAT\t\tCT\n");
    for(int i=0; i<5; i++){
        fscanf(fp1,"%d\t\t%s\t\t%d\t\t%d\n",&p[i].id,p[i].pname,&p[i].bt,&p[i].at);
    }

    start_time();
    completion_time();
    turnaround_time();
    waiting_time();
    for(int i=0; i<5; i++){ 
        fprintf(fp2,"%d\t\t%s\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].pname,p[i].bt,p[i].at,p[i].st,p[i].wt,p[i].tat,p[i].ct);
    }
    printf("Average waiting time = %f\n",(awt/5));
    printf("Average turn around time = %f\n",(atat/5));
}