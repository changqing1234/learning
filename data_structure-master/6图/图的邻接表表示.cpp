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
	struct ArcNode *next;	//ָ����һ�������λ�� 
	int info; 	//�ߵ�Ȩֵ����Ϣ 
	
}ArcNode, *LinkNode;

//������Ϣ�������˶������ֵ�Ͷ���ָ�����Ϣ(������) 
typedef struct{
	ElemType data; //������ 
	LinkNode firstarc; //ָ���һ����ϵ���� 
	
}VNode;

//ͼ�Ķ��� 
typedef struct{
	VNode adjlist[maxSize];  //�ڽӱ�(�����Ԫ���ǵ�����) 
	int n; //������ 
	int e; //���� 
}AGraph;

//����һ��ͼ 
void create(AGraph &G);
//���ͼ�Ĺ�ϵ
void relation(AGraph &G);
//���������
void add(LinkNode &firstarc, int value);
//��ӡͼ������ 
void print(AGraph G);
//��ӡͼ�Ĺ�ϵ
void printRelation(AGraph G); 


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
	
	
} 

//����һ��ͼ�����ͼ���ж���֮�仹û���κεĹ�ϵ 
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
	
	cout<<"������������ӹ�ϵ�Ķ����"<<endl;
	cin>>a;
	
	if(a >=0 && a<G.n){
		cout<<"������"<<a<<"�����ڶ���ţ��س�֮��ctrl+z����"<<endl;
		 while(scanf("%d", &b) != EOF){
		 	add(G.adjlist[a].firstarc,  b);
		 	G.e++;
		 	
		 }
		 cout<<"��ӹ�ϵ�ɹ�"<<endl;
		 
	}else{
		cout<<"�Ҳ�������"<<endl; 
	}
	
	
} 

//��ӡ��ϵ
void printRelation(AGraph G){
	
	if(G.n != 0){
		cout<<"\nͼ�Ĺ�ϵ����:"<<endl;
		
		for(int i=0; i<G.n; i++){
			cout<<i<<"�����ڶ���Ϊ��"; 
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

//���������
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

