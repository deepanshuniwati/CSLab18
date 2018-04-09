#include<stdio.h>
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
    
     
    insertionSort(a,n);
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
