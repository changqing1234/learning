#include<stdio.h>
#include<iostream>
using namespace std;

//插入排序,从后往前进行比较，如果大于待比较的数就讲数据后移一位。 
void InsertSort(int s[], int n){
	int i, j;
	int temp;
	
	for(i=1; i<n; i++){
		
		temp = s[i];
		
		for(j=i-1; j>=0 && temp < s[j]; j--){
			s[j+1] = s[j];
		}
		
		s[j+1] =  temp;
	}
	
}

//折半插入排序，利用折半查找，找出待排序的数应该插入的位置。插入的位置就是high+1； 
void binary_insertSort(int s[], int n){
	int i, j, temp;
	int low, high, m;
	
	for(int i=1; i<n; i++){
		
		int temp = s[i];
		low = 0;
		high = i-1;
		
		while(low <= high){
			m = (low + high)/2;
			
			if(temp < s[m]){
				high = m-1;
			}else{
				low = m+1;

			}
		}
		
		for(int j=i-1; j>high; j--){
			s[j+1] = s[j];
		}
		
		s[high+1] =  temp;
		
	} 
} 

//希尔排序
void  g 

int main(void){
	
	int s[20];
	int n;
	
	cout<<"请输入你要插入的数据个数"<<endl;
	cin>>n;
	cout<<"请输入你要插入的数据"<<endl;
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	binary_insertSort(s, n);
	
	cout<<"排序后的数据如下："; 
	for(int i=0; i<5; i++){
		cout<<s[i]<<" ";
	} 
	
	cout<<endl;
	
} 
