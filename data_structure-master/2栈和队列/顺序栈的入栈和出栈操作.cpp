#include<stdio.h>
#include<iostream>
using  namespace std;
typedef int ElemType;
#define maxSize 20

typedef struct {
	ElemType data[maxSize];
	int top;
	
}Stack;

int push(Stack &st, ElemType x);
int pop(Stack &st, ElemType& x);
int isEmpty(Stack st);
void initStack(Stack &st);
void print(Stack st);

int main(void){
	Stack st;
	initStack(st);
	int n, a; 
	
	cout<<"���������ݵĸ���";
	cin>>n;
	
	cout<<"��������Ҫ���������ջ����: ";
	for(int i=0; i<n; i++){
		cin>>a;
		
		push(st, a);
	}
	
	print(st);

	int i= 0;

	while(pop(st, a)){
		cout<<"��"<<++i<<"����ջ�����ǣ�"<<a<<endl; 
	}
	
	
} 

//��ʼ��ջ����ջ��ָ����Ϊ-1 
void initStack(Stack &st){
	st.top = -1;
}

//��ӡջ�е����� 
void print(Stack st){
	cout<<"�������ջ����������:"; 
	for(int i= 0; i<=st.top; ++i){
		cout<<st.data[i]<<" ";
		
	}
	cout<<endl<<endl;
}

//�ж�ջ�Ƿ�Ϊ�� 
int isEmpty(Stack st){
	if(st.top == -1){
		return 1;
	}
	else{
		return 0;
	}
	
}

//��ջ 
int push(Stack &st, ElemType x){
	if(st.top != maxSize-1){
		st.data[++st.top] = x;
		return 1;
	}
	return 0;
}

//��ջ 
int pop(Stack &st, ElemType &x){
	if(!isEmpty(st) ){
		x = st.data[st.top--];
		return 1;
	}
	
	return 0;
}
