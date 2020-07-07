#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef int ElemType;

typedef struct DLNode{
	ElemType data;
	struct DLNode *next;
	
}LNode, *LinkList;

void print(LinkList L);
void createListR(LinkList &L, int n);
int findAndDelete(LinkList L, ElemType e);


int main(void){
	int n; 
	LinkList L;
	ElemType e;
	
	cout<<"请输入你要输入的数据个数"<<endl;
	cin>>n;
	
	cout<<endl;
	//尾插法 
	createListR(L, n);
	print(L);
	
	
	cout<<"请输入你要删除的数据: ";
	cin>>e;
	 
	
	findAndDelete(L, e);
	print(L);
	
	
	

}


//打印单链表 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"操作后的链表的数据如下："<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

//查找数据，并删除 
int findAndDelete(LinkList L, ElemType e){
	LinkList p, q;
	p = L;
	
	while(p->next){
		if(p->next->data == e){
			break;
		}
		
		p = p->next;
	}
	
	if(p->next == NULL){
		return 0;
		
	}else{
		q = p->next;
		p->next = p->next->next;
		free(q); 
		
		return 1;
	}
}

//尾插法建立单链表(顺序建立链表) 
void createListR(LinkList &L, int n){
	
	LinkList r, s;
	
	//建立头结点 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	
	cout<<"这是尾插法，请输入你要输入的数据 ";
	 
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		r->next = s;
		r = s;
		
	}
	
	r->next = NULL;
}
