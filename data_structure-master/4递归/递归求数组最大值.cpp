#include<stdio.h>
#include<iostream>
using namespace std;

int max(int R[], int n){
	
	if(n == 1)
		return R[0];
	
	if(R[n-1] >= max(R, n-1))
		return R[n-1];
	else
		return max(R, n-1);
	
}

int main(void){
	int n;
	cout<<"���������鳤��"<<endl;
	cin>>n;
	
	int R[n];
	cout<<"����������"<<endl;
	 
	for(int i=0; i<n; i++){
		cin>>R[i];
	}
	
	cout<<"���ֵΪ"<<max(R, n);
	
}
