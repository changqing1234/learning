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
	struct ArcNode *next;	//指向下一个顶点的位置 
	int info; 	//边的权值等信息 
	
}ArcNode, *LinkNode;

//顶点信息，包含了顶点的数值和顶点指向的信息(单链表) 
typedef struct{
	ElemType data; //数据域 
	LinkNode firstarc; //指向第一个关系顶点 
	
}VNode;

//图的定义 
typedef struct{
	VNode adjlist[maxSize];  //邻接表(数组的元素是单链表) 
	int n; //顶点数 
	int e; //边数 
}AGraph;

//创建一个图 
void create(AGraph &G);
//添加图的关系
void relation(AGraph &G);
//添加链表顶点
void add(LinkNode &firstarc, int value);
//打印图的数据 
void print(AGraph G);
//打印图的关系
void printRelation(AGraph G); 


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
	
	
} 

//创建一个图，这个图所有顶点之间还没有任何的关系 
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
	
	cout<<"请输入你想添加关系的顶点号"<<endl;
	cin>>a;
	
	if(a >=0 && a<G.n){
		cout<<"请输入"<<a<<"的相邻顶点号，回车之后ctrl+z结束"<<endl;
		 while(scanf("%d", &b) != EOF){
		 	add(G.adjlist[a].firstarc,  b);
		 	G.e++;
		 	
		 }
		 cout<<"添加关系成功"<<endl;
		 
	}else{
		cout<<"找不到顶点"<<endl; 
	}
	
	
} 

//打印关系
void printRelation(AGraph G){
	
	if(G.n != 0){
		cout<<"\n图的关系如下:"<<endl;
		
		for(int i=0; i<G.n; i++){
			cout<<i<<"的相邻顶点为："; 
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

//添加链表顶点
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

