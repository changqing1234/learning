#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
typedef struct Queue{
	int data;
	struct Queue *next;
}Queue, *LinkQueue;

//����ڵ�����Ŷ��У�������ͷ�Ͷ�βָ�� 
typedef struct{
	Queue *front;
	Queue *rear;
}LiQueue;

void initQueue(LiQueue *&lqu);
void enQueue(LiQueue *lqu, ElemType x);
int deQueue(LiQueue *lqu, ElemType &x);
int isEmpty(LiQueue *lqu);
void print(LiQueue * lqu);



int main(void){
	LiQueue* lqu;
	initQueue(lqu);
	int value, select;
	
	cout<<"��������Ҫ���������"<<endl;
		while(1){
		cout<<"		1 ���";
		cout<<"		2 ����";
		cout<<"		3 ��ӡ��������"<<endl;
		cout<<"��ѡ����Ĳ���"<<endl;
		
		cin>>select;
		switch(select){
			case 1:	
				cout<<"��������Ҫ���������"<<endl;
				cin>>value;
				enQueue(lqu, value);
				break;
			
			case 2:
				deQueue(lqu, value);
				cout<<"��������Ϊ:"<<value<<endl;
				break;
				
			case 3:
				print(lqu);
				break;
			default: cout<<"���������⣬����������"<<endl; 
		}
	}
}


void print(LiQueue *lqu){
	LinkQueue p;
	if(lqu->front == NULL){
		cout<<"����Ϊ��"<<endl;
	}else{
		cout<<"�����������£�"<<endl; 
		p = lqu->front;
		while(p){
			cout<<p->data<<" ";
			p = p->next;
		}
	}
	
} 

//��ʼ�������У��൱�ڴ���һ��ͷ��㣬����������ָ�� 
void initQueue(LiQueue *&lqu){
	lqu = (LiQueue*)malloc(sizeof(LiQueue));
	lqu->front = NULL;
	lqu->rear =  NULL;
}

//�ж϶����Ƿ�Ϊ��,��Ϊ1 
int isEmpty(LiQueue *lqu){
	if(lqu->front == NULL || lqu->rear == NULL){
		return 1;
	}
	
	return 0;
} 

//����㷨 
void enQueue(LiQueue *lqu, ElemType x){
	LinkQueue p = (LinkQueue)malloc(sizeof(LinkQueue));
	p->data = x;
	p->next = NULL;
	
	//����ǵ�һ���ڵ㣬��ͷ�Ͷ�β��ָ������ڵ� 
	if(lqu->rear == NULL){
		lqu->front = lqu->rear = p;
		
	}else{
		//��β�������һλ��ָ�����µĽڵ� 
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

//�����㷨
int deQueue(LiQueue *lqu, ElemType &x){
	LinkQueue p;
	if(lqu->rear == NULL){
		return 0;
		
	}else{
		//ֻ��һ���ڵ� 
		if(lqu->rear ==  lqu->front){
			lqu->rear = lqu->front = NULL;
		}else{	
			p = lqu->front;
			lqu->front =  p->next;
			x = p->data;
			free(p);
			
		}
		
		return 1;
	}

	
} 
