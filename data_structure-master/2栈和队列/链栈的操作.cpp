#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
//链式栈没有栈溢出，长度可以无限长 
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
	
	cout<<"请输入你要输入的数据个数: ";
	cin>>n;
	
	cout<<"请输入"<<n<<"个数据: ";
	for(int i=0; i<n; i++){
		cin>>data;
		push(st, data);
	} 
	
	print(st);
	
	while(pop(st, data)){
		cout<<"出栈的数据为: "<<data<<endl;
	}
}

//初始化栈，建立头结点 
void initStack(LinkNode &st){
	st = (LinkNode)malloc(sizeof(LNode));
	st->next =  NULL;
}

//判断是否为空栈 
int isEmpty(LinkNode st){
	if(st->next == NULL)
		return 1;
	return 0;
}


//进栈 
void push(LinkNode &st, ElemType data){
	LinkNode p= (LinkNode)malloc(sizeof(LNode));
	p->data = data;
	p->next = st->next;
	st->next = p;
	
}

//出栈 
int pop(LinkNode &st, ElemType &data){
	if(st->next == NULL){
		cout<<"空栈"<<endl;
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
	cout<<"操作后的栈的数据如下:"<<endl; 
	while(p->next){
		cout<<p->next->data<<" ";
		p = p->next;
	}
	
	cout<<endl;
}
