#include<stdio.h>
#include<iostream>
using namespace std;

//折半查找、二分查找 
int Bsearch(int R[], int low, int high, int k){
	int mid;
	while(low <= high){
		mid = (low+high)/2;
		
		if(R[mid] == k){
			return mid;
			
		}else if(R[mid] > k){
			high = mid-1;
			
		}else{
			low = mid+1;
		}
	}
	
	return 0;
	
}

int main(void){
	cout<<"请输入你要输入的数据个数: "<<endl; 
	int n;
	int value;
	
	cin>>n;
	
	int s[n];
	
	cout<<"请输入"<<n<<"个数据"<<endl; 
	for(int i=0; i<n; i++){
		cin>>s[i];
	} 
	
	cout<<"数据如下："<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	} 
	cout<<endl;
	
	cout<<"请输入你要查找的数据: ";
	cin>>value;
	
	cout<<"查找的数据如下："<<endl; 
	int a = Bsearch(s, 0, n-1, value);
	cout<<s[a];
} 
