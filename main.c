#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y) ((x)<(y) ? -1 : (x)==(y) ? 0 : 1)

void sort(int [],int); //selection and sort//
int binarysearch(int [], int, int ,int);

int main(void)
{
    int i,n;
    int list[MAX_SIZE];
    printf("enter a number of the number lists:");
    scanf("%d",&n);
    if( n <= 1 || n>MAX_SIZE){
        fprintf(stderr,"Improper value!");
        exit(1);
    }

    for(i=0;i<n;i++){
        list[i] = rand() % 1000;
        printf("%d ",list[i]);
    }

    sort(list,n);
    printf("\nSorted array:\n");
    for(i = 0 ; i < n ; i++)
        printf("%d ",list[i]);
    printf("\n");

    int num,search,searchnum;
    printf("enter a number, you want to search:");
    scanf("%d",&searchnum);

    search = binarysearch(list,searchnum,0,n-1);

    if(search<0)
        printf("not found!");
    else
        printf("%d is in pos(%d)\n",searchnum,search+1);


    return 0;
}


void sort(int list[], int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(list[j]<list[min])
                min=j;
        }
        SWAP(list[i],list[min],temp);
    }
}

int binarysearch(int list[], int searchnum, int left, int right){
    int middle;
    while(left<=right){
        middle = (right + left)/2;
        switch(COMPARE(list[middle],searchnum)){
            case -1: left = middle + 1;
                break;
            case 0: return middle;
            case 1: right = middle - 1;
        }
    }
    return -1;
}
