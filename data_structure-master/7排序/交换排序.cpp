#include<stdio.h>
#include<iostream>
using namespace std;

//ð������ 
void BubbleSort(int s[], int n){
	int temp;
	//ֻ��Ҫ�Ƚ�n-1�Σ� 
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			
			if(s[j] > s[j+1]){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}

//��������,���ϻ������䣬ֱ��ÿ�����䶼������� 
void QuickSort(int s[], int low, int high){
	int temp;
	int i, j;
	i =  low;
	j = high;
	
	if(low < high){
		temp = s[low];
		
		while(i < j){
			
			//���ұ������ɨ�裬���С��tempֵ���˳�ѭ�� 
			while(j > i && s[j] >= temp) --j;
			
			//�����ߵ��ڱ�С���ұ��ڱ����ͽ��ұ��������ֵͣ��ֵ����ߵ��ڱ�λ�� 
			if(i < j){
				s[i] = s[j];
			} 
			
			//�ҵ���������һ������tempֵ������λ�� 
			while(i < j && s[i] <= temp) ++i;
			if(i < j){
				s[j] =  s[i];
			}
			
		}
		
		//���������ڱ������ˣ�˵���������䶼�Ѿ�����ɹ�������׼ֵ��ֵ�����λ�ã��ͻ��ֳ��������� 
		s[i] =  temp;
		QuickSort(s, low, i-1);
		QuickSort(s, i+1, high);
		
	}
	
} 


int main(void){
	
	cout<<"��������Ҫ��������ݸ���";
	int n, s[20];
	cin>>n;
	
	cout<<"��������Ҫ��������ݣ�";
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	QuickSort(s, 0, n-1);
	cout<<"�������������£� "<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	} 
	
	cout<<endl;
	
	
	 
	
} 
