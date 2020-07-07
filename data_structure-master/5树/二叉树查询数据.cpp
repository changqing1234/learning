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

//��ѯ���ݣ�����ָ��ָ������
void search(BTree T, BTree &p, ElemType key); 

int main(void){
	BTree T, p;
	T = p = NULL;
	ElemType key;
	
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
	
	cout<<"��������Ҫ��ѯ������"<<endl;

	cin>>key; 
	
	search(T, p, key);
	
	cout<<p->data;
	if(p != NULL){
		cout<<"��ѯ�ɹ�"<<endl; 
		
	} else{
		cout<<"�Ҳ������ݼ�¼"<<endl; 
	}
	 
	
} 

//�����������ݵ�λ��,����ָ��ָ��������� 
void search(BTree T, BTree &p, ElemType key){
	if(T != NULL){
		
		if(T->data != key){
			search(T->lchild, p, key);
			//�����������ҵ������ݣ��Ͳ����������н��в��� 
			if(p == NULL){
				search(T->rchild, p, key); 
			}
			
		}else{
			p = T;
			
		}
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
