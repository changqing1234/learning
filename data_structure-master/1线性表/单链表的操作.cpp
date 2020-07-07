#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;
#define ok 1
#define false 0 

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

 //�������� 
 Status CreatList(LinkList &L, int n){
 	int i;
 	
 	L = (LinkList)malloc(sizeof(LNode));
 	L->next = NULL;
 	
 	cout<<"��������Ҫ�������ݣ�\n";
 	
 	for(i = 0; i < n; i++){
 		LinkList p = new LNode;
 		cin>> p->data;
 		p->next = L->next;
 		L->next = p;
	 }
	 return ok;
 }
 //���������Ԫ�� 
 Status ListInsert(LinkList &L, int i, ElemType e){
    LinkList s,  p = L;
 	int j = 0;
 	
 	while(p && j < i - 1){
 		p = p->next;
 		j++;
	 }
	 
	 if(!p||j > i -  1) {
	 	cout<<"�������λ�������⣬���벻�ɹ�\n";
	 	return false;
	 }
	 s = new LNode;
	 s->data = e;
	 s->next = p->next;
	 p->next = s;
	 cout<<"����ɹ���\n";
	 system("pause");
	 return ok; 
 }
  //������ĺϲ�
  Status MergeList(LinkList &La, LinkList &Lb, LinkList &Lc){
  	LinkList pa, pb, pc;
  	pa = La->next; pb = Lb->next;
	Lc = pc = pa;
	
	while(pa && pb){
		if(pa->data <= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	
	pc->next = pa ? pa:pb;
	free(Lb); 
  } 
  
 Status Put(LinkList L){
 	LinkList p = L->next;
 	cout<<"������������£�\n";
 	while(p){
 		cout<<p->data<<" ";
 		p = p->next;
	 }
	 cout<<endl;
	 return ok;
 } 
 
 //ɾ�������е�Ԫ��
 Status ListDelete(LinkList &L, int i, ElemType &e){
 	LinkList p = L;
 	int j = 0;
 	
 	while(p->next && j < i-1){
 		p = p->next;
 		j++;
	 }
	 
	 if(!(p->next) || j > i-1){
	 	cout<<"ɾ��λ�ô���, ɾ�����ɹ�:\n";
	 	return false;
	 }
	 
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	cout<<"ɾ���ɹ���\n";
	free(q);
	 return ok;
 }  
 Status Display(void){
 	system("cls");
 	cout<<"��ѡ����Ĳ�����\n\n";
 	printf("\n 1 �������\n\n 2 ���ӽڵ�\n\n 3 ɾ���ڵ�\n\n 4 ���ȫ������\n\n 5 �˳�ϵͳ\n\n"); 
 }
 
 int main(void){
 	
 	int i, n, e, a = 0;
 	cout<<"��������Ҫ��������ĸ�����\n";
 	
 	int j;
 	cin>> j;
 	LinkList L[j];
 	LinkList p;
 	
 	for(i = 0; i < j; i++){	
						cout<<"\n���������ݵĸ�����\n";
		 				cin>> n;
		 				CreatList(L[i], n);
					} 
 	
 	while(1){	
		Display();
	 	int select, n1, n2, n3;
	 	
	 	while(1){  
		 	cin>>select;
		 	if(select > 5 || select < 1) cout<<"�������ѡ�������⣬����������:\n";
		 	else break;
		 }	
		 
		 if(select != 4 && select != 5) {	
				cout<<"�������ѡ����Ҫ������������ţ�"; 
			while(1){	
			 
				
				for(i = 0; i < j; i++){
					cout<< i+1<<" ";
				}
				cout<< endl;
				
					cin>> n2; 
					if(n2 > j || n2 <= 0){
						cout<<"��ѡ���������Ų���ȷ��������ѡ��"; 
					}
					else break;
				
			  } 	
		 
					
		   }
	
		 	
		switch(select){
					
	 		case 1:
	 				Put(L[n2-1]); system("pause"); 
					 break;
	 		case 2: 
		 			cout<<"��������Ҫ�����λ�ú�����\n";	
		 			while(1){
					 	cin>> i>> e;	
						  if(ListInsert(L[n2-1], i, e)) break;
						  cout<<"���벻�ɹ�������������λ�ú����ݣ�\n";
						  
						   
					 } 
		 			break;
	 		case 3:
	 				int n1, e1;
	 				cout<<"��������Ҫɾ����λ��"<<endl; 
	 				cin>> n1;
	 				ListDelete(L[n2-1], n1, e1);
	 				cout<<"��ɾ������Ϊ��"<<e1 <<endl;
	 				break;
	 		case 4:
	 			cout<<"���ȫ������\n\n";
	 			for(i = 0; i < j; i++){
	 				Put(L[i]);
				 }
				 system("pause"); 
				 break;
	 		case 5:
			 	 	return 0;	
		}
	}
	 	
	  
 	
 }
