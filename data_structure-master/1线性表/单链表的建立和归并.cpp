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
void createListF(LinkList &L, int n);
void merge1(LinkList &A, LinkList &B, LinkList &C);
void merge2(LinkList &A, LinkList &B, LinkList &C);

int main(void){
	int n; 
	LinkList L1, L2, L3;
	
	cout<<"请输入你要输入的数据个数"<<endl;
	cin>>n;
	
	//头插法 
	createListF(L1, n);
	print(L1);
	
	cout<<endl;
	//尾插法 
	createListR(L2, n);
	print(L2);
	
	
	merge2(L1, L2, L3);
	print(L3);
	
}

//打印单链表 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"链表的数据如下："<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
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

//头插法建立链表
void createListF(LinkList &L, int n){
	LinkList s;
	
	cout<<"这是头插法，请输入你要输入的数据: "; 
	
	//建立头结点 
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		
		//将头结点的指针域赋值给新建的结点，即新节点插入到头结点跟下一个结点之间 
		s->next = L->next;
		//头结点指向新建立的结点 
		L->next = s;  
	}
	
} 

//将两个有序单链表进行归并 ，递增排序插入 
void merge1(LinkList &A, LinkList &B, LinkList &C){

	LinkList p, q, r;
	
	p = A->next;
	q = B->next;
	C =  A;
	C->next =  NULL;
	r = C;
	
	//释放B的头结点 
	free(B);
	
	while( p && q){
		if(p->data <= q->data){
			r->next = p;
			r = p;
			p = p->next;
			
		}else{
			r->next = q;
			r = q;
			q = q->next;
		}
		
	}
	
	r->next = p ? p: q;
}

//逆序归并
void merge2(LinkList &A, LinkList &B, LinkList &C){

	LinkList p, q, s;
	
	p = A->next;
	q = B->next;
	
	C = A;
	C->next = NULL;
	free(B);
	
	while(p && q){
		if(p->data <= q->data){
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
			
				
		}else{
			s = q;	
			q = q->next;
			s->next =  C->next;
			C->next =  s;
		
		}
	}
	
	while(p){
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
		
	}
	
	while(q){
		s = q;
		q = q->next;
		s->next =  C->next;
		C->next = s; 
		
	}
} 
