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
	printf("�����������ĸ�����");
	cin>>n;
	
	printf("ǰ������%d������:", n); 
     top = creat_stack(n);
	printf("������Ϊ��"); 
    output_stack(top,  n);

}

