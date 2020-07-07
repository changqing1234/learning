#include<stdio.h>
#include<iostream>
#include<string.h>
using  namespace std;
typedef char ElemType;
#define maxSize 40

//求后缀表达式，数据必须是10内数相乘 

typedef struct {
	ElemType data[maxSize];
	int top;
	
}Stack;

int push(Stack &st, ElemType x);
int pop(Stack &st, ElemType &x);
int isEmpty(Stack st);
void initStack(Stack &st);
void print(Stack st);
int getPriorty(char op); 
char* getString(Stack &st, char str1[], char str2[]);
int calculate(char str[]);

int main(void){
	Stack st;
	char str1[30];
	char str2[30];
	
	//操作符栈 
	initStack(st);
	cout<<"请输入表达式"<<endl;
	gets(str1);
	
	char *str = getString(st, str1, str2);
	puts(str);
	
	
} 

int getPriorty(char op){
	switch(op){
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
		
	}
	
}


//中缀表达式求后缀表达式
char* getString(Stack &st, char str1[], char str2[]){
	int length;
	int j = 0;
	length = strlen(str1);
	for(int i=0; i<length; i++){
		
		//如果是数字，直接写入表达式2中 
		if(str1[i] >= '0' && str1[i] <= '9'){
			str2[j++]= str1[i];
			
			
			//如果栈顶是左括号，或则选定的字符是左括号，或则空栈，都直接将操作符进栈 
		}else if(st.top == -1 || str1[i] == '(' || st.data[st.top] == '('){
					push(st, str1[i]);
					
		//对比优先级再压栈		
		}else if(str1[i] == ')'){
					while(st.data[st.top] != '('){
						pop(st, str2[j++]);
					} 
					
					char a;
					pop(st, a);
				}
	
		else {	
			//获取选定字符的优先级 
		 	int prior = getPriorty(str1[i]);
		 
			 while(prior <= getPriorty(st.top) && st.top >= -1){
			 	pop(st, str2[j++]);
			 	
			 }
			 
			 push(st, str1[i]);	 
			 
		 }
		 
	}
	
	while(st.top != -1){
		pop(st, str2[j++]);
	}
	
	return str2;
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
