#include<stdio.h>
#include<iostream>
#include<string.h> 
using  namespace std;

typedef char ElemType;
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
void judge(Stack &st, char str[]);

int main(void){
	Stack st;
	char str[maxSize];
	
	initStack(st);
	
	
	cout<<"请输入你要输入的字符串"<<endl;
	 gets(str);
	 
	 judge(st, str);
	
} 

//判断括号是否匹配 
void judge(Stack &st, char str[]){
	char data;
	int length = strlen(str);
	if(length % 2 != 0){
		cout<<"不匹配"<<endl; 
		
	}else{
		
		for(int i=0; i<length; i++){
			
			//空栈，就将数据压如栈中，下一次跟栈中的数据进行比较 
			if(st.top == -1){
				push(st, str[i]);
			}
			else{
					//括号匹配就弹出栈中的数据 
					if((str[i] == ')'  && st.data[st.top] == '(' )  || (str[i] == ']' && st.data[st.top] == '['
					)|| ( str[i] == '}'  && st.data[st.top] == '{') ){
					pop(st, data);
					
				}else{
					//不匹配就进行压栈，等待后面的括号 
					push(st, str[i]);
				}
			}	
		}
		
		
		//如果栈是空的，说明括号都成功匹配了 
		if(st.top == -1){
			cout<<"符号匹配"<<endl;
		}else{
			cout<<"符号不匹配"<<endl; 
		}
		
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
