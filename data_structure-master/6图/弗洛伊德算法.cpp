#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;
typedef int ElemType;
#define maxSize 30
#define INF 1000

//顶点信息定义 
typedef struct{
	int no; //顶点编号 
	char info;//顶点的其他信息 
	ElemType data; //顶点数据 
	
}GNode; 

//图的定义(顶点集合及关系集合) 
typedef struct{
	int edge[maxSize][maxSize]; //邻接矩阵表示顶点之间的关系 
	int n;//顶点数 
	int e;//边数(关系数) 
	GNode  *p; //指向顶点数组的指针 
}Graph;

//创建n个顶点，顶点之间没有关系(没有边)
//创建有向图 
int create(Graph &G){
	int n;
	ElemType data;
	
	cout<<"请输入你要数据的数据个数"<<endl;
	cin>>n;
	
	G.p = (GNode*)malloc(sizeof(GNode) * n);
	G.n = n;
	cout<<"请输入"<<n<<"个数据"<<endl; 
	for(int i=0; i<n; i++){
		cin>>data;
		G.p[i].data = data;
		G.p[i].no = i; 		
		
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j){
				G.edge[i][j] = 0;
			}else{
				G.edge[i][j] = INF;
			}
			
		} 
	}
	
	G.e = 0;
	
}

//添加节点之间的关系
void relation(Graph &G){
	cout<<"请按确定的关系输入两个编号，如a b"<<endl;
	int a, b;
	cin>>a;
	cin>>b;
	int value;
		
	if(a>=0 && a<=G.n && b>=0 && b<=G.n && a != b){
		 
		if(G.edge[a][b] == INF){
			cout<<"请输入"<<a<<"  到  "<<b<<"的权值"<<endl; 
			cin>>value;
			G.edge[a][b] = value;
			++G.e;
			cout<<"关系已建立"<<endl; 
		
		}else{
			cout<<"关系已经建立，不能重复建立"<<endl; 
		}
		
	}else{
		cout<<"编号输入有问题, 找不到数据"<<endl;
	}
} 

//打印节点信息
void print(Graph &G){
	cout<<"\n节点的数据如下："<<endl;
	for(int i=0; i<G.n; i++){
		cout<<G.p[i].data<<" ";
	}
	
	cout<<endl;
} 

//打印节点之间的关系 
void printRelation(Graph &G){
	for(int i=0; i<G.n; i++){
		cout<<i<<"的邻接点如下："<<endl<<endl; 
		for(int j=0; j<G.n; j++){
			if(G.edge[i][j] != INF){
				cout<<"    "<<i<<"到"<<j<<"的权值为："<<G.edge[i][j]<<endl;
				
			}
		}
		
		cout<<endl; 
	}
} 

//弗洛伊德算法 
void Floyd(Graph &G, int A[][maxSize]){
	//各个顶点之间直接路径 
	for(int i=0; i<G.n; i++){
		for(int j=0; j<G.n; j++){
			A[i][j] = G.edge[i][j];
			
		}
	}
	
	//计算各个顶点之间的最小路径 
	for(int k=-0; k<G.n; k++)
		for(int i=0; i<G.n; i++){
			for(int j=0; j<G.n; j++){
				if(A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j];
				
			}
		}
}


int main(void){
	Graph G;
	create(G);
	int flag = 1;
	int A[maxSize][maxSize];
	
	while(flag){
		relation(G);
		cout<<"继续请输入1：结束请输入0"<<endl;
		cin>>flag;
	} 

	print(G);
	
	cout<<"各节点的关系如下："<<endl;
	printRelation(G);	
	Floyd(G, A);
	
	for(int i=0; i<G.n; i++){
		for(int j=0; j<G.n; j++){
			if(A[i][j] == INF)
				cout<<"从"<<i<<"到不了"<<j<<endl;
			else{
				cout<<"从"<<i<<"到"<<j<<"最小路径为:"<<A[i][j]<<endl<<endl;
			}
		}
	} 
	
	
	
	
} 

