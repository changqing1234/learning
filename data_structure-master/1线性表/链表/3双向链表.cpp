#include <iostream>
using namespace std;
#include <stdlib.h>
struct DulNode{
  int date;
  struct dulnode *prior;
  struct dulnode *next;
}DulNode, *DuLink;

void creat(DuLink& L, int n)
{
   DuLink p;
   L=(DuLink) malloc(sizeof(DulNode));
   L->next=NULL;
   L->prior=NULL;
   
   for(i=n;i>0;--i)
   {
     p=(DuLink) malloc(sizeof(DulNode));
	 cout <<"input a date \n";
	 cin >>p->data;
	 ptmp=p->prior;
     p->prior->next=p;
     p->next=p;

  node->prior=pnode;
  pnode->prior=ptmp;;

   }
}

void creatnode(int data)
{
  pnode= malloc
  pnode->data=data;
  pnode->next=pnode->prior=pnode //指向自身

   //creatlink
  ptmp=node->prior;
  node->prior->next=pnode;
  pnode->next=node;

  node->prior=pnode;
  pnode->prior=ptmp;
}



void insert(DuLink &L, int i, int e)
{
    DuLink p; int j;
	p=L;j=0;
	while(p && j<i-1){p=p->next;++j;}
	if (!(s=(DuLink)malloc(sizeof(DulNode))))  exit(-1);
	s->date=e;
	s->prior=p->prior;
    p->prior->next=s;
	s->next=p;
	p->prior=s;
	return;

}
void result(DuLink L)
{
    DuLink p; int j;
	p=L;j=0;
  while (p->next!=L)
  {
    cout <<"p->date"<<"--";
	cout <<endl;
  }

}
int main()
{
    DuLink la;
	creat(la,5);
	insert(la,3,100);

}
