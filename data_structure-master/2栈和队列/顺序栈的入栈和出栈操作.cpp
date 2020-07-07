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
	
	cout<<"请输入数据的个数";
	cin>>n;
	
	cout<<"请输入你要是输入的入栈数据: ";
	for(int i=0; i<n; i++){
		cin>>a;
		
		push(st, a);
	}
	
	print(st);

	int i= 0;

	while(pop(st, a)){
		cout<<"第"<<++i<<"个出栈数据是："<<a<<endl; 
	}
	
	
} 

//初始化栈，将栈顶指针置为-1 
void initStack(Stack &st){
	st.top = -1;
}

//打印栈中的数据 
void print(Stack st){
	cout<<"操作后的栈的数据如下:"; 
	for(int i= 0; i<=st.top; ++i){
		cout<<st.data[i]<<" ";
		
	}
	cout<<endl<<endl;
}

//判断栈是否为空 
int isEmpty(Stack st){
	if(st.top == -1){
		return 1;
	}
	else{
		return 0;
	}
	
}

//进栈 
int push(Stack &st, ElemType x){
	if(st.top != maxSize-1){
		st.data[++st.top] = x;
		return 1;
	}
	return 0;
}

//出栈 
int pop(Stack &st, ElemType &x){
	if(!isEmpty(st) ){
		x = st.data[st.top--];
		return 1;
	}
	
	return 0;
}
