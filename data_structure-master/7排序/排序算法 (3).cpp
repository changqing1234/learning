#include<iostream>
using namespace std;
int main()
{
	
	int i, j, temp;
	
	
	
	int get;
	 int n = 10; 
	cout<<"ÇëÊäÈëÊı"<<endl; 
	int a[10] = {1, 2, 3, 5 , 6 , 54 ,6, 7 , 8, 9}	;
  
	
	for(i = 1; i < n; i++)
	{
		get = a[i];
		
		for(j = i-1; j >= 0 && a[j] > get; j--)
		{
			a[j+1] = a[j];
		}
		
		a[j+1] = get;
	 } 
	 
	 for(i = 0; i < n; i++)
	 {
	 	cout << a[i] << " ";
	 }
}
	
