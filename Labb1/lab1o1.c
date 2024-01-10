#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pro
{
    char fname[20],lname[20];
    int age;
}p[5];

int main(){
    FILE *fp;
    fp = fopen("lab1o1.txt","w");
    if(fp==NULL){
        printf("File not found!");
        exit(0);
    }
    printf("File opened successfully\n");
    int n;
    printf("Enter the number of people\n");
    scanf("%d",&n);
    fprintf(fp,"FName\t\tLName\t\tAge\n");
    for(int i=0;i<n;i++){
        printf("Enter first name\n");
        scanf("%s",p[i].fname);
        printf("Enter last name\n");
        scanf("%s",p[i].lname);
        printf("Enter age\n");
        scanf("%d",&p[i].age);
        fprintf(fp,"%s\t\t%s\t\t%d\n",p[i].fname,p[i].lname,p[i].age);
    }
    fclose(fp);

    fp=fopen("lab1o1.txt","r");
    if(fp==NULL){
        printf("File not found\n");
        exit(0);
    }
    char f[20],l[20],a[20];
    int k;
    printf("Names of people with age>=40\n");
    fscanf(fp,"%s\t\t%s\t\t%s\n",f,l,a);
    printf("%s\t\t%s\t\t\n",f,l);
    struct pro P[n];
    int i=0;
    while(fscanf(fp,"%s\t\t%s\t\t%d\n",f,l,&k)==3){
        if(k>=40){
            printf("%s\t\t%s\n",f,l);
        }
        strcpy(P[i].fname,f);
        strcpy(P[i].lname,l);
        P[i].age = k;
    }
    fclose(fp);
}