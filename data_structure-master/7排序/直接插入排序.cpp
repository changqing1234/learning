#include<stdio.h>
#include<iostream>
using namespace std;

//��������,�Ӻ���ǰ���бȽϣ�������ڴ��Ƚϵ����ͽ����ݺ���һλ�� 
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

//�۰�������������۰���ң��ҳ����������Ӧ�ò����λ�á������λ�þ���high+1�� 
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

//ϣ������
void  g 

int main(void){
	
	int s[20];
	int n;
	
	cout<<"��������Ҫ��������ݸ���"<<endl;
	cin>>n;
	cout<<"��������Ҫ���������"<<endl;
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	binary_insertSort(s, n);
	
	cout<<"�������������£�"; 
	for(int i=0; i<5; i++){
		cout<<s[i]<<" ";
	} 
	
	cout<<endl;
	
} 
