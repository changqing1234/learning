#include<stdio.h>
#include<iostream>
using namespace std; 

void output(int s[], int n, int k){
	
	if(k < n){
			output(s, n, ++k);
			cout<<s[k-1]<<" ";
	}else{
		return ;	 
	}

}

int main(void){
	int s[40];
	
	cout<<"��������Ҫ��������ݸ���"<<endl;
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>s[i];
	} 
	
	
	int k = 0;
	cout<<"���"<<endl; 
	output(s, n, k);
	
}
