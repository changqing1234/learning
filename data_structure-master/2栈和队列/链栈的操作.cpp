#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
//��ʽջû��ջ��������ȿ������޳� 
typedef int ElemType; 

typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode, *LinkNode;

void initStack(LinkNode &st);
void push(LinkNode &st, ElemType data);
int pop(LinkNode &st, ElemType &data);
int isEmpty(LinkNode st);
void print(LinkNode st);
 
 
int main(void){
	LinkNode st;
	initStack(st);
	int n, data;
	
	cout<<"��������Ҫ��������ݸ���: ";
	cin>>n;
	
	cout<<"������"<<n<<"������: ";
	for(int i=0; i<n; i++){
		cin>>data;
		push(st, data);
	} 
	
	print(st);
	
	while(pop(st, data)){
		cout<<"��ջ������Ϊ: "<<data<<endl;
	}
}

//��ʼ��ջ������ͷ��� 
void initStack(LinkNode &st){
	st = (LinkNode)malloc(sizeof(LNode));
	st->next =  NULL;
}

//�ж��Ƿ�Ϊ��ջ 
int isEmpty(LinkNode st){
	if(st->next == NULL)
		return 1;
	return 0;
}


//��ջ 
void push(LinkNode &st, ElemType data){
	LinkNode p= (LinkNode)malloc(sizeof(LNode));
	p->data = data;
	p->next = st->next;
	st->next = p;
	
}

//��ջ 
int pop(LinkNode &st, ElemType &data){
	if(st->next == NULL){
		cout<<"��ջ"<<endl;
		return 0;
	}
	
	LinkNode p = st->next;
	st->next =  p->next;
	data = p->data;
	free(p);
	return 1;
	
}

void print(LinkNode st){
	LinkNode p = st;
	cout<<"�������ջ����������:"<<endl; 
	while(p->next){
		cout<<p->next->data<<" ";
		p = p->next;
	}
	
	cout<<endl;
}
