#include<stdio.h>
#include<iostream>
using namespace std;

//��ѡ������ ,ÿ�δ������������ҳ���С(���)������ 
void SelectSort(int s[], int n){
	int i, j, k;
	
	int temp;
	for(int i=0; i<n; i++){
		k=i;
		for(int j=i+1; j<n; j++){
			if(s[k] > s[j]){
				k = j;
			}
		}
		
		temp = s[k];
		s[k] =  s[i];
		s[i] =  temp;
	}
	
} 
int main(void){
	
	cout<<"��������Ҫ��������ݵĸ���"<<endl;
	int n;
	cin>>n;
	
	int s[30];
	cout<<"������Ҫ���������:"; 
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	SelectSort(s, n);
	
	cout<<"�������������£�"<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	}
	
	cout<<endl; 
	
} 
