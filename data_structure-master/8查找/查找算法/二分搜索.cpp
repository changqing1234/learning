#include<stdio.h>

int search(int a[], int x, int low, int high)
{
	if(low > high)
	  return -1;
	else
	   {
	   	 int mid = (low + high) / 2;
	   	   if(x == a[mid])
	   	      return mid;
	   	      
	   	   if(x < a[mid])
	   	      return  search(a, x, low, mid-1);
	   	   else
	   	      return search(a, x, mid+1, high);
	   }
}

int main(void)
{
	int n, i, j, a, b;
	int biaoji;
	
	scanf("%d", &n);
	
     int s[n];
	 for(i = 0; i < n; i++)
	 {
	 	scanf("%d", &s[i]);
	 }
	
	scanf("%d", &a);
	
	while(a--)
	{
		scanf("%d", &b);
	     biaoji = search(s, b,  0, n-1);
	     
	     if(biaoji != -1)
	       printf("%d\n", biaoji);
	    else
	      printf("Not found!\n");
	}
	
	return 0;
	
 } 
