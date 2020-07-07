#include<iostream>
using namespace std;
int main(void)
{
	int a[] = {1, 2, 3, 23, 23, 34, 56, 56, 67, 98};
	int n;
	n = sizeof(a) / sizeof(int);
	
	int middle, left, right, biaoji;
	biaoji = 0;
	left = 0;
	right = n-1;
	
	int x;
	cin >>x;
	
	while(left <= right)
	{ 
	   middle = left + right;
	   if(x == a[middle])
	   { 
	      biaoji = 1;
	      break;
	   }
	    
	      
         if(a[middle] < x)
         {
         	left = middle + 1;
		 }
		 
		 else
		    right = middle -1;
	}
	
	if(biaoji == 1)
	{ 
		cout<<"所找的数在"<<"第"<<middle+1<<"位"<<endl; 
			
	}
	
	
     
}
