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
		cout<<"		1 入队";
		cout<<"		2 出队";
		cout<<"		3 打印队列数据"<<endl;
		cout<<"请选择你的操作"<<endl;
		
		cin>>select;
		switch(select){
			case 1:	
				if(front == (rear+1) % maxSize){
					cout<<"队列已满，请出队后再入队"<<endl;
					
				}else{
					cout<<"请输入你要输入的数据"<<endl;
				 	cin>>value;
				 	rear = (rear+1) % maxSize;
				 	queue[rear] = value;
				}
				break;
			
			case 2:
				if(rear == front){
					cout<<"队列为空，请先入队"<<endl;
					
				}else{
					front = (front+1) % maxSize;
					cout<<"出队的数据为："<<queue[front]<<endl;
				}
				
				break;
				
			case 3:
				if(front == rear){
					cout<<"空队列, 请入队后再来打印数据"<<endl<<endl;
					break;
				} 
				index = front;
				cout<<"队列的数据如下: "<<endl;
				while(rear+1 != (index+1) % maxSize){
					index = index +1;
					cout<<queue[index]<<" ";
				}
				cout<<endl;
				break;
				
			default: cout<<"输入错误，请重新输入"<<endl;
			
		}
	}
	
}
