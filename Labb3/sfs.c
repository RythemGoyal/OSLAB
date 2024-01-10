#include<stdio.h>
#include<stdlib.h>

struct pro{
    char pname[5];
    int at,bt,wt,tat,ct,exe;
}p[5];
float awt,atat;
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
void calculate(){
    int currrentTime = 0;
    int totalExecuted = 0;
    while(totalExecuted < 5){
        int shortest = -1;
        int shortestBurst = 9999;
        for(int i=0; i<5; i++){
            if(p[i].at <= currrentTime && p[i].exe == 0 && p[i].bt <= shortestBurst){
                shortest = i;
                shortestBurst = p[i].bt;
            }
        }
        if(shortest==-1){
            currrentTime++;
            continue;
        }

        p[shortest].ct = p[shortest].bt + currrentTime;
        p[shortest].tat = p[shortest].ct - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;
        p[shortest].exe = 1;
        totalExecuted++;
        currrentTime = p[shortest].ct;

    }
}

void average(){
    for(int i=0; i<5; i++){
        awt = awt + p[i].wt;
        atat = atat + p[i].tat;
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

    fprintf(fp2,"PName\t\tBT\t\tAT\t\tWT\t\tTAT\t\tCT\n");
    for(int i=0; i<5; i++){
        fscanf(fp1,"%s\t\t%d\t\t%d\n",p[i].pname,&p[i].bt,&p[i].at);
        p[i].exe=0;
    }

    calculate();
    bubblesort();
    average();

    for(int i=0; i<5; i++){
        fprintf(fp2,"%s\t\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pname,p[i].bt,p[i].at,p[i].wt,p[i].tat,p[i].ct);
    }
    printf("Average Waiting time : %f\n",(awt/5));
    printf("Average Turn around time : %f\n",(atat)/5);

    printf("\nGANTT CHART\n");
    for(int i=0;i<5;i++){
        printf("|---%s---|",p[i].pname);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        printf("|   %d    |",p[i].ct);
    }
}
