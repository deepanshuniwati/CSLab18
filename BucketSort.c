This program works for 1000 integers only..
Above 1000 it givves segmentation fault because it requires more memory space and while defining array we just made clear that the size is 1000.
But it needs more than 1000 memory spaces to work on more than 1000 integers.


#include<stdio.h>
#include<stdlib.h>
void Bucket_Sort(int array[], int n) 
{
         int i, j;
         int count[n];
         for (i=0; i < n; i++) 
         {
           count[i] = 0;
         }
         for (i=0; i < n; i++) 
         {
          (count[array[i]])++;
         }
         for (i=0,j=0; i < n; i++) 
         {
          for (; count[i]>0;(count[i])--) 
          {
            array[j++] = i;
          }
         }
}
         
int main() 
{
         int array[10000];
         int num=1000;
         int i;
	       FILE *f,*p;
	       f = fopen("catomic.txt","w");
	       p = fopen("titanic.txt","w");
         printf("Taking 1000 Random Numbers in range(1000) as input: \n");
         for (i = 0; i < num; i++ ) 
         {
          array[i] = rand()%1000;
         }
         
         for (i = 0;i < num;i++) 
         {
          fprintf(f,"%d ", array[i]);
         }
         
         Bucket_Sort(array, num);
         for (i = 0;i < num;i++) 
         {
          fprintf(p,"%d ", array[i]);
         }
         printf("\n");
         return 0;
}
  
