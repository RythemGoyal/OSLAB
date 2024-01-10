#include<stdio.h>

int n,m,i,j,k;
int alloc[5][3] = {{0,1,0},
                    {2,0,0},
                    {3,0,2},
                    {2,1,1},
                    {0,0,2}};

int max[5][3] ={{7,5,3},
                {3,2,2},
                {9,0,2},
                {2,2,2},
                {4,3,3}};

int avail[3] = {3,3,2};

int f[5],ans[5],ind = 0;

void initialize(){
    n = 5; 
    m = 3;

    for(i=0; i<n; i++){
        f[i] = 0;
    }
}

void safeSequence(){
    int need[n][m];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(k=0; k<5; k++){
        for(i=0; i<n; i++){
            if(f[i] == 0){
                int flag = 0;
                for(j=0; j<m; j++){
                    if(need[i][j]>avail[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    ans[ind++] = i;
                    for(j=0; j<m; j++){
                        avail[j] = avail[j] + alloc[i][j];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int flag = 1;
    for(int i=0; i<n; i++){
        if(f[i] == 0){
            flag = 0;
            printf("The following system is unsafe\n");
        }
    }
    if(flag == 1){
        printf("The following is the safe sequence : \n");
        for(i=0; i<n-1; i++){
            printf("P%d->",ans[i]);
        }
        printf("P%d",ans[n-1]);
    }
}
int main(){
    initialize();
    safeSequence();
    return 0;
}