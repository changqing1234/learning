#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
#define maxSize 30
#define INF 1000

//������Ϣ���� 
typedef struct{
	int no; //������ 
	char info;//�����������Ϣ 
	ElemType data; //�������� 
	
}GNode; 

//ͼ�Ķ���(���㼯�ϼ���ϵ����) 
typedef struct{
	int edge[maxSize][maxSize]; //�ڽӾ����ʾ����֮��Ĺ�ϵ 
	int n;//������ 
	int e;//����(��ϵ��) 
	GNode  *p; //ָ�򶥵������ָ�� 
}Graph;

typedef struct{
	int a, b; //�����űߵ���������
	int w; //�����űߵ�Ȩֵ 
}Road;

int v[maxSize];		//���岢�鼯���� 

//����n�����㣬����֮��û�й�ϵ(û�б�)
//��������ͼ 
int create(Graph &G){
	int n;
	ElemType data;
	
	cout<<"��������Ҫ���ݵ����ݸ���"<<endl;
	cin>>n;
	
	G.p = (GNode*)malloc(sizeof(GNode) * n);
	G.n = n;
	cout<<"������"<<n<<"������"<<endl; 
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
//��Ӷ���֮��Ĺ�ϵ
void relation(Graph &G, Road road[]){
	cout<<"�밴ȷ���Ĺ�ϵ����������ţ���a b"<<endl;
	int a, b;
	cin>>a;
	cin>>b;

	int value;
		
	if(a>=0 && a<G.n && b>=0 && b<G.n && a != b){
		if(G.edge[a][b] == INF){
			cout<<"������"<<a<<"  ��  "<<b<<"��Ȩֵ"<<endl; 
			cin>>value;
			G.edge[a][b] = value;
			G.edge[b][a] = value; 
			road[z].a = a;
			road[z].b = b;
			road[z++].w = value;
			++G.e;
			cout<<"��ϵ�ѽ���"<<endl; 
		
		}else{
			cout<<"��ϵ�Ѿ������������ظ�����"<<endl; 
		}
		
	}else{
		cout<<"�������������, �Ҳ�������"<<endl;
	}
} 

//��ӡ����֮��Ĺ�ϵ 
void printRelation(Graph &G){
	for(int i=0; i<G.n; i++){
		cout<<i<<"���ڽӵ����£�"<<endl<<endl; 
		for(int j=0; j<G.n; j++){
			if(G.edge[i][j] != INF){
				cout<<"    "<<i<<"��"<<j<<"��ȨֵΪ��"<<G.edge[i][j]<<endl;
				
			}
		}
		
		cout<<endl; 
	}
} 

//��ѡ������ ,ÿ�δ������������ҳ���С(���)������ 
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

//�ڲ��鼯�в��Ҹ��ڵ�ĺ���(˫�״洢�ṹ) 
int getRoot(int a){
	while(a != v[a])
		a = v[a];
	return a;
}

//kruskal�㷨 
void Kruskal(Graph &G, int &sum, Road road[]){
	int i;
	int N, E, a, b;
	N = G.n; 
	E = G.e;
	sum = 0;
	
	//��Ȩֵ�������� 
	Sort(road, E);
	
	for(int i=0; i<N; i++)
		v[i] = i;
	
	cout<<"��С����������:"<<endl; 
	for(int i=0; i<E; i++){
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		
		if(a != b){
			
			cout<<road[i].a<<"��"<<road[i].b<<"��ȨֵΪ��"<<road[i].w<<endl;
			v[a] =  b;
			sum += road[i].w;
			
		}
	}
}

int main(void){
	Graph G;
	create(G);
	Road road[maxSize]; //�ߵļ���
	int flag = 1;
	int sum;
	
	while(flag){
		relation(G, road);
		cout<<"����������1������������0"<<endl;
		cin>>flag;
	} 	
	
	cout<<"���ڵ�Ĺ�ϵ���£�"<<endl;
	printRelation(G);	
	
	cout<<"�ߵĸ���Ϊ��"<<G.e<<endl;
	Kruskal(G, sum, road);	
	
	cout<<"��С��������ȨֵΪ��"<<sum<<endl; 
	
} 


