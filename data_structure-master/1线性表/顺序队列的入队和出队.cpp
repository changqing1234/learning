#include<stdio.h>
#include<iostream>
using namespace std;
#define maxSize 20

int main(void){
	int queue[maxSize];
	int rear, front;
	rear = front = 0;
	
	int value;
	int select;
	int index;
	
	while(1){
		cout<<"		1 ���";
		cout<<"		2 ����";
		cout<<"		3 ��ӡ��������"<<endl;
		cout<<"��ѡ����Ĳ���"<<endl;
		
		cin>>select;
		switch(select){
			case 1:	
				if(front == (rear+1) % maxSize){
					cout<<"��������������Ӻ������"<<endl;
					
				}else{
					cout<<"��������Ҫ���������"<<endl;
				 	cin>>value;
				 	rear = (rear+1) % maxSize;
				 	queue[rear] = value;
				}
				break;
			
			case 2:
				if(rear == front){
					cout<<"����Ϊ�գ��������"<<endl;
					
				}else{
					front = (front+1) % maxSize;
					cout<<"���ӵ�����Ϊ��"<<queue[front]<<endl;
				}
				
				break;
				
			case 3:
				if(front == rear){
					cout<<"�ն���, ����Ӻ�������ӡ����"<<endl<<endl;
					break;
				} 
				index = front;
				cout<<"���е���������: "<<endl;
				while(rear+1 != (index+1) % maxSize){
					index = index +1;
					cout<<queue[index]<<" ";
				}
				cout<<endl;
				break;
				
			default: cout<<"�����������������"<<endl;
			
		}
	}
	
}
