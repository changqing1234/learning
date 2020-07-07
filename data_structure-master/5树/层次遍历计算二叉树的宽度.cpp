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

//建立非循环队列，给队里的节点中包含了层次的大小，可以统计相同层次的个数来计算宽度 
typedef struct{
	BTree p;
	int lno;
}st; 

//先序遍历建立二叉树 
void CreateBTree(BTree &T);

//访问函数 
void visit(BTree &T);

//先序遍历 
void preorder(BTree &p);

//求树的宽度
int maxNode(BTree T); 

int main(void){
	BTree T;
	cout<<"以先序遍历进行创建二叉树"<<endl;
	cout<<"请输入，以*键结束"<<endl;
	
	//先序建立二叉树 
	CreateBTree(T);
	
	cout<<"\n先序遍历结果如下: "<<endl; 
	preorder(T);
	cout<<endl;
	
	cout<<"二叉树的最大宽度为："<<maxNode(T)<<endl; 
	 
	
} 

int maxNode(BTree T){
	//建立非循环队列 
	st que[maxSize];
	int front, rear;
	int Lno, i, j, n, max;
	
	front = rear = 0;
	BTree q;
	
	if(T != NULL){
		//根节点进入队列 
		++rear;
		 que[rear].p= T;
		 que[rear].lno = 1;
		 
		 //队头节点出队，但是数据仍在内存，知识队头指针改变了而已，最后rear和front相遇，LNo为最大的层次 
		 while(front != rear){
		 	++front;
		 	q = que[front].p;
		 	//获取当前的层次号 
		 	Lno =  que[front].lno;
		 	
		 	//左子树进队 
		 	if(q->lchild != NULL){
		 		++rear;
		 		que[rear].p = q->lchild;
		 		que[rear].lno = Lno+1;
			 }
			 
			//右子树进队 
			if(q->rchild != NULL){
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = Lno+1;
			}
		 }
		 
		 // 统计0到Lno各层次的数量，找出最大值就是树的宽度 
		 max  = 0;
		 for(int i=0; i<=Lno; ++i){
		 	n = 0;
		 	for(int j=0; j<=rear; ++j){
		 		if(que[j].lno == i){
		 			++n; 
				 }
			 }
			 
			 if(n > max){
			 	max = n;
			 } 
		 }
		 
		 return max;
		 
	}else{
		//空树，直接返回0 
		return 0;
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

