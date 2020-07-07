#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef int ElemType;
#define maxSize 40

//�������Ľڵ㶨�� �����������ʽ 
typedef struct BTNode{
	ElemType key;		   //���ڵ������� 
	struct BTNode *lchild; //ָ�����ӵ�ָ�� 
	struct BTNode *rchild; //ָ���Һ��ӵ�ָ�� 
}BTNode, *BTree;



//����������������� 
void CreateBTree(BTree &T);

//���ʺ��� 
void visit(BTree &T);

//������� 
void preorder(BTree &p);

//�������������ҹؼ��֣�����ҵ����ݣ�����pָ��ָ�����ݣ����򣬾ͽ����ݲ��뵽������������ 
void BTSearch(BTree &bt, BTree &p, ElemType key); 

int main(void){
	BTree T, p;
	ElemType key;
	
	cout<<"������������д���������"<<endl;
	cout<<"�����룬��0������"<<endl;
	
	//������������ 
	CreateBTree(T);
	
	cout<<"\n��������������: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n�������㻹Ҫ���ҵĹؼ���: "<<endl;
	cin>>key;
	BTSearch(T, p, key);
	if(p == NULL){
		cout<<"�Ҳ������ݣ�����ʧ�ܣ�"<<endl;
		cout<<"�ѽ����ݲ��뵽�����������У��������£�"<<endl;
		preorder(T);
		cout<<endl; 
		
	}else{
		cout<<"���ҳɹ�,����Ϊ��"<<p->key<<endl;; 
	}
	
} 

//����������������� 
void CreateBTree(BTree &T){
	ElemType ch;
	cin>>ch;
	
	//���û�����Һ��ӣ�������*������һ���ڵ㣬���������ڵ�������� 
	if(ch == 0){
		T = NULL;
			
	}else{
		T = (BTree)malloc(sizeof(BTNode));
		T->key = ch;
		
		cout<<"  "<<ch<<"�Ƿ������ӣ�����о�ֱ���������ݣ���������0"<<endl;
		CreateBTree(T->lchild);
		
		cout<<"  "<<ch<<"�Ƿ����Һ��ӣ�����о�ֱ���������ݣ���������0"<<endl;
		CreateBTree(T->rchild);
		
	}
}

//���������������㷨 
void BTSearch(BTree &bt, BTree &p, ElemType key){
	//���Ϊ�գ��ͷ��� 
	if(bt == NULL){
		bt = (BTree)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return;
		
	//������ҳɹ��� �ͷ���ָ�� 
	}else if( bt->key == key){
		p = bt;
		
		//���������� 
	}else if(bt->key < key){
		 BTSearch(bt->rchild, p, key);
		
		//���������� 
	}else{
		 BTSearch(bt->lchild, p, key);
	}
}

/*
//���������������㷨 
BTree BTSearch(BTree bt, ElemType key){
	//���Ϊ�գ��ͷ��� 
	if(bt == NULL){
		return NULL;
		
	//������ҳɹ��� �ͷ���ָ�� 
	}else if( bt->key == key){
		return bt;
		
		//���������� 
	}else if(bt->key < key){
		return BTSearch(bt->rchild, key);
		
		//���������� 
	}else{
		return BTSearch(bt->lchild, key);
	}
}


*/

//���ʺ��� 
void visit(BTree &T){
	cout<<T->key<<" ";
}

//������� 
void preorder(BTree &p){
	if(p != NULL){
		visit(p);
		preorder(p->lchild);
		preorder(p->rchild); 
	}
}
	
