#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40
 //ʹ�÷ǵݹ鷽ʽʵ�ֱ����㷨 
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
void preorder(BTree &bt);

//�������
void inorder(BTree &bt);

//�������
void postorder(BTree &bt);

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

//����ǵݹ���� 
void preorder(BTree &bt){
	if(bt != NULL){
		BTree  Stack[maxSize];
		int top = -1;
		BTree p;
		
		//���ڵ��ջ 
		Stack[++top] = bt;
		
		while(top != -1){ //��ջ���˳� 
			//ջ���ڵ��ջ ��������ջ���ڵ� 
			p = Stack[top--];
			visit(p);
			
			//�Һ��ӽ�ջ 
			if(p->rchild != NULL){
				Stack[++top] = p->rchild;
			}
			
			//���ӽ�ջ 
			if(p->lchild != NULL){
				Stack[++top] =  p->lchild;
			}
		}
		
	}else{
		cout<<"����"<<endl; 
	}
}

//����ǵݹ����
void inorder(BTree &bt){
	if(bt != NULL){
		BTree Stack[maxSize];
		int top = -1;
	
		BTree p;
		p = bt;
		
		while(top != -1 || p != NULL){
			while(p != NULL){
				Stack[++top] = p;
				p = p->lchild;
			}
			
			if(top != -1){
				p = Stack[top--];
				visit(p);
				p = p->rchild;
			}
		} 
	}
} 

//����ǵݹ����
void postorder(BTree &bt){
	if(bt != NULL){
		BTree Stack1[maxSize]; int top1 = -1;
		BTree Stack2[maxSize]; int top2 = -1;
		
		BTree p = NULL;
		
		Stack1[++top1] = bt;
		
		while(top1 != -1){
			p = Stack1[top1--];
			Stack2[++top2] = p;
			
			if(p->lchild != NULL){
				Stack1[++top1] = p->lchild;
				 
			}
			if(p->rchild != NULL){
				Stack1[++top1] = p->rchild;
			}
		}
		
		while(top2 != -1){
			p = Stack2[top2--];
			visit(p);
		}
	}else{
		cout<<"����"<<endl; 
	}
} 


