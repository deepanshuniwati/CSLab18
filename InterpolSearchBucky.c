#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void Bucket_Sort(int a[], int n) 
{
         int i, j;
         int count[n];
         for (i=0; i < n; i++) 
	{
	         count[i] = 0;
         }
         for (i=0; i < n; i++) 
	{
	         (count[a[i]])++;
         }
         for (i=0,j=0; i < n; i++) 
	{
 	        for (; count[i]>0;(count[i])--) 
		{         
			a[j++] = i;
         	}
         }
}
int iSearch(int a[], int x, int n)
{
    
    int lo = 0, hi = (n - 1);
	int pos=0;
    while (lo <= hi && x >= a[lo] && x <= a[hi])
    {
       pos = lo + (((double)(hi-lo)*(x-a[lo])/(a[hi]-a[lo])));
 
        
        if (a[pos] == x)
            return pos+1;
        if (a[pos] < x)
            lo = pos + 1;
 
        else
            hi = pos - 1;
    }
    return -1;
}
int main()
{
    //We will be using array to store random integers.
    int a[1000],i;
    FILE *f,*p;
    f=fopen("meetme.txt","w");
    p=fopen("dateme.txt","w");
    int n = sizeof(a)/sizeof(a[0]);
    //We will seed at TIME=NULL
    srand(time(NULL));
    
    //Loop to assign random integers to indexes of array.
    for(i=0;i<1000;i++)
    {
        a[i] = rand()%1000;
        
        fprintf(f,"%d \n",a[i]);
    }
    
     
    Bucket_Sort(a,n);
    for(i=0;i<n;i++)
    {
	fprintf(p,"%d \n",a[i]);
    }
        
    int x;
    printf("Enter the integer from our array database you want to search for : \t");
    scanf("%d",&x);
    int result = iSearch(a, x,n);
    
    (result == -1)? printf("Element you searched for is not present"
                                       " in array")
               : printf("Element you searched for is present at "
                                "index %d \n", result);
        return 0;
}
