#include<iostream>
using namespace std;
int main()
{
	int n;
	int i, j, temp;
	
	cin>>n;
	int a[n];
	
   for(i=0; i < n; i++)
   {
   	 cin>>a[i];
   
   }
	for(i = 1; i < n; i++)
	{
	 for(j=0; j < i; j++)
	 {
	 	if(a[j] > a[i])
	 	{
			 temp = a[j];
		 	 a[j] = a[i];
		 	 a[i] = temp;
		 }
	 	 
	 	
	 }
	}
	
	for(i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
 } 
