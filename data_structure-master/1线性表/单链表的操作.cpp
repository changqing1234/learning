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

 //创建链表 
 Status CreatList(LinkList &L, int n){
 	int i;
 	
 	L = (LinkList)malloc(sizeof(LNode));
 	L->next = NULL;
 	
 	cout<<"请输入你要输入数据：\n";
 	
 	for(i = 0; i < n; i++){
 		LinkList p = new LNode;
 		cin>> p->data;
 		p->next = L->next;
 		L->next = p;
	 }
	 return ok;
 }
 //增加链表的元素 
 Status ListInsert(LinkList &L, int i, ElemType e){
    LinkList s,  p = L;
 	int j = 0;
 	
 	while(p && j < i - 1){
 		p = p->next;
 		j++;
	 }
	 
	 if(!p||j > i -  1) {
	 	cout<<"你输入的位置有问题，插入不成功\n";
	 	return false;
	 }
	 s = new LNode;
	 s->data = e;
	 s->next = p->next;
	 p->next = s;
	 cout<<"插入成功：\n";
	 system("pause");
	 return ok; 
 }
  //单链表的合并
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
 	cout<<"输出的链表如下：\n";
 	while(p){
 		cout<<p->data<<" ";
 		p = p->next;
	 }
	 cout<<endl;
	 return ok;
 } 
 
 //删除链表中的元素
 Status ListDelete(LinkList &L, int i, ElemType &e){
 	LinkList p = L;
 	int j = 0;
 	
 	while(p->next && j < i-1){
 		p = p->next;
 		j++;
	 }
	 
	 if(!(p->next) || j > i-1){
	 	cout<<"删除位置错误：, 删除不成功:\n";
	 	return false;
	 }
	 
	LinkList q = p->next;
	p->next = q->next;
	e = q->data;
	cout<<"删除成功：\n";
	free(q);
	 return ok;
 }  
 Status Display(void){
 	system("cls");
 	cout<<"请选择你的操作：\n\n";
 	printf("\n 1 输出链表\n\n 2 增加节点\n\n 3 删除节点\n\n 4 输出全部链表\n\n 5 退出系统\n\n"); 
 }
 
 int main(void){
 	
 	int i, n, e, a = 0;
 	cout<<"请输入你要输入链表的个数：\n";
 	
 	int j;
 	cin>> j;
 	LinkList L[j];
 	LinkList p;
 	
 	for(i = 0; i < j; i++){	
						cout<<"\n请输入数据的个数：\n";
		 				cin>> n;
		 				CreatList(L[i], n);
					} 
 	
 	while(1){	
		Display();
	 	int select, n1, n2, n3;
	 	
	 	while(1){  
		 	cin>>select;
		 	if(select > 5 || select < 1) cout<<"你输入的选项有问题，请重新输入:\n";
		 	else break;
		 }	
		 
		 if(select != 4 && select != 5) {	
				cout<<"请从下面选择你要操作的链表序号："; 
			while(1){	
			 
				
				for(i = 0; i < j; i++){
					cout<< i+1<<" ";
				}
				cout<< endl;
				
					cin>> n2; 
					if(n2 > j || n2 <= 0){
						cout<<"你选择的链表序号不正确，请重新选择："; 
					}
					else break;
				
			  } 	
		 
					
		   }
	
		 	
		switch(select){
					
	 		case 1:
	 				Put(L[n2-1]); system("pause"); 
					 break;
	 		case 2: 
		 			cout<<"请输入你要插入的位置和数据\n";	
		 			while(1){
					 	cin>> i>> e;	
						  if(ListInsert(L[n2-1], i, e)) break;
						  cout<<"插入不成功，请重新输入位置和数据：\n";
						  
						   
					 } 
		 			break;
	 		case 3:
	 				int n1, e1;
	 				cout<<"请输入你要删除的位置"<<endl; 
	 				cin>> n1;
	 				ListDelete(L[n2-1], n1, e1);
	 				cout<<"你删除的数为："<<e1 <<endl;
	 				break;
	 		case 4:
	 			cout<<"输出全部链表：\n\n";
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
