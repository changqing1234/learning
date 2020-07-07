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
	
	cout<<"请输入你要输入的数据个数"<<endl;
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>s[i];
	} 
	
	
	int k = 0;
	cout<<"输出"<<endl; 
	output(s, n, k);
	
}
