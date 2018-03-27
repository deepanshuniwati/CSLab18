#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int min(int f,int g)
{
	int m;
	if(f>g)
	m=g;
	else
	m=f;
	return m;
}

int jumpsearch(int arr[],int x,int n)
{
	int step = sqrt(n);
	int prev=0;
	while(arr[min(step,n)-1]<x)
	{
		prev=step;
		step += sqrt(n);
		if(prev >=n)
		return -1;
	}
	while(arr[prev]<x)
	{
		prev++;
		if(prev== min(step,n))
		{
			return -1;
		}
	}
	if(arr[prev]==x)
	return prev+1;
	return-1;
}
int iSearch(int arr[], int x, int n)
{
    
    int lo = 0, hi = (n - 1);
	int pos=0;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
       pos = lo + (((double)(hi-lo)*(x-arr[lo])/(arr[hi]-arr[lo])));
 
        
        if (arr[pos] == x)
            return pos+1;
        if (arr[pos] < x)
            lo = pos + 1;
 
        else
            hi = pos - 1;
    }
    return -1;
}

int main()
{
	int a[1000];
	int i,m,l; 
	int c=1000;
	int s=10;
	srand(121);
	
	for(i=0;i<10;i++)
	{
		a[i] = rand()%1000+c;
		c=c+1000;
		printf("%d\n",a[i]);
	}
	printf("ENTER THE NUMBER TO BE SEARCHED:\n");
	scanf("%d",&m);
	int k;
	k=iSearch(a,m,s);
	l=jumpsearch(a,m,s);
	printf("%d\n",k);
	printf("%d\n",l);
}
