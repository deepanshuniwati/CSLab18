#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void insertionSort(int a[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = a[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
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
    
     
    insertionSort(a,n);
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
