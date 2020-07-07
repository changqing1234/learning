#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40

//�������Ľڵ㶨�� �����������ʽ 
typedef struct BTNode{
	ElemType data;		   //���ڵ������� 
	struct BTNode *lchild; //ָ�����ӵ�ָ�� 
	struct BTNode *rchild; //ָ���Һ��ӵ�ָ�� 
}BTNode, *BTree;

//������ѭ�����У�������Ľڵ��а����˲�εĴ�С������ͳ����ͬ��εĸ����������� 
typedef struct{
	BTree p;
	int lno;
}st; 

//����������������� 
void CreateBTree(BTree &T);

//���ʺ��� 
void visit(BTree &T);

//������� 
void preorder(BTree &p);

//�����Ŀ��
int maxNode(BTree T); 

int main(void){
	BTree T;
	cout<<"������������д���������"<<endl;
	cout<<"�����룬��*������"<<endl;
	
	//������������ 
	CreateBTree(T);
	
	cout<<"\n��������������: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"�������������Ϊ��"<<maxNode(T)<<endl; 
	 
	
} 

int maxNode(BTree T){
	//������ѭ������ 
	st que[maxSize];
	int front, rear;
	int Lno, i, j, n, max;
	
	front = rear = 0;
	BTree q;
	
	if(T != NULL){
		//���ڵ������� 
		++rear;
		 que[rear].p= T;
		 que[rear].lno = 1;
		 
		 //��ͷ�ڵ���ӣ��������������ڴ棬֪ʶ��ͷָ��ı��˶��ѣ����rear��front������LNoΪ���Ĳ�� 
		 while(front != rear){
		 	++front;
		 	q = que[front].p;
		 	//��ȡ��ǰ�Ĳ�κ� 
		 	Lno =  que[front].lno;
		 	
		 	//���������� 
		 	if(q->lchild != NULL){
		 		++rear;
		 		que[rear].p = q->lchild;
		 		que[rear].lno = Lno+1;
			 }
			 
			//���������� 
			if(q->rchild != NULL){
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = Lno+1;
			}
		 }
		 
		 // ͳ��0��Lno����ε��������ҳ����ֵ�������Ŀ�� 
		 max  = 0;
		 for(int i=0; i<=Lno; ++i){
		 	n = 0;
		 	for(int j=0; j<=rear; ++j){
		 		if(que[j].lno == i){
		 			++n; 
				 }
			 }
			 
			 if(n > max){
			 	max = n;
			 } 
		 }
		 
		 return max;
		 
	}else{
		//������ֱ�ӷ���0 
		return 0;
	}
}

//����������������� 
void CreateBTree(BTree &T){
	ElemType ch;
	cin>>ch;
	
	//���û�����Һ��ӣ�������*������һ���ڵ㣬���������ڵ�������� 
	if(ch == '*'){
		T = NULL;
			
	}else{
		T = (BTree)malloc(sizeof(BTNode));
		T->data = ch;
		
		cout<<"  "<<ch<<"�Ƿ������ӣ�����о�ֱ���������ݣ���������*"<<endl;
		CreateBTree(T->lchild);
		
		cout<<"  "<<ch<<"�Ƿ����Һ��ӣ�����о�ֱ���������ݣ���������*"<<endl;
		CreateBTree(T->rchild);
		
	}
}

//���ʺ��� 
void visit(BTree &T){
	cout<<T->data;
}

//������� 
void preorder(BTree &p){
	if(p != NULL){
		visit(p);
		preorder(p->lchild);
		preorder(p->rchild); 
	}
}

