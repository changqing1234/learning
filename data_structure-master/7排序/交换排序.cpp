#include<stdio.h>
#include<iostream>
using namespace std;

//冒泡排序 
void BubbleSort(int s[], int n){
	int temp;
	//只需要比较n-1次， 
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

//快速排序,不断划分区间，直到每个区间都是有序的 
void QuickSort(int s[], int low, int high){
	int temp;
	int i, j;
	i =  low;
	j = high;
	
	if(low < high){
		temp = s[low];
		
		while(i < j){
			
			//从右边向左边扫描，如果小于temp值就退出循环 
			while(j > i && s[j] >= temp) --j;
			
			//如果左边的哨兵小于右边哨兵，就将右边区间的暂停值赋值到左边的哨兵位置 
			if(i < j){
				s[i] = s[j];
			} 
			
			//找到左边区间第一个大于temp值的数据位置 
			while(i < j && s[i] <= temp) ++i;
			if(i < j){
				s[j] =  s[i];
			}
			
		}
		
		//左右两个哨兵相遇了，说明两个区间都已经排序成功，将基准值赋值到这个位置，就划分出两个区间 
		s[i] =  temp;
		QuickSort(s, low, i-1);
		QuickSort(s, i+1, high);
		
	}
	
} 


int main(void){
	
	cout<<"请输入你要输入的数据个数";
	int n, s[20];
	cin>>n;
	
	cout<<"请输入你要输入的数据：";
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	
	QuickSort(s, 0, n-1);
	cout<<"排序后的数据如下： "<<endl;
	for(int i=0; i<n; i++){
		cout<<s[i]<<" ";
	} 
	
	cout<<endl;
	
	
	 
	
} 
