//First code had Binary Search and Bubble Sort.

//This code uses Jump Search and Bubble Sort.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int*xp, int *yp)
{
    int t = *xp;
    *xp = *yp;
    *yp = t;
}
//Searching using Jump Search.
int min(int a, int b) {
	return a < b ? a : b;
}

int jumpSearch(int a[], int n, int x) {
    int jump = (int) sqrt(n);
    int left = 0;
    int right = 0;

    while (left < n && a[left] <= x) {
        right = min(n - 1, left + jump);

        if (a[left] <= x && a[right] >= x) {
            break;
        }

        left += jump;
    }

    if (left >= n || a[left] > x) {
        return -1;
    }

    right = min(n - 1, right);

	int i;

    for (i = left; i <= right && a[i] <= x; ++i) {
        if (a[i] == x) {
            return i;
        }
    }

    return -1;
}

 
int main()
{
    //We will be using array to store random integers.
    int a[1000],i;
    int n = sizeof(a)/sizeof(a[0]);
    //We will seed at TIME=NULL
    srand(time(NULL));
    
    //Loop to assign random integers to indexes of array.
    for(i=0;i<1000;i++)
    {
        a[i] = rand();
        
        printf("The element at %dth index is %d.\n",i,a[i]);
    }
    
     
    //Next we sort this array using Bubble sort
        int j;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                    swap(&a[j],&a[j+1]);
            }
            printf("The sorted element at %dth index is %d \n",i,a[i]);
        }
        
    int x;
    printf("Enter the integer from our array database you want to search for : \t");
    scanf("%d",&x);
    int result = jumpSearch(a, n, x);
    
    (result == -1)? printf("Element you searched for is not present"
                                       " in array")
               : printf("Element you searched for is present at "
                                "index %d", result);
        return 0;
}

