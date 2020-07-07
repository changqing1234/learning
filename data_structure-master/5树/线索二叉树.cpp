#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40

//�������Ľڵ㶨�� �����������ʽ 
typedef struct BTNode{
	ElemType data;	
	int ltag, rtag;	  //������� 
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

//�����������ݹ��㷨 
void InThread(BTree p, BTree &pre); 

//������������ 
void createInThread(BTree root); 

//�ɸ��ڵ�������������µĵ�һ���ڵ� 
BTree first(BTree p);

//���̽ڵ� 
BTree next(BTree p);

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
	
	//������������������������� 
	createInThread(T);
	
	cout<<"\n�����������������£�"<<endl; 
	
	//���������� 
	for(BTree p= first(T); p != NULL; p=next(p)){
		visit(p);
	}
		 
	
} 

//������ĵ�һ���ڵ� 
BTree first(BTree p){
	while(p->ltag == 0){
		p = p->lchild;
	}
	
	return p;
} 

//�����̽ڵ� 
BTree next(BTree p){
	if(p->rtag == 0){
		return first(p->rchild);
	}else{
		return p->rchild;
	}
} 

//�����������ݹ��㷨 
void InThread(BTree p, BTree &pre){
	if(p != NULL){
		InThread(p->lchild, pre);
		if(p->lchild == NULL){
			p->lchild = pre;
			p->ltag =  1;
		}
		
		if(pre != NULL && pre->rchild == NULL){
			pre->rchild = p;
			pre->rtag = 1;
		}
		
		pre =  p;
		p= p->rchild;
		
		InThread(p, pre);
	}
	
} 

//���������������������� 
void createInThread(BTree root){
	BTree pre = NULL;
	if(root != NULL){
		InThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1; 
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
		T->ltag = 0;
		T->rtag = 0;
		
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

