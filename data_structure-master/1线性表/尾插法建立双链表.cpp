 #include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef int ElemType;

typedef struct DLNode{
	ElemType data;
	struct DLNode *prior;
	struct DLNode *next;
	
}LNode, *LinkList;

void print(LinkList L);
void createDListR(LinkList &L, int n);
int insertDLNode(LinkList &L, int i, ElemType e);

int main(void){
	int n; 
	LinkList L;
	
	cout<<"��������Ҫ��������ݸ���"<<endl;
	cin>>n;
	
	cout<<endl;
	//β�巨 
	createDListR(L, n);
	print(L);
	
	
	int i, e;
	cout<<"��������Ҫ��ӵ�λ�ú����ݣ�";
	cin>>i;
	cin>>e;
	 
	insertDLNode(L, i, e);
	print(L);

}

//��ӡ˫���� 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"������������£�"<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}


//β�巨����˫���� 
void createDListR(LinkList &L, int n){
	LinkList s, r;
	
	L = (LinkList)malloc(sizeof(LNode));
	L->prior = NULL;
	L->next = NULL;
	
	r = L;
	
	cout<<"��������Ҫ���������:";
	
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		
		r->next = s;
		s->prior = r;
		r = s;
	}
	
	r->next =  NULL;	
	
}

//���ҽ����㷨, �����ؽڵ��ָ�� 
LinkList findDLNode(LinkList L, ElemType e){
	LinkList p = L->next;
	while(p){
		if(p->data == e){
			break;
		}
		
		p = p->next;
	}
	
	return p;
} 

//�ڵ�i��λ��֮ǰ�����㣬����λ���ǵ�i��λ�� 
int insertDLNode(LinkList &L, int i, ElemType e){
	LinkList p = L;
	int j = 0;
	
	while(p && j<i-1){
		p =  p->next;
		j++;
	}
	
	if(p == NULL || j > i-1) 
		return 0;
		
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next = s;
	s->next->prior = s;
	
	return 1;
	
}
 
