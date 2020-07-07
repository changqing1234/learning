#include<stdio.h>
#include<iostream>
#include<malloc.h> 
#include<stdlib.h>
using namespace std;
#define maxSize 3

typedef int ElemType; 

//队列的数据结构 
typedef struct{
	ElemType *data;
	int  front, rear;
	int length;
	
	
}Queue; 

//初始化队列 
void init(Queue &Q){
	Q.data = (ElemType* )malloc(sizeof(ElemType) * maxSize);
	Q.front = Q.rear =0;
	Q.length = maxSize;
	
} 

//入队,如果队里已满，就重新分配空间 
int enQueue(Queue &Q, int x){
	//队列已满，进行重新分配空间 
	if(Q.front == (Q.rear+1) % maxSize){
		Q.data = (ElemType*)realloc(Q.data, sizeof(ElemType) * (Q.length+maxSize));
		Q.length = Q.length + maxSize;
	}
	
	Q.data[Q.rear] = x;
	Q.rear++;

	return 1;	
		
}

//出队列
int deQueue(Queue &Q, int &x){
	if(Q.rear != Q.front){
		x = Q.data[Q.front];
		Q.front++;
		return 1;
	}
	
	else{
		cout<<"空队列"<<endl;
		return 0;
	}
		
} 

//打印队列
void print(Queue Q){
	cout<<"队列数据如下"<<endl;
	for(int i=Q.front; i< Q.rear; i++){
		cout<<Q.data[i]<<" ";
	}
	cout<<endl;
} 


int main(void){
	Queue Q;
	ElemType index, n;
	int value;
	
	init(Q);
	cout<<"请输入你要输入的个数和数据"<<endl;
	
	cin>>n; 
	for(int i=0; i<n; i++){
		cin>>index;
		enQueue(Q, index);
	}
	
	

	deQueue(Q, value);
	cout<<"出队数据为:"<<value<<endl;
	print(Q);	
	
	
}



