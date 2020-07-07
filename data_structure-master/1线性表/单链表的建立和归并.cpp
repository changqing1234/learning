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
	
	cout<<"��������Ҫ��������ݸ���"<<endl;
	cin>>n;
	
	//ͷ�巨 
	createListF(L1, n);
	print(L1);
	
	cout<<endl;
	//β�巨 
	createListR(L2, n);
	print(L2);
	
	
	merge2(L1, L2, L3);
	print(L3);
	
}

//��ӡ������ 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"������������£�"<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}


//β�巨����������(˳��������) 
void createListR(LinkList &L, int n){
	
	LinkList r, s;
	
	//����ͷ��� 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	r = L;
	
	cout<<"����β�巨����������Ҫ��������� ";
	 
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		r->next = s;
		r = s;
		
	}
	
	r->next = NULL;
}

//ͷ�巨��������
void createListF(LinkList &L, int n){
	LinkList s;
	
	cout<<"����ͷ�巨����������Ҫ���������: "; 
	
	//����ͷ��� 
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		
		//��ͷ����ָ����ֵ���½��Ľ�㣬���½ڵ���뵽ͷ������һ�����֮�� 
		s->next = L->next;
		//ͷ���ָ���½����Ľ�� 
		L->next = s;  
	}
	
} 

//����������������й鲢 ������������� 
void merge1(LinkList &A, LinkList &B, LinkList &C){

	LinkList p, q, r;
	
	p = A->next;
	q = B->next;
	C =  A;
	C->next =  NULL;
	r = C;
	
	//�ͷ�B��ͷ��� 
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

//����鲢
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
