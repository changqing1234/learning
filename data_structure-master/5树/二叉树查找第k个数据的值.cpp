#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;

//遍历第k个节点的值
 
//二叉树的节点定义 ，二叉链表格式 
typedef struct BTNode{
	ElemType data;		   //本节点数据域 
	struct BTNode *lchild; //指向左孩子的指针 
	struct BTNode *rchild; //指向右孩子的指针 
}BTNode, *BTree;

//先序遍历建立二叉树 
void CreateBTree(BTree &T);

//访问函数 
void visit(BTree T);

//先序遍历第k个数据 
void preorder(BTree p, int k);

//中序遍历第k个数据 
void inorder(BTree p, int k);

//后序遍历第k个数据 
void postorder(BTree p, int k);

int n = 0;

int main(void){
	BTree T;
	int index;
	
	cout<<"以先序遍历进行创建二叉树"<<endl;
	cout<<"请输入，以*键结束"<<endl;
	
	//先序建立二叉树 
	CreateBTree(T);
	
	cout<<"请输入你要查询的数据位置："<<endl;
	cin>>index;
	
	cout<<"\n先序遍历结果如下: "<<endl; 
	preorder(T, index);
	cout<<endl;
	
	n = 0;
	cout<<"\n中序遍历结果如下:"<<endl;
	inorder(T, index);
	cout<<endl;
	
	n = 0;
	cout<<"\n后序遍历结果如下"<<endl;
	postorder(T,  index);
	 
	
} 

//先序遍历建立二叉树 
void CreateBTree(BTree &T){
	ElemType ch;
	cin>>ch;
	
	//如果没有左右孩子，就输入*结束这一个节点，进入其他节点继续创建 
	if(ch == '*'){
		T = NULL;
			
	}else{
		T = (BTree)malloc(sizeof(BTNode));
		T->data = ch;
		
		cout<<"  "<<ch<<"是否有左孩子，如果有就直接输入数据，无则输入*"<<endl;
		CreateBTree(T->lchild);
		
		cout<<"  "<<ch<<"是否有右孩子，如果有就直接输入数据，无则输入*"<<endl;
		CreateBTree(T->rchild);
		
	}
}

//访问函数 
void visit(BTree T){
	cout<<T->data;
}

//先序遍历 
void preorder(BTree p, int k){
	if(p != NULL){
		++n;
		if(n == k){
			cout<<"第"<<k<<"个位置是"<<p->data<<endl; 
		}
		
		preorder(p->lchild, k);
		preorder(p->rchild, k); 
	}
}

//中序遍历
void inorder(BTree p, int k){ 
	if(p != NULL){
	 
		
		inorder(p->lchild, k);
		++n;
		
		if(n == k){
			cout<<"第"<<k<<"个位置是"<<p->data<<endl; 
		}
		inorder(p->rchild, k);
	}
} 

//后序遍历
void postorder(BTree p, int k){
	if(p != NULL){
	
	
		postorder(p->lchild, k);
		postorder(p->rchild, k);	
		++n;
		
		if(n == k){
			cout<<"第"<<k<<"个位置是"<<p->data<<endl; 
		}
	} 
} 
