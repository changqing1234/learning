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

//二叉排序树查找关键字，如果找到数据，就用p指针指向数据，否则，就将数据插入到二叉排序树中 
void BTSearch(BTree &bt, BTree &p, ElemType key); 

int main(void){
	BTree T, p;
	ElemType key;
	
	cout<<"以先序遍历进行创建二叉树"<<endl;
	cout<<"请输入，以0键结束"<<endl;
	
	//先序建立二叉树 
	CreateBTree(T);
	
	cout<<"\n先序遍历结果如下: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n请输入你还要查找的关键字: "<<endl;
	cin>>key;
	BTSearch(T, p, key);
	if(p == NULL){
		cout<<"找不到数据，查找失败："<<endl;
		cout<<"已将数据插入到二叉排序树中，数据如下："<<endl;
		preorder(T);
		cout<<endl; 
		
	}else{
		cout<<"查找成功,数据为："<<p->key<<endl;; 
	}
	
} 

//先序遍历建立二叉树 
void CreateBTree(BTree &T){
	ElemType ch;
	cin>>ch;
	
	//如果没有左右孩子，就输入*结束这一个节点，进入其他节点继续创建 
	if(ch == 0){
		T = NULL;
			
	}else{
		T = (BTree)malloc(sizeof(BTNode));
		T->key = ch;
		
		cout<<"  "<<ch<<"是否有左孩子，如果有就直接输入数据，无则输入0"<<endl;
		CreateBTree(T->lchild);
		
		cout<<"  "<<ch<<"是否有右孩子，如果有就直接输入数据，无则输入0"<<endl;
		CreateBTree(T->rchild);
		
	}
}

//二叉排序树查找算法 
void BTSearch(BTree &bt, BTree &p, ElemType key){
	//如果为空，就返回 
	if(bt == NULL){
		bt = (BTree)malloc(sizeof(BTNode));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return;
		
	//如果查找成功， 就返回指针 
	}else if( bt->key == key){
		p = bt;
		
		//查找右子树 
	}else if(bt->key < key){
		 BTSearch(bt->rchild, p, key);
		
		//查找左子树 
	}else{
		 BTSearch(bt->lchild, p, key);
	}
}

/*
//二叉排序树查找算法 
BTree BTSearch(BTree bt, ElemType key){
	//如果为空，就返回 
	if(bt == NULL){
		return NULL;
		
	//如果查找成功， 就返回指针 
	}else if( bt->key == key){
		return bt;
		
		//查找右子树 
	}else if(bt->key < key){
		return BTSearch(bt->rchild, key);
		
		//查找左子树 
	}else{
		return BTSearch(bt->lchild, key);
	}
}


*/

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
	
