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
	
	
	cout<<"��������Ҫ������ַ���"<<endl;
	 gets(str);
	 
	 judge(st, str);
	
} 

//�ж������Ƿ�ƥ�� 
void judge(Stack &st, char str[]){
	char data;
	int length = strlen(str);
	if(length % 2 != 0){
		cout<<"��ƥ��"<<endl; 
		
	}else{
		
		for(int i=0; i<length; i++){
			
			//��ջ���ͽ�����ѹ��ջ�У���һ�θ�ջ�е����ݽ��бȽ� 
			if(st.top == -1){
				push(st, str[i]);
			}
			else{
					//����ƥ��͵���ջ�е����� 
					if((str[i] == ')'  && st.data[st.top] == '(' )  || (str[i] == ']' && st.data[st.top] == '['
					)|| ( str[i] == '}'  && st.data[st.top] == '{') ){
					pop(st, data);
					
				}else{
					//��ƥ��ͽ���ѹջ���ȴ���������� 
					push(st, str[i]);
				}
			}	
		}
		
		
		//���ջ�ǿյģ�˵�����Ŷ��ɹ�ƥ���� 
		if(st.top == -1){
			cout<<"����ƥ��"<<endl;
		}else{
			cout<<"���Ų�ƥ��"<<endl; 
		}
		
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
