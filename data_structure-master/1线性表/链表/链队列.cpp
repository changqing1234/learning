#include<iostream>
#include<stdio.h>
#include<iomanip>//��ʽ����ͷ�ļ�
#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int QElemType;

typedef struct QNode{ //�����н������Ͷ���
   QElemType data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct{ //�����еı�ͷ���ĵ����Ͷ���
   QueuePtr front;//��ͷָ�룬ָ������ͷ���
   QueuePtr rear; //��βָ�룬ָ���β���
}LinkQueue;

Status InitQueue(LinkQueue &Q);
Status DestroyQueue(LinkQueue &Q);
Status EnQueue(LinkQueue &Q, QElemType e);
Status DeQueue(LinkQueue &Q, QElemType &e);
void PrintQueue(LinkQueue Q);

int main(){

    LinkQueue Q;
	int i,n,e;
    cout<<"������У�\n";
	InitQueue(Q);
	cout<<"����Ҫ������еĽ�������";
	
	cin>>n;
	for (i=1;i<=n;i++)
	{
	   cout<<"�����"<<i<<"������ֵ";
	   cin>>e;	
	   if(!EnQueue(Q,e)) break;
	};
	cout<<"����Ķ���Ϊ��";
    PrintQueue(Q);
    cout<<endl;
  
	cout<<"���һ���½�㣬ֵΪ��";
	cin>>e;
	if(EnQueue(Q,e)) 
	{
		cout<<"�¶���Ϊ��\n";
		PrintQueue(Q);
		cout<<endl;
	}
	else
		cout<<"error��\n";


   cout<<"����һ�����\n";
   if (DeQueue(Q,e))
   {
       cout<<"����Ԫ��ֵΪ��"<<e<<endl;
	   cout<<"�¶���Ϊ��\n";
       PrintQueue(Q);
	   cout<<endl;
   }

   else
	   cout<<"error��\n";
}


Status InitQueue(LinkQueue &Q){
	//����һ���ն���Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}


Status DestroyQueue(LinkQueue &Q){
	//���ٶ���
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}


Status EnQueue(LinkQueue &Q, QElemType e){
	//����Ԫ��eΪQ���¶�βԪ��
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
	//�����в�Ϊ��,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ��
     //������OK;���򷵻�ERROR
	if(Q.front == Q.rear)
		return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)     //Ψһ�����ݽ����ӣ�
                           //��βָ�����       
		Q.rear = Q.front;
	free(p);
	return OK;
}

void PrintQueue(LinkQueue Q){
	//��ʾ����
     if(Q.front == Q.rear)
		cout<<"����Ϊ��\n";
     QueuePtr p = Q.front->next;
	 while(p!=NULL){
		 cout<<setw(4)<<p->data;
		 p=p->next;
	 }
}
