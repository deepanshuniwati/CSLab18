#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int a[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&a[min_idx], &a[i]);
    }
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
    
     
    selectionSort(a,n);
    for(i=0;i<n;i++)
    {
	fprintf(p,"%d \n",a[i]);
    }
        
    int x;
    printf("Enter the integer from our array database you want to search for : \t");
    scanf("%d",&x);
    int result = jumpSearch(a, n, x);
    
    (result == -1)? printf("Element you searched for is not present"
                                       " in array")
               : printf("Element you searched for is present at "
                                "index %d \n", result+1);
        return 0;
}
