#include<stdio.h>
#include<iostream>
using namespace std;
typedef int ElemType;
#define m 12 

//˫ջ���ݽṹ 
typedef struct{
	ElemType data[m];
	int top[2];
		
}Stack;

//��ʼ��˫ջ 
void initStack(Stack &st){
	st.top[0] = -1;
	st.top[1] = m;
}

//�ж��ĸ�ջΪ�� 
int isEmpty(Stack &st, int i){
	
	//�����ջ0��ջ��ָ��Ϊ-1�� ջ��ָ��Ϊm 
	if(i == 1 && st.top[i] == m)
		return 1;
	if(i == 0 && st.top[i] == -1)
		return 1;
	else
		return 0;	
}

//�ж�ջ������
int isFully(Stack &st){
	if(st.top[0] + 1 == st.top[1])
		return 1;
	else
		return 0;
} 


//��ջ,����ָ�����ĸ�ջ 
int push(Stack &st, int i, ElemType x){
	if(isFully(st))
		return 0;
		
	else if(i == 0){
		st.top[i]++;
		st.data[st.top[i]] = x;
		return 1;
		
	}else{
		st.top[i]--;
		st.data[st.top[i]] = x;
		return 1;
	}
	
} 

//��ջ,����ָ���ĸ���ջ
int pop(Stack &st, int i, ElemType &e){
	if(isEmpty(st, i))
		return 0;
		
	else{
		e = st.data[st.top[i]--];
		return 1;
	}
} 

//ȡջ��Ԫ��
int getTop(Stack st, int i, ElemType &e){
	if(isEmpty(st, i))
		return 0;
		
	else{
		e = st.data[st.top[i]];
		return 1;
	}
	
}

//���ջ
void clear(Stack &st, int i){
	if(i == 0)
		st.top[i] == -1;
		
	if(i == 1)
		st.top[i] == m;
} 



int main(void){
	
	Stack st;
	int index;
	int select;
	int x;
	
	initStack(st);
	cout<<"˫ջ��ʼ���ɹ�"<<endl;
	
	while(1){
		
		cout<<"������Ĳ�����ջ��"<<endl;
		cin>>index;
		
		if(index != 1 && index != 0)
			cout<<"�������������ѡ��"<<endl;
			 
		else{
			
			while(1){
				
				cout<<"��ѡ����Ĳ���, 1 ��ջ�� 2 ��ջ�� 3 ���  4 ��ӡջ"<<endl;
				cin>>select;
				
				if(select != 1 && select != 2 && select != 3 && select != 4)
					cout<<"�������������ѡ��"<<endl;
				else
					break;
				
			}
		
		switch(select){
			case 1:
				cout<<"����������Ҫ���������"<<endl;
				cin>>x;
				push(st, index, x);
				break;
				
			case 2:
				if(pop(st, index, x ) == 1)
					cout<<"��Ҫ��ջ������Ϊ"<<x<<endl;
				else
					cout<<"��ջ��û������"<<endl; 
				break;
				
			case 3:
				clear(st, index);
				cout<<"ջ�Ѿ����"<<endl;
				break;
				
			case 4:
				if( !isEmpty(st, index)){
					if(index == 0){
						for(int i=0; i<st.top[index]; i++){
						cout<<st.data[i]<<" ";
						}
					}else{
						for(int i=st.top[index]; i<m; i++){
							cout<<st.data[i]<<" ";
						}
					}
				}else{
					cout<<"��ջ"<<endl;
				}
				
				cout<<endl;
				break;
			}
		
		}	
	}
} 
