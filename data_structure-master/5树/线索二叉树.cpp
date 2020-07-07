#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40

//二叉树的节点定义 ，二叉链表格式 
typedef struct BTNode{
	ElemType data;	
	int ltag, rtag;	  //线索标记 
	struct BTNode *lchild; //指向左孩子的指针 
	struct BTNode *rchild; //指向右孩子的指针 
}BTNode, *BTree;

//先序遍历建立二叉树 
void CreateBTree(BTree &T);

//访问函数 
void visit(BTree &T);

//先序遍历 
void preorder(BTree &p);

//中序遍历
void inorder(BTree &p);

//中序线索化递归算法 
void InThread(BTree p, BTree &pre); 

//二叉树线索化 
void createInThread(BTree root); 

//由根节点求出中序序列下的第一个节点 
BTree first(BTree p);

//求后继节点 
BTree next(BTree p);

int main(void){
	BTree T;
	cout<<"以先序遍历进行创建二叉树"<<endl;
	cout<<"请输入，以*键结束"<<endl;
	
	//先序建立二叉树 
	CreateBTree(T);
	
	cout<<"\n先序遍历结果如下: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"\n中序遍历结果如下:"<<endl;
	inorder(T);
	cout<<endl;
	
	//中序遍历建立中序线索二叉树 
	createInThread(T);
	
	cout<<"\n线索后的中序遍历如下："<<endl; 
	
	//遍历单链表 
	for(BTree p= first(T); p != NULL; p=next(p)){
		visit(p);
	}
		 
	
} 

//求中序的第一个节点 
BTree first(BTree p){
	while(p->ltag == 0){
		p = p->lchild;
	}
	
	return p;
} 

//求出后继节点 
BTree next(BTree p){
	if(p->rtag == 0){
		return first(p->rchild);
	}else{
		return p->rchild;
	}
} 

//中序线索化递归算法 
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

//中序建立线索二叉树主程序 
void createInThread(BTree root){
	BTree pre = NULL;
	if(root != NULL){
		InThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1; 
	}
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
		T->ltag = 0;
		T->rtag = 0;
		
		T->data = ch;
		
		cout<<"  "<<ch<<"是否有左孩子，如果有就直接输入数据，无则输入*"<<endl;
		CreateBTree(T->lchild);
		
		cout<<"  "<<ch<<"是否有右孩子，如果有就直接输入数据，无则输入*"<<endl;
		CreateBTree(T->rchild);
		
	}
}

//访问函数 
void visit(BTree &T){
	cout<<T->data;
}

//先序遍历 
void preorder(BTree &p){
	if(p != NULL){
		visit(p);
		preorder(p->lchild);
		preorder(p->rchild); 
	}
}

//中序遍历
void inorder(BTree &p){
	if(p != NULL){
		inorder(p->lchild);
		visit(p);
		inorder(p->rchild);
	}
} 

