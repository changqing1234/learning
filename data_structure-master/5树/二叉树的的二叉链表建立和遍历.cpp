#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef char ElemType;
#define maxSize 40

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
void preorder(BTree &p);

//中序遍历
void inorder(BTree &p);

//后序遍历
void postorder(BTree &p);

//层次遍历
void level(BTree &p); 

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
	
	cout<<"\n层次遍历的结果如下："<<endl;;
	level(T);
	 
	
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

//后序遍历
void postorder(BTree &p){
	if(p != NULL){
		postorder(p->lchild);
		postorder(p->rchild);
		visit(p);
	} 
} 

//层次遍历,首先将根节点入队，然后不断的将左右子树入队，然后再出队，队列空时就是层次结构。 
void level(BTree &p){
	int front, rear;
	BTree queue[maxSize];
	BTree q;
	
	rear = front = 0;
	
	if(p != NULL){
		//根节点入队 
		rear = (rear+1)%maxSize;
		queue[rear] = p;
		
		while(front != rear){
			//队头出队 
			front = (front+1)%maxSize;
			q = queue[front];
			visit(q);
			
			//左孩树入队 
			if(q->lchild != NULL){
				rear = (rear+1)%maxSize;
				queue[rear] = q->lchild;
			}
			
			//右子树入队 
			if(q->rchild != NULL){
				rear = (rear+1)%maxSize;
				queue[rear] = q->rchild;
			}
		}
	}	
	
	
} 
