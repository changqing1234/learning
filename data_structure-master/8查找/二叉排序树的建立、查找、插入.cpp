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

//������������� 
void CreateBST(BTree &bt);

//���������������㷨 
int BSTInsert(BTree &bt, ElemType key); 

//���������������㷨 
BTree BSTSearch(BTree bt, ElemType key);

int main(void){
	BTree T, p;
	ElemType key;
	
	cout<<"������������д���������"<<endl;
	cout<<"�����룬��0������"<<endl;
	
	//������������� 
	CreateBST(T);
	
	cout<<"\n��������������: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n�������㻹Ҫ��ѯ�Ĺؼ��֣� "<<endl;
	cin>>key;
	 p = BSTSearch(T, key);
	if(p == NULL){
		cout<<"�Ҳ�������"<<endl; 
	}else{
		cout<<"���ҳɹ�,����Ϊ��"<<p->key<<endl;
	}
	
} 

//������������� 
void CreateBST(BTree &bt){
	int i, n;
	
	cout<<"��������Ҫ���ݵĸ���: "<<endl;
	cin>>n;
	
	ElemType data[n];
	
	cout<<"������"<<n<<"������"<<endl;
	for(int i=0; i<n; i++){
		cin>>data[i];
	}
	
	bt = NULL;
	for(int i=0; i<n; i++){
		if(BSTInsert(bt, data[i])){
			cout<<"��������Ѵ��ڣ�����ʧ��"<<endl;
		}
	}
}

//���������������㷨 
int BSTInsert(BTree &bt, ElemType key){
	//���Ϊ�գ��ͷ��� 
	if(bt == NULL){
		bt = (BTree)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return 0;
		
	//������ҳɹ��� �ͷ���ָ�� 
	}else if( bt->key == key){
		return 1;
		
		//���������� 
	}else if(bt->key < key){
		 return BSTInsert(bt->rchild,  key);
		
		//���������� 
	}else{
		 return BSTInsert(bt->lchild,  key);
	}
}


//���������������㷨 
BTree BSTSearch(BTree bt, ElemType key){
	//���Ϊ�գ��ͷ��� 
	if(bt == NULL){
		return NULL;
		
	//������ҳɹ��� �ͷ���ָ�� 
	}else if( bt->key == key){
		return bt;
		
		//���������� 
	}else if(bt->key < key){
		return BSTSearch(bt->rchild, key);
		
		//���������� 
	}else{
		return BSTSearch(bt->lchild, key);
	}
}

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
	
