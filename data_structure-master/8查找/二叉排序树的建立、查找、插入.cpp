#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef int ElemType;
#define maxSize 40

//二叉树的节点定义 ，二叉链表格式 
typedef struct BTNode{
	ElemType key;		   //本节点数据域 
	struct BTNode *lchild; //指向左孩子的指针 
	struct BTNode *rchild; //指向右孩子的指针 
}BTNode, *BTree;



//先序遍历建立二叉树 
void CreateBTree(BTree &T);

//访问函数 
void visit(BTree &T);

//先序遍历 
void preorder(BTree &p);

//构造二叉排序树 
void CreateBST(BTree &bt);

//二叉排序树插入算法 
int BSTInsert(BTree &bt, ElemType key); 

//二叉排序树查找算法 
BTree BSTSearch(BTree bt, ElemType key);

int main(void){
	BTree T, p;
	ElemType key;
	
	cout<<"以先序遍历进行创建二叉树"<<endl;
	cout<<"请输入，以0键结束"<<endl;
	
	//构造二叉排序树 
	CreateBST(T);
	
	cout<<"\n先序遍历结果如下: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n请输入你还要查询的关键字： "<<endl;
	cin>>key;
	 p = BSTSearch(T, key);
	if(p == NULL){
		cout<<"找不到数据"<<endl; 
	}else{
		cout<<"查找成功,数据为："<<p->key<<endl;
	}
	
} 

//构造二叉排序树 
void CreateBST(BTree &bt){
	int i, n;
	
	cout<<"请输入你要数据的个数: "<<endl;
	cin>>n;
	
	ElemType data[n];
	
	cout<<"请输入"<<n<<"个数据"<<endl;
	for(int i=0; i<n; i++){
		cin>>data[i];
	}
	
	bt = NULL;
	for(int i=0; i<n; i++){
		if(BSTInsert(bt, data[i])){
			cout<<"这个数据已存在，插入失败"<<endl;
		}
	}
}

//二叉排序树插入算法 
int BSTInsert(BTree &bt, ElemType key){
	//如果为空，就返回 
	if(bt == NULL){
		bt = (BTree)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return 0;
		
	//如果查找成功， 就返回指针 
	}else if( bt->key == key){
		return 1;
		
		//查找右子树 
	}else if(bt->key < key){
		 return BSTInsert(bt->rchild,  key);
		
		//查找左子树 
	}else{
		 return BSTInsert(bt->lchild,  key);
	}
}


//二叉排序树查找算法 
BTree BSTSearch(BTree bt, ElemType key){
	//如果为空，就返回 
	if(bt == NULL){
		return NULL;
		
	//如果查找成功， 就返回指针 
	}else if( bt->key == key){
		return bt;
		
		//查找右子树 
	}else if(bt->key < key){
		return BSTSearch(bt->rchild, key);
		
		//查找左子树 
	}else{
		return BSTSearch(bt->lchild, key);
	}
}

//访问函数 
void visit(BTree &T){
	cout<<T->key<<" ";
}

//先序遍历 
void preorder(BTree &p){
	if(p != NULL){
		visit(p);
		preorder(p->lchild);
		preorder(p->rchild); 
	}
}
	
