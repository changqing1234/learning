#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define Stack_Init_Size 20

typedef int Status;
typedef int SElemType;

typedef struct SqStack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackEmpty(SqStack S);
void conversion();

int main(){
	
    conversion();
}

Status InitStack(SqStack &S)
//��ʼ��ջ 
{
  S.base=(int *)malloc(Stack_Init_Size * sizeof(int));
  if(!S.base) exit (OVERFLOW);
  S.top=S.base;
  S.stacksize=Stack_Init_Size;
  return OK;
}

Status Push(SqStack &S, SElemType e)
//��ջ 
{
   *S.top=e;
   S.top++;
   return OK;
} 

Status Pop(SqStack &S, SElemType &e)
//��ջ 
{
  if (S.top == S.base) return ERROR;
  {
	  --S.top;
	  e = *S.top; 
  }
  
  return OK;
}

Status StackEmpty(SqStack S)
//�ж��Ƿ�Ϊ��ջ 
{
  if (S.top == S.base) 
  {
	  return OK;
  }
  else 
    return ERROR;
}

void conversion(){
   SqStack S;
	int N, e;
	
   InitStack(S);
   
   cout<< "����һ��ʮ��������:\n";
   
   cin >> N;
   while (N)
   {
     Push(S, N % 8);
     N = N / 8;
   }
   cout<<"�õ��İ˽�����Ϊ:"<<endl;
   
   while (!StackEmpty(S))
   {
     Pop(S,e);
     cout<<e;
   }  
   cout<<endl;

}
