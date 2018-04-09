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
int binarySearch(int a[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
 
        // Check if x is present at mid
        if (a[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (a[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
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
    int result = binarySearch(a,0, n-1, x);
    
    (result == -1)? printf("Element you searched for is not present"
                                       " in array")
               : printf("Element you searched for is present at "
                                "index %d \n", result+1);
        return 0;
}
