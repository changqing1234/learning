#include<stdio.h>
#include<iostream>
using namespace std;

//�ݹ���׳� 
int get(int n){
	
	if(n > 0){
		int k = get(--n);
		cout<<n<<"�Ľ׳�Ϊ"<<k<<endl;
		return (n+1) * k;
		
		
	}else{
		return 1;
	}
	
}

int main(void){
	int n;
	cout<<"������׳���"<<endl;
	cin>>n;
	
	cout<<n<<"�Ľ׳�Ϊ��"<<get(n)<<endl;
	 
	
}
