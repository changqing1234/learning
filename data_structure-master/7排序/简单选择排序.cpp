#include<stdio.h>
#include<iostream>
using namespace std;

//简单选择排序 ,每次从无序序列中找出最小(最大)的数据 
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
	
	cout<<"请输入你要输入的数据的个数"<<endl;
	int n;
	cin>>n;
	
	int s[30];
	cout<<"请输入要输入的数据:"; 
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	SelectSort(s, n);
	
	cout<<"排序后的数据如下："<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	}
	
	cout<<endl; 
	
} 
