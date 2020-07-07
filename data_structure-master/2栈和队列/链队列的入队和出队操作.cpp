#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
typedef struct Queue{
	int data;
	struct Queue *next;
}Queue, *LinkQueue;

//这个节点代表着队列，包含队头和队尾指针 
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
	
	cout<<"请输入你要输入的数据"<<endl;
		while(1){
		cout<<"		1 入队";
		cout<<"		2 出队";
		cout<<"		3 打印队列数据"<<endl;
		cout<<"请选择你的操作"<<endl;
		
		cin>>select;
		switch(select){
			case 1:	
				cout<<"请输入您要输入得数据"<<endl;
				cin>>value;
				enQueue(lqu, value);
				break;
			
			case 2:
				deQueue(lqu, value);
				cout<<"出队数据为:"<<value<<endl;
				break;
				
			case 3:
				print(lqu);
				break;
			default: cout<<"输入有问题，请重新输入"<<endl; 
		}
	}
}


void print(LiQueue *lqu){
	LinkQueue p;
	if(lqu->front == NULL){
		cout<<"队列为空"<<endl;
	}else{
		cout<<"队列数据如下："<<endl; 
		p = lqu->front;
		while(p){
			cout<<p->data<<" ";
			p = p->next;
		}
	}
	
} 

//初始化链队列，相当于创建一个头结点，包好了两个指针 
void initQueue(LiQueue *&lqu){
	lqu = (LiQueue*)malloc(sizeof(LiQueue));
	lqu->front = NULL;
	lqu->rear =  NULL;
}

//判断队列是否为空,空为1 
int isEmpty(LiQueue *lqu){
	if(lqu->front == NULL || lqu->rear == NULL){
		return 1;
	}
	
	return 0;
} 

//入队算法 
void enQueue(LiQueue *lqu, ElemType x){
	LinkQueue p = (LinkQueue)malloc(sizeof(LinkQueue));
	p->data = x;
	p->next = NULL;
	
	//如果是第一个节点，队头和队尾都指向这个节点 
	if(lqu->rear == NULL){
		lqu->front = lqu->rear = p;
		
	}else{
		//队尾几点后移一位，指向最新的节点 
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

//出队算法
int deQueue(LiQueue *lqu, ElemType &x){
	LinkQueue p;
	if(lqu->rear == NULL){
		return 0;
		
	}else{
		//只有一个节点 
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
