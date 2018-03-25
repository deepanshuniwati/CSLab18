#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int*xp, int *yp)
{
    int t = *xp;
    *xp = *yp;
    *yp = t;
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
    //First we generate 1000 integers and storethem in an array
        srand(time(NULL));
        
        
        int a[1000];
        int i;
        for(i=0;i<1000;i++)
        {
            a[i] = rand();
            printf("The %dth random integer is %d \n",i,a[i]);
            
        }
        int n = sizeof(a)/sizeof(a[0]);
    //Next we sort this array using Bubble sort
        int j;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                    swap(&a[j],&a[j+1]);
            }
            printf("%d\n",a[i]);
        }
    //Now we  call the search function for a specific value in our array.
        int x;
        printf("Enter the interger from our array database to search its index: \t");
        scanf("%d",&x);
        int result = binarySearch(a,0,n-1,x);
        (result == -1)? printf("Element you searched for is not present"
                                       " in array")
               : printf("Element you searched for is present at "
                                "index %d", result);
        return 0;
}
