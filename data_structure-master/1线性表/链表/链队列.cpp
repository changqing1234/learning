#include<iostream>
#include<stdio.h>
#include<iomanip>//格式控制头文件
#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct QNode{ //链队列结点的类型定义
   QElemType data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct{ //链队列的表头结点的的类型定义
   QueuePtr front;//队头指针，指向链表头结点
   QueuePtr rear; //队尾指针，指向队尾结点
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);
void PrintQueue(LinkQueue Q);

int main(){

    LinkQueue Q;
	int i,n,e;
    cout<<"构造队列：\n";
	InitQueue(Q);
	cout<<"输入要构造队列的结点个数：";
	
	cin>>n;
	for (i=1;i<=n;i++)
	{
	   cout<<"输入第"<<i<<"个结点的值";
	   cin>>e;	
	   if(!EnQueue(Q,e)) break;
	};
	cout<<"构造的队列为：";
    PrintQueue(Q);
    cout<<endl;
  
	cout<<"入队一个新结点，值为：";
	cin>>e;
	if(EnQueue(Q,e)) 
	{
		cout<<"新队列为：\n";
		PrintQueue(Q);
		cout<<endl;
	}
	else
		cout<<"error！\n";


   cout<<"出队一个结点\n";
   if (DeQueue(Q,e))
   {
       cout<<"出队元素值为："<<e<<endl;
	   cout<<"新队列为：\n";
       PrintQueue(Q);
	   cout<<endl;
   }

   else
	   cout<<"error！\n";
}


Status InitQueue(LinkQueue &Q){
	//构造一个空队列Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}


Status DestroyQueue(LinkQueue &Q){
	//销毁队列
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}


Status EnQueue(LinkQueue &Q, QElemType e){
	//插入元素e为Q的新队尾元素
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}


Status DeQueue(LinkQueue &Q, QElemType &e){
	//若队列不为空,则删除Q的队头元素,用e返回其值，
     //并返回OK;否则返回ERROR
	if(Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)     //唯一的数据结点出队，
                           //队尾指针空置       
		Q.rear = Q.front;
	free(p);
	return OK;
}

void PrintQueue(LinkQueue Q){
	//显示队列
     if(Q.front == Q.rear)
		cout<<"队列为空\n";
     QueuePtr p = Q.front->next;
	 while(p!=NULL){
		 cout<<setw(4)<<p->data;
		 p=p->next;
	 }
}
