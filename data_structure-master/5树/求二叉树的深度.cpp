#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;

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

//������������
int getdepth(BTree &T); 

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
	
	cout<<"\n\n�����������Ϊ��"<<getdepth(T)<<endl;
	 
	
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

//������������,ʹ�õݹ�ʱ����Ҫע�����Ȿ��ֻҪ��ע�����������Ĺ�ϵ���ҳ����ƹ�ʽ 
int getdepth(BTree &T){
	int LD, RD;
	
	if(T == NULL){
		return 0;
		
	}else{
				//���������� 
		LD = getdepth(T->lchild);
		RD = getdepth(T->rchild);
		
		//ԭ����������ȵ����������������+1 
		return (LD > RD ?LD:RD)+1;
	}
		
}
