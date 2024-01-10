#include<stdio.h>
#include<stdlib.h>
struct pro{
    char pname[5];
    int at,bt,wt,rt,ct,tat;
}p[4];
float awt,atat;

#define TIME_QUANT 6

void calculate(){
    int complete = 0;
    int currentTime = 0;
    while(complete<4){
        for(int i=0; i<4; i++){
            if(p[i].rt >0){
                int executeTime;
                if(p[i].rt >= TIME_QUANT){
                    executeTime = TIME_QUANT;
                }else{
                    executeTime = p[i].rt;
                }
                printf("Process %s executes from %d to", p[i].pname, currentTime);
                currentTime = currentTime + executeTime;
                p[i].rt = p[i].rt - executeTime;
                printf("%d\n", currentTime);
                if(p[i].rt == 0){
                    complete++;
                    p[i].ct = currentTime;
                }
            }
        }
    }
    for(int i=0; i<4; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].wt;
    }
}

void average(){
    for(int i=0; i<4; i++){
        awt = p[i].wt + awt;
        atat = atat + p[i].tat;
    }
}

void sort(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4-1-i; j++){
            if(p[j].ct > p[j+1].ct){
                struct pro temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
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
    printf("File openend\n");
    fprintf(fp2,"PName\t\tAT\t\tBT\t\tWT\t\tTAT\t\tCT\n");
    for(int i=0; i<4; i++){
        fscanf(fp1,"%s\t\t%d\t\t%d\n",p[i].pname,&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }
    calculate();
    average();
    sort();
    for(int i=0; i<4; i++){
        fprintf(fp2,"%s\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pname,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
    }
    printf("Average waiting time is : %f\n",awt);
    printf("Average turn around time is : %f\n",atat);
}