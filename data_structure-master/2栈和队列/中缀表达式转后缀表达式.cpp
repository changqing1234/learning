#include<stdio.h>
#include<iostream>
#include<string.h>
using  namespace std;
typedef char ElemType;
#define maxSize 40

//���׺���ʽ�����ݱ�����10������� 

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
	
	//������ջ 
	initStack(st);
	cout<<"��������ʽ"<<endl;
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


//��׺���ʽ���׺���ʽ
char* getString(Stack &st, char str1[], char str2[]){
	int length;
	int j = 0;
	length = strlen(str1);
	for(int i=0; i<length; i++){
		
		//��������֣�ֱ��д����ʽ2�� 
		if(str1[i] >= '0' && str1[i] <= '9'){
			str2[j++]= str1[i];
			
			
			//���ջ���������ţ�����ѡ�����ַ��������ţ������ջ����ֱ�ӽ���������ջ 
		}else if(st.top == -1 || str1[i] == '(' || st.data[st.top] == '('){
					push(st, str1[i]);
					
		//�Ա����ȼ���ѹջ		
		}else if(str1[i] == ')'){
					while(st.data[st.top] != '('){
						pop(st, str2[j++]);
					} 
					
					char a;
					pop(st, a);
				}
	
		else {	
			//��ȡѡ���ַ������ȼ� 
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
