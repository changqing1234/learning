#include<iostream>
using namespace std;
int main(void)
{

	
	int i,j, temp;
	
/*	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}
*/ 
int a[10] = {1, 2, 3, 5 , 5 , 54 ,6, 7 , 8, 9}	;
int n =10; 
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[j] < a[i])
			{
				temp = a[i];
				a[i]  = a[j];
				a[j]  = temp;
			}
			
				
	   }
	}
	
	for(i = 0; i < n; i++)
	{
		cout << a[i] <<" ";
	}
}
