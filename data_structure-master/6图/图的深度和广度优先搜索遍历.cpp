#include<stdio.h>
#include<iostream>
#include<malloc.h>
//图的邻接表存储 

using namespace std;
typedef int ElemType;
#define maxSize 30

//指向的位置信息(关系表) 
typedef struct ArcNode{
	int adjvex;		//标识该节点的位置 
	struct ArcNode *next;	//指向下一个位置 
	int info; 	//边的其他信息 
	
}ArcNode, *LinkNode;

//节点信息，包含了节点的数值和节点指向的信息(单链表) 
typedef struct{
	ElemType data; //数据域 
	LinkNode firstarc; //指向第一个关系节点 
	
}VNode;

//图的定义 
typedef struct{
	VNode adjlist[maxSize];  //邻接表,数组中的每个数据元素一个嵌入单链表 
	int n; //顶点数 
	int e; //边数 
}AGraph;

//创建一个图 
void create(AGraph &G);
//添加图的关系
void relation(AGraph &G);
//添加链表节点
void add(LinkNode &firstarc, int value);
//打印图的数据 
void print(AGraph G);
//打印图的关系
void printRelation(AGraph G); 

//图的深度优先搜索遍历算法 
void DFS(AGraph G, int v); 

//标记节点是否被访问过 
int visit[maxSize] = {0};

//图的广度优先搜索算法 
void BFS(AGraph G, int v);

int main(void){
	AGraph G;
	int flag = 1;
	 
	create(G);
	
	while(flag){
		
		relation(G);	
		cout<<endl;
		cout<<"继续请输入1, 退出请输0"<<endl;
	
		cin>>flag;
	}

	
	print(G);
	printRelation(G);
	
	cout<<"请输入你要访问的顶点编号"<<endl;
	cin>>flag;
	
	cout<<"该顶点的深度优先遍历结果如下："<<endl;
	DFS(G, flag);
	cout<<endl<<endl;
	
	int i=G.n;
	while(--i){
		visit[i] = 0;
	} 
	cout<<"该顶点的广度优先遍历结果如下："<<endl;
	BFS(G, flag);
	 	
} 

//图的深度优先搜索遍历算法 ,v代表着顶点号 
void DFS(AGraph G, int v){
	ArcNode *p;
	
	//访问第一个节点，并标记成已访问 
	cout<<G.adjlist[v].data<<" ";
	visit[v] = 1;
	
	//获取邻接表表头，即第一个邻接节点的地址 
	p = G.adjlist[v].firstarc;
	
	while(p != NULL){
		//递归访问，下一个顶点非空，就继续访问 
		if(visit[p->adjvex] == 0){
			DFS(G, p->adjvex);
		}
		
		p= p->next;
	}	
}

//图的广度优先搜索遍历算法 
void BFS(AGraph G, int v){
	LinkNode p;
	int que[maxSize], front, rear;
	front =  rear = 0;
	int j;
	
	//第一个顶点访问后，进队 
	cout<<G.adjlist[v].data<<" ";
	rear = (rear+1)%maxSize;
	que[rear] = v;
	
	while(rear != front){
		
		//都是先访问再判断是否有邻接点，如果有就进队，否则继续出队 
		//对顶出队，j用来记录队顶的编号，用来判断队顶是否还有邻接 
		front = (front+1)%maxSize;
		j = que[front];
		
		//获得该节点的邻接表，如果邻接表不空，就进行访问，标记成已访问，再将节点进行入队操作。循环执行，知道队列为空 
		p = G.adjlist[j].firstarc;
		
		while(p != NULL){
			if(visit[p->adjvex] ==  0){
				cout<<G.adjlist[p->adjvex].data<<" ";
				//标记成已访问
				visit[p->adjvex] = 1;
				
				//将已经访问过的节点进队 
				rear = (rear+1)%maxSize;
				que[rear] = p->adjvex; 
			}
			
			//指向下一条邻接边,直到将邻接的顶点全部入队完，指针为空，退出循环 
			p =  p->next;
		} 
		
	}
}

//创建一个图 
void create(AGraph &G){
	G.n = 0;
	
	cout<<"请输入数据的个数："<<endl;
	
	 cin >> G.n;
	 cout<<"请输入"<<G.n<<"个数据"<<endl; 
	 for(int i=0; i<G.n; i++){
	 	cin>>G.adjlist[i].data;
	 	G.adjlist[i].firstarc = NULL;
	 } 
	 
}

//添加图的关系
void relation(AGraph &G){ 
	int a;
	int b;
	int i=0;
	
	cout<<"请输入你想添加关系的节点号"<<endl;
	cin>>a;
	
	if(a >=0 && a<G.n){
		cout<<"请输入"<<a<<"的相邻顶点号，然后回车之后ctrl+z结束"<<endl;
		 while(scanf("%d", &b) != EOF){
		 	add(G.adjlist[a].firstarc,  b);
		 	G.e++;
		 	
		 }
		 cout<<"添加关系成功"<<endl;
		 
	}else{
		cout<<"找不到节点"<<endl; 
	}
	
	
} 

//打印关系
void printRelation(AGraph G){
	
	if(G.n != 0){
		cout<<"\n图的关系如下:"<<endl;
		
		for(int i=0; i<G.n; i++){
			cout<<i<<"的相邻节点为："; 
			LinkNode p = G.adjlist[i].firstarc;
		
			while(p){
				cout<<p->adjvex<<" "; 
				p = p->next;
			}
			cout<<endl<<endl; 
			
		}
		
	}else{
		cout<<"空图"<<endl;
	}
} 

//添加单链表节点
void add(LinkNode &firstarc, int value){
	LinkNode s;
	s = (LinkNode)malloc(sizeof(ArcNode));
	s->adjvex = value; 
	
	
 	if(firstarc == NULL){
 		s->next = NULL; 
 		firstarc = s;
				
	 }else{
	 		s->next = firstarc->next;
			firstarc->next = s;
		
	 }	
	
} 
//打印图的数据 
void print(AGraph G){
	cout<<"图的数据如下："<<endl;
	for(int i=0; i<G.n; i++){
		cout<<G.adjlist[i].data<<" ";
	}
	
	cout<<endl; 
}



