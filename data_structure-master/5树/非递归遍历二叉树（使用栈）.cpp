#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40
 //使用非递归方式实现遍历算法 
//二叉树的节点定义 ，二叉链表格式 
typedef struct BTNode{
	ElemType data;		   //本节点数据域 
	struct BTNode *lchild; //指向左孩子的指针 
	struct BTNode *rchild; //指向右孩子的指针 
}BTNode, *BTree;

//先序遍历建立二叉树 
void CreateBTree(BTree &T);

//访问函数 
void visit(BTree &T);

//先序遍历 
void preorder(BTree &bt);

//中序遍历
void inorder(BTree &bt);

//后序遍历
void postorder(BTree &bt);

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
	
	cout<<"\n后序遍历结果如下"<<endl;
	postorder(T);
	
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
void visit(BTree &T){
	cout<<T->data;
}

//先序非递归遍历 
void preorder(BTree &bt){
	if(bt != NULL){
		BTree  Stack[maxSize];
		int top = -1;
		BTree p;
		
		//根节点进栈 
		Stack[++top] = bt;
		
		while(top != -1){ //空栈就退出 
			//栈顶节点出栈 ，并遍历栈顶节点 
			p = Stack[top--];
			visit(p);
			
			//右孩子进栈 
			if(p->rchild != NULL){
				Stack[++top] = p->rchild;
			}
			
			//左孩子进栈 
			if(p->lchild != NULL){
				Stack[++top] =  p->lchild;
			}
		}
		
	}else{
		cout<<"空树"<<endl; 
	}
}

//中序非递归遍历
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

//后序非递归遍历
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
		cout<<"空树"<<endl; 
	}
} 


