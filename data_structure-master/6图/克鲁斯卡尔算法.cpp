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

typedef struct{
	int a, b; //代表着边的两个顶点
	int w; //代表着边的权值 
}Road;

int v[maxSize];		//定义并查集数组 

//创建n个顶点，顶点之间没有关系(没有边)
//创建无向图 
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
			G.edge[i][j] = INF;
		} 
	}
	
	G.e = 0;
	
}


int z = 0;
//添加顶点之间的关系
void relation(Graph &G, Road road[]){
	cout<<"请按确定的关系输入两个编号，如a b"<<endl;
	int a, b;
	cin>>a;
	cin>>b;

	int value;
		
	if(a>=0 && a<G.n && b>=0 && b<G.n && a != b){
		if(G.edge[a][b] == INF){
			cout<<"请输入"<<a<<"  到  "<<b<<"的权值"<<endl; 
			cin>>value;
			G.edge[a][b] = value;
			G.edge[b][a] = value; 
			road[z].a = a;
			road[z].b = b;
			road[z++].w = value;
			++G.e;
			cout<<"关系已建立"<<endl; 
		
		}else{
			cout<<"关系已经建立，不能重复建立"<<endl; 
		}
		
	}else{
		cout<<"编号输入有问题, 找不到数据"<<endl;
	}
} 

//打印顶点之间的关系 
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

//简单选择排序 ,每次从无序序列中找出最小(最大)的数据 
void Sort(Road road[], int n){
	int  k;
	Road temp;
	for(int i=0; i<n; i++){
		k=i;
		for(int j=i+1; j<n; j++){
			if(road[k].w > road[j].w){
				k = j;
			}
		}
		
		temp = road[k];
		road[k] =  road[i];
		road[i] =  temp;
	}
	
} 

//在并查集中查找根节点的函数(双亲存储结构) 
int getRoot(int a){
	while(a != v[a])
		a = v[a];
	return a;
}

//kruskal算法 
void Kruskal(Graph &G, int &sum, Road road[]){
	int i;
	int N, E, a, b;
	N = G.n; 
	E = G.e;
	sum = 0;
	
	//对权值进行排序 
	Sort(road, E);
	
	for(int i=0; i<N; i++)
		v[i] = i;
	
	cout<<"最小生成树如下:"<<endl; 
	for(int i=0; i<E; i++){
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		
		if(a != b){
			
			cout<<road[i].a<<"到"<<road[i].b<<"的权值为："<<road[i].w<<endl;
			v[a] =  b;
			sum += road[i].w;
			
		}
	}
}

int main(void){
	Graph G;
	create(G);
	Road road[maxSize]; //边的集合
	int flag = 1;
	int sum;
	
	while(flag){
		relation(G, road);
		cout<<"继续请输入1：结束请输入0"<<endl;
		cin>>flag;
	} 	
	
	cout<<"各节点的关系如下："<<endl;
	printRelation(G);	
	
	cout<<"边的个数为："<<G.e<<endl;
	Kruskal(G, sum, road);	
	
	cout<<"最小生成树的权值为："<<sum<<endl; 
	
} 


