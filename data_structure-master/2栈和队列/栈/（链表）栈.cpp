#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std; 
typedef struct stack{
	int date;
	struct stack* next;
}Lstack, *link;

link creat_stack(int n)
{
	int i, j;
	link p;
	
     link top = new Lstack;
	top->next == NULL;
	
	for(i = 0; i < n; i++)
	{
		p = (link)malloc(sizeof(Lstack));
		
		cin >> p->date;
		p->next = top->next;
		top->next = p;
		
	}
	return top;
	
}

void output_stack(link top, int n)
{
	link p = top->next;
	 
	for(int i = n; i> 0; i--)
	{
		cout << p->date<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main(void)
{
	link top;
	
	int n;
	printf("请输入整数的个数：");
	cin>>n;
	
	printf("前请输入%d个整数:", n); 
     top = creat_stack(n);
	printf("输出结果为："); 
    output_stack(top,  n);

}

