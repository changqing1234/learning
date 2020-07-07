#include<stdio.h>
#include<iostream>
#include<malloc.h> 
#include<stdlib.h>
using namespace std;
#define maxSize 3

typedef int ElemType; 

//���е����ݽṹ 
typedef struct{
	ElemType *data;
	int  front, rear;
	int length;
	
	
}Queue; 

//��ʼ������ 
void init(Queue &Q){
	Q.data = (ElemType* )malloc(sizeof(ElemType) * maxSize);
	Q.front = Q.rear =0;
	Q.length = maxSize;
	
} 

//���,������������������·���ռ� 
int enQueue(Queue &Q, int x){
	//�����������������·���ռ� 
	if(Q.front == (Q.rear+1) % maxSize){
		Q.data = (ElemType*)realloc(Q.data, sizeof(ElemType) * (Q.length+maxSize));
		Q.length = Q.length + maxSize;
	}
	
	Q.data[Q.rear] = x;
	Q.rear++;

	return 1;	
		
}

//������
int deQueue(Queue &Q, int &x){
	if(Q.rear != Q.front){
		x = Q.data[Q.front];
		Q.front++;
		return 1;
	}
	
	else{
		cout<<"�ն���"<<endl;
		return 0;
	}
		
} 

//��ӡ����
void print(Queue Q){
	cout<<"������������"<<endl;
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
	cout<<"��������Ҫ����ĸ���������"<<endl;
	
	cin>>n; 
	for(int i=0; i<n; i++){
		cin>>index;
		enQueue(Q, index);
	}
	
	

	deQueue(Q, value);
	cout<<"��������Ϊ:"<<value<<endl;
	print(Q);	
	
	
}



