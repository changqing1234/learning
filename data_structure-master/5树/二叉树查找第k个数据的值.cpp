#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;

//������k���ڵ��ֵ
 
//�������Ľڵ㶨�� �����������ʽ 
typedef struct BTNode{
	ElemType data;		   //���ڵ������� 
	struct BTNode *lchild; //ָ�����ӵ�ָ�� 
	struct BTNode *rchild; //ָ���Һ��ӵ�ָ�� 
}BTNode, *BTree;

//����������������� 
void CreateBTree(BTree &T);

//���ʺ��� 
void visit(BTree T);

//���������k������ 
void preorder(BTree p, int k);

//���������k������ 
void inorder(BTree p, int k);

//���������k������ 
void postorder(BTree p, int k);

int n = 0;

int main(void){
	BTree T;
	int index;
	
	cout<<"������������д���������"<<endl;
	cout<<"�����룬��*������"<<endl;
	
	//������������ 
	CreateBTree(T);
	
	cout<<"��������Ҫ��ѯ������λ�ã�"<<endl;
	cin>>index;
	
	cout<<"\n��������������: "<<endl; 
	preorder(T, index);
	cout<<endl;
	
	n = 0;
	cout<<"\n��������������:"<<endl;
	inorder(T, index);
	cout<<endl;
	
	n = 0;
	cout<<"\n��������������"<<endl;
	postorder(T,  index);
	 
	
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
void visit(BTree T){
	cout<<T->data;
}

//������� 
void preorder(BTree p, int k){
	if(p != NULL){
		++n;
		if(n == k){
			cout<<"��"<<k<<"��λ����"<<p->data<<endl; 
		}
		
		preorder(p->lchild, k);
		preorder(p->rchild, k); 
	}
}

//�������
void inorder(BTree p, int k){ 
	if(p != NULL){
	 
		
		inorder(p->lchild, k);
		++n;
		
		if(n == k){
			cout<<"��"<<k<<"��λ����"<<p->data<<endl; 
		}
		inorder(p->rchild, k);
	}
} 

//�������
void postorder(BTree p, int k){
	if(p != NULL){
	
	
		postorder(p->lchild, k);
		postorder(p->rchild, k);	
		++n;
		
		if(n == k){
			cout<<"��"<<k<<"��λ����"<<p->data<<endl; 
		}
	} 
} 
