#include<stdio.h>
#include<iostream>
using namespace std;

int sum(int R[], int n){
	if(n == 1)
		return R[0];
	
	return R[n-1] + sum(R, n-1);
	
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
	
	cout<<"��Ϊ"<<sum(R, n);
	
}
