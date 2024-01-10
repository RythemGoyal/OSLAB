#include<stdio.h>
#include<stdlib.h>

struct pro{
    char pname[5];
    int at,bt,ct,rt,wt,tat;
}p[5];

float awt, atat;

void calculate(){
    int completed = 0;
    int currentTime = 0;
    while(completed < 5){
        int shortest = -1;
        int shortestTime = 9999;
        for(int i=0; i<5; i++){
            if(p[i].at <= currentTime && p[i].rt < shortestTime && p[i].rt >0){
                shortest = i;
                shortestTime = p[i].rt;
            }
        }

        if(shortest == -1){
            currentTime++;
            continue;
        }
        p[shortest].rt--;

        if(p[shortest].rt == 0){
            p[shortest].ct = currentTime + 1;
            completed++;
        }
        currentTime++;
    }

    for(int i=0; i<5; i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void average(){
    for(int i=0; i<5; i++){
        awt = awt + p[i].wt;
        atat = atat + p[i].tat;
    }
}

void bubblesort(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5-1-i; j++){
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
        printf("File not found\n");
        exit(0);
    }
    fprintf(fp2,"PName\t\tAT\t\tBT\t\tWT\t\tTAT\t\tCT\n");
    for(int i=0; i<5; i++){
        fscanf(fp1,"%s\t\t%d\t\t%d\n",p[i].pname,&p[i].bt,&p[i].at);
        p[i].rt = p[i].bt;
    }

    calculate();
    average();
    bubblesort();

    for(int i=0; i<5; i++){
        fprintf(fp2,"%s\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pname,p[i].at,p[i].bt,p[i].wt,p[i].tat,p[i].ct);
    }

    printf("Average Waiting time : %f\n",(awt/5));
    printf("Average Turn Around Time : %f\n",(atat/5));
    
}