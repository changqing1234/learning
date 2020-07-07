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

//����������������� 
void CreateBTree(BTree &T);

//���ʺ��� 
void visit(BTree &T);

//������� 
void preorder(BTree &p);

//�������
void inorder(BTree &p);

//�������
void postorder(BTree &p);

//��α���
void level(BTree &p); 

int main(void){
	BTree T;
	cout<<"������������д���������"<<endl;
	cout<<"�����룬��*������"<<endl;
	
	//������������ 
	CreateBTree(T);
	
	cout<<"\n��������������: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n��������������:"<<endl;
	inorder(T);
	cout<<endl;
	
	cout<<"\n��������������"<<endl;
	postorder(T);
	
	cout<<"\n��α����Ľ�����£�"<<endl;;
	level(T);
	 
	
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

//�������
void inorder(BTree &p){
	if(p != NULL){
		inorder(p->lchild);
		visit(p);
		inorder(p->rchild);
	}
} 

//�������
void postorder(BTree &p){
	if(p != NULL){
		postorder(p->lchild);
		postorder(p->rchild);
		visit(p);
	} 
} 

//��α���,���Ƚ����ڵ���ӣ�Ȼ�󲻶ϵĽ�����������ӣ�Ȼ���ٳ��ӣ����п�ʱ���ǲ�νṹ�� 
void level(BTree &p){
	int front, rear;
	BTree queue[maxSize];
	BTree q;
	
	rear = front = 0;
	
	if(p != NULL){
		//���ڵ���� 
		rear = (rear+1)%maxSize;
		queue[rear] = p;
		
		while(front != rear){
			//��ͷ���� 
			front = (front+1)%maxSize;
			q = queue[front];
			visit(q);
			
			//������� 
			if(q->lchild != NULL){
				rear = (rear+1)%maxSize;
				queue[rear] = q->lchild;
			}
			
			//��������� 
			if(q->rchild != NULL){
				rear = (rear+1)%maxSize;
				queue[rear] = q->rchild;
			}
		}
	}	
	
	
} 
