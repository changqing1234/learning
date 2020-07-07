#include<stdio.h>
#include<iostream>
#include<malloc.h>
//ͼ���ڽӱ�洢 

using namespace std;
typedef int ElemType;
#define maxSize 30

//ָ���λ����Ϣ(��ϵ��) 
typedef struct ArcNode{
	int adjvex;		//��ʶ�ýڵ��λ�� 
	struct ArcNode *next;	//ָ����һ��λ�� 
	int info; 	//�ߵ�������Ϣ 
	
}ArcNode, *LinkNode;

//�ڵ���Ϣ�������˽ڵ����ֵ�ͽڵ�ָ�����Ϣ(������) 
typedef struct{
	ElemType data; //������ 
	LinkNode firstarc; //ָ���һ����ϵ�ڵ� 
	
}VNode;

//ͼ�Ķ��� 
typedef struct{
	VNode adjlist[maxSize];  //�ڽӱ�,�����е�ÿ������Ԫ��һ��Ƕ�뵥���� 
	int n; //������ 
	int e; //���� 
}AGraph;

//����һ��ͼ 
void create(AGraph &G);
//���ͼ�Ĺ�ϵ
void relation(AGraph &G);
//�������ڵ�
void add(LinkNode &firstarc, int value);
//��ӡͼ������ 
void print(AGraph G);
//��ӡͼ�Ĺ�ϵ
void printRelation(AGraph G); 

//ͼ������������������㷨 
void DFS(AGraph G, int v); 

//��ǽڵ��Ƿ񱻷��ʹ� 
int visit[maxSize] = {0};

//ͼ�Ĺ�����������㷨 
void BFS(AGraph G, int v);

int main(void){
	AGraph G;
	int flag = 1;
	 
	create(G);
	
	while(flag){
		
		relation(G);	
		cout<<endl;
		cout<<"����������1, �˳�����0"<<endl;
	
		cin>>flag;
	}

	
	print(G);
	printRelation(G);
	
	cout<<"��������Ҫ���ʵĶ�����"<<endl;
	cin>>flag;
	
	cout<<"�ö����������ȱ���������£�"<<endl;
	DFS(G, flag);
	cout<<endl<<endl;
	
	int i=G.n;
	while(--i){
		visit[i] = 0;
	} 
	cout<<"�ö���Ĺ�����ȱ���������£�"<<endl;
	BFS(G, flag);
	 	
} 

//ͼ������������������㷨 ,v�����Ŷ���� 
void DFS(AGraph G, int v){
	ArcNode *p;
	
	//���ʵ�һ���ڵ㣬����ǳ��ѷ��� 
	cout<<G.adjlist[v].data<<" ";
	visit[v] = 1;
	
	//��ȡ�ڽӱ��ͷ������һ���ڽӽڵ�ĵ�ַ 
	p = G.adjlist[v].firstarc;
	
	while(p != NULL){
		//�ݹ���ʣ���һ������ǿգ��ͼ������� 
		if(visit[p->adjvex] == 0){
			DFS(G, p->adjvex);
		}
		
		p= p->next;
	}	
}

//ͼ�Ĺ���������������㷨 
void BFS(AGraph G, int v){
	LinkNode p;
	int que[maxSize], front, rear;
	front =  rear = 0;
	int j;
	
	//��һ��������ʺ󣬽��� 
	cout<<G.adjlist[v].data<<" ";
	rear = (rear+1)%maxSize;
	que[rear] = v;
	
	while(rear != front){
		
		//�����ȷ������ж��Ƿ����ڽӵ㣬����оͽ��ӣ������������ 
		//�Զ����ӣ�j������¼�Ӷ��ı�ţ������ж϶Ӷ��Ƿ����ڽ� 
		front = (front+1)%maxSize;
		j = que[front];
		
		//��øýڵ���ڽӱ�����ڽӱ��գ��ͽ��з��ʣ���ǳ��ѷ��ʣ��ٽ��ڵ������Ӳ�����ѭ��ִ�У�֪������Ϊ�� 
		p = G.adjlist[j].firstarc;
		
		while(p != NULL){
			if(visit[p->adjvex] ==  0){
				cout<<G.adjlist[p->adjvex].data<<" ";
				//��ǳ��ѷ���
				visit[p->adjvex] = 1;
				
				//���Ѿ����ʹ��Ľڵ���� 
				rear = (rear+1)%maxSize;
				que[rear] = p->adjvex; 
			}
			
			//ָ����һ���ڽӱ�,ֱ�����ڽӵĶ���ȫ������ָ꣬��Ϊ�գ��˳�ѭ�� 
			p =  p->next;
		} 
		
	}
}

//����һ��ͼ 
void create(AGraph &G){
	G.n = 0;
	
	cout<<"���������ݵĸ�����"<<endl;
	
	 cin >> G.n;
	 cout<<"������"<<G.n<<"������"<<endl; 
	 for(int i=0; i<G.n; i++){
	 	cin>>G.adjlist[i].data;
	 	G.adjlist[i].firstarc = NULL;
	 } 
	 
}

//���ͼ�Ĺ�ϵ
void relation(AGraph &G){ 
	int a;
	int b;
	int i=0;
	
	cout<<"������������ӹ�ϵ�Ľڵ��"<<endl;
	cin>>a;
	
	if(a >=0 && a<G.n){
		cout<<"������"<<a<<"�����ڶ���ţ�Ȼ��س�֮��ctrl+z����"<<endl;
		 while(scanf("%d", &b) != EOF){
		 	add(G.adjlist[a].firstarc,  b);
		 	G.e++;
		 	
		 }
		 cout<<"��ӹ�ϵ�ɹ�"<<endl;
		 
	}else{
		cout<<"�Ҳ����ڵ�"<<endl; 
	}
	
	
} 

//��ӡ��ϵ
void printRelation(AGraph G){
	
	if(G.n != 0){
		cout<<"\nͼ�Ĺ�ϵ����:"<<endl;
		
		for(int i=0; i<G.n; i++){
			cout<<i<<"�����ڽڵ�Ϊ��"; 
			LinkNode p = G.adjlist[i].firstarc;
		
			while(p){
				cout<<p->adjvex<<" "; 
				p = p->next;
			}
			cout<<endl<<endl; 
			
		}
		
	}else{
		cout<<"��ͼ"<<endl;
	}
} 

//��ӵ�����ڵ�
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
//��ӡͼ������ 
void print(AGraph G){
	cout<<"ͼ���������£�"<<endl;
	for(int i=0; i<G.n; i++){
		cout<<G.adjlist[i].data<<" ";
	}
	
	cout<<endl; 
}



