#include<stdio.h>
#include<stdlib.h>
void Bucket_Sort(int a[], int n)
{  
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[a[i]])++;
 
    for (i = 0, j = 0; i < n; i++)  
        for(; count[i] > 0; (count[i])--)
            a[j+1] = i;

}   

void printArray(int a[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    
    int n ,i;
    printf("Enter the size of array : \t");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%1000;
        printf("%d ",a[i]);
    }
    printf("\n");
    Bucket_Sort(a, n);
    printArray(a, n);
 
    return 0;
}
