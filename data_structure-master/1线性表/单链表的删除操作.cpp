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
	
	cout<<"��������Ҫ��������ݸ���"<<endl;
	cin>>n;
	
	cout<<endl;
	//β�巨 
	createListR(L, n);
	print(L);
	
	
	cout<<"��������Ҫɾ��������: ";
	cin>>e;
	 
	
	findAndDelete(L, e);
	print(L);
	
	
	

}


//��ӡ������ 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"�������������������£�"<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

//�������ݣ���ɾ�� 
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
