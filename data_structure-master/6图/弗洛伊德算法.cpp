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
			if(i == j){
				G.edge[i][j] = 0;
			}else{
				G.edge[i][j] = INF;
			}
			
		} 
	}
	
	G.e = 0;
	
}

//��ӽڵ�֮��Ĺ�ϵ
void relation(Graph &G){
	cout<<"�밴ȷ���Ĺ�ϵ����������ţ���a b"<<endl;
	int a, b;
	cin>>a;
	cin>>b;
	int value;
		
	if(a>=0 && a<=G.n && b>=0 && b<=G.n && a != b){
		 
		if(G.edge[a][b] == INF){
			cout<<"������"<<a<<"  ��  "<<b<<"��Ȩֵ"<<endl; 
			cin>>value;
			G.edge[a][b] = value;
			++G.e;
			cout<<"��ϵ�ѽ���"<<endl; 
		
		}else{
			cout<<"��ϵ�Ѿ������������ظ�����"<<endl; 
		}
		
	}else{
		cout<<"�������������, �Ҳ�������"<<endl;
	}
} 

//��ӡ�ڵ���Ϣ
void print(Graph &G){
	cout<<"\n�ڵ���������£�"<<endl;
	for(int i=0; i<G.n; i++){
		cout<<G.p[i].data<<" ";
	}
	
	cout<<endl;
} 

//��ӡ�ڵ�֮��Ĺ�ϵ 
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

//���������㷨 
void Floyd(Graph &G, int A[][maxSize]){
	//��������֮��ֱ��·�� 
	for(int i=0; i<G.n; i++){
		for(int j=0; j<G.n; j++){
			A[i][j] = G.edge[i][j];
			
		}
	}
	
	//�����������֮�����С·�� 
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
		cout<<"����������1������������0"<<endl;
		cin>>flag;
	} 

	print(G);
	
	cout<<"���ڵ�Ĺ�ϵ���£�"<<endl;
	printRelation(G);	
	Floyd(G, A);
	
	for(int i=0; i<G.n; i++){
		for(int j=0; j<G.n; j++){
			if(A[i][j] == INF)
				cout<<"��"<<i<<"������"<<j<<endl;
			else{
				cout<<"��"<<i<<"��"<<j<<"��С·��Ϊ:"<<A[i][j]<<endl<<endl;
			}
		}
	} 
	
	
	
	
} 

