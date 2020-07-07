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
	
	cout<<"请输入你要输入的数据个数"<<endl;
	cin>>n;
	
	cout<<endl;
	//尾插法 
	createDListR(L, n);
	print(L);
	
	
	int i, e;
	cout<<"请输入你要添加的位置和数据：";
	cin>>i;
	cin>>e;
	 
	insertDLNode(L, i, e);
	print(L);

}

//打印双链表 
void print(LinkList L){
	LinkList p = L->next;
	cout<<"链表的数据如下："<<endl;
	 
	while(p){
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}


//尾插法建立双链表 
void createDListR(LinkList &L, int n){
	LinkList s, r;
	
	L = (LinkList)malloc(sizeof(LNode));
	L->prior = NULL;
	L->next = NULL;
	
	r = L;
	
	cout<<"请输入你要输入的数据:";
	
	for(int i=0; i<n; i++){
		s = (LinkList)malloc(sizeof(LNode));
		cin>>s->data;
		
		r->next = s;
		s->prior = r;
		r = s;
	}
	
	r->next =  NULL;	
	
}

//查找结点的算法, 并返回节点的指针 
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

//在第i个位置之前插入结点，结点的位置是第i个位置 
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
 
