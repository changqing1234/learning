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
			G.edge[i][j] = INF;
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
			G.edge[b][a] = value; 
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

//����ķ�㷨
void Prim(Graph &G, int	v0, int &sum){
	int lowcost[maxSize];//��ǰ�������������������СȨֵ
	int vset[maxSize]; //��Ƕ����Ƿ񱻲������� 
	int v; //ʼ��ָ��ǰ�ս��������¶���
	int k;
	int min;
	
	for(int i=0; i<G.n; i++){
		lowcost[i] = G.edge[v0][i]; //��ȫ�����������㵽vo��Ȩֵ��ֵ��lowcost������
		vset[i] = 0; //��������Ϊ��Ϊ���� 
	} 
	
	vset[v0] = 1; //��v0�������� 
	sum = 0;
	
	for(int i=0; i<G.n-1; i++){
		min = INF; //���κ�Ȩֵ�����ֵ
		
		//�ҵ�����������СȨֵ�Ķ��� 
		for(int j=0; j<G.n; j++){
			if(vset[j] == 0 && lowcost[j] < min){
				min = lowcost[j];
				k = j; 
			} 
		
		} 
		
		//������������СȨֵ�Ķ��㲢�����У����Ϊ�Ѳ���	
		vset[k] = 1;
		v = k;
		sum += min;
		
		//���µ�ǰ����δ���붥���Ȩֵ 
		for(int i=0; i<G.n; i++){
			if(vset[i] == 0 && G.edge[v][i] < lowcost[i])
				lowcost[i] = G.edge[v][i];
		}
		
	}
	
}

int main(void){
	Graph G;
	create(G);
	int flag = 1;
	int sum;
	
	while(flag){
		relation(G);
		cout<<"����������1������������0"<<endl;
		cin>>flag;
	} 

	print(G);
	
	cout<<"���ڵ�Ĺ�ϵ���£�"<<endl;
	printRelation(G);	
	
	Prim(G, 0, sum);
	cout<<"��С��������ȨֵΪ��"<<sum<<endl; 
	
	
} 

