#include<stdio.h>
#include<iostream>
using namespace std;

//�۰���ҡ����ֲ��� 
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
	cout<<"��������Ҫ��������ݸ���: "<<endl; 
	int n;
	int value;
	
	cin>>n;
	
	int s[n];
	
	cout<<"������"<<n<<"������"<<endl; 
	for(int i=0; i<n; i++){
		cin>>s[i];
	} 
	
	cout<<"�������£�"<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	} 
	cout<<endl;
	
	cout<<"��������Ҫ���ҵ�����: ";
	cin>>value;
	
	cout<<"���ҵ��������£�"<<endl; 
	int a = Bsearch(s, 0, n-1, value);
	cout<<s[a];
} 
