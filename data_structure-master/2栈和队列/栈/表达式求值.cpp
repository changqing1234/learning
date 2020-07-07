#include<iostream>
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
using namespace std;
#define stackincrement 10

typedef struct{
		char *base;
		char *top;
		int stacksize;
	}stack; 

void InitStack(stack* s)
{
	(*s).base = (char* )malloc(1000 * sizeof(char));
	(*s).top = (*s).base;
}	

double calculate(stack s)
{
  if(*s.top == s.base)
    return a[0] 
	int i, j;
	stack a;
	initStack(&a);
	
	int c = strlen(s.base);
	
	for(i = 0; i < c; i++)
	   
		for(j = i+1; j < c; j++)
		{
			if(s.base[i] == '(' && s.base[j] == '(')
			{	
			  i = j;
			  continue;
			}
			
			
			if(s.base[i] == '(' && s.base[j] == ')')
			  { 
			     for(int k = i+1; k < j-1; k++)
			     {
			       if(s.base[i] == '-')
			      
				 }
			  }
			  
	
	} 
	
}
int main()	
{
	int n;
	cin >>n;
	stack s;
	
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		InitStack(&s);
		cin >>s.base;
	    
        
	}
	
	 
      
	  

 } 
