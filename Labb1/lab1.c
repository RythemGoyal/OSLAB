#include<stdio.h>
#include<stdlib.h>
struct pro{
    int pid,etime;
    char pname[10];
}p[5];
int main(){
    FILE *fp;
    fp = fopen("lab1.txt","w");
    int n;
    if(fp==NULL){
        printf("File not found!");
    }else{
        printf("Successful in opening the file\n");
        printf("Enter the number of processes\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("Enter pid\n");
            scanf("%d",&p[i].pid);
            printf("Enter pname\n");
            scanf("%s",p[i].pname);
            printf("Enter etime\n");
            scanf("%d",&p[i].etime);
        }
        fprintf(fp,"PiD\t\tPName\t\tEtime\n");
        for(int i=0;i<n;i++){
            fprintf(fp,"%d\t\t%s\t\t%d\n",p[i].pid,p[i].pname,p[i].etime);
        }
        fclose(fp);
    }

    fp=fopen("lab1.txt","r");
    if(fp==NULL){
        printf("File not found!\n");
    }else{
        printf("File opened Successfully\n");
        char x[10],y[10];
        char z[10];
        int X,Z;
        fscanf(fp,"%s\t\t%s\t\t%s\n",x,y,z);
        printf("%s\t\t%s\t\t%s\n",x,y,z);
        while(fscanf(fp,"%d\t\t%s\t\t%d\n",&X,y,&Z)==3){
            printf("%d\t\t%s\t\t%d\n",X,y,Z);
        }
        fclose(fp);
    }

}