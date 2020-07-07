#include<stdio.h>
#include<iostream>
using namespace std;
typedef int ElemType;
#define m 12 

//双栈数据结构 
typedef struct{
	ElemType data[m];
	int top[2];
		
}Stack;

//初始化双栈 
void initStack(Stack &st){
	st.top[0] = -1;
	st.top[1] = m;
}

//判断哪个栈为空 
int isEmpty(Stack &st, int i){
	
	//如果是栈0，栈顶指针为-1， 栈顶指针为m 
	if(i == 1 && st.top[i] == m)
		return 1;
	if(i == 0 && st.top[i] == -1)
		return 1;
	else
		return 0;	
}

//判断栈是已满
int isFully(Stack &st){
	if(st.top[0] + 1 == st.top[1])
		return 1;
	else
		return 0;
} 


//入栈,必须指定入哪个栈 
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

//出栈,必须指定哪个出栈
int pop(Stack &st, int i, ElemType &e){
	if(isEmpty(st, i))
		return 0;
		
	else{
		e = st.data[st.top[i]--];
		return 1;
	}
} 

//取栈顶元素
int getTop(Stack st, int i, ElemType &e){
	if(isEmpty(st, i))
		return 0;
		
	else{
		e = st.data[st.top[i]];
		return 1;
	}
	
}

//清空栈
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
	cout<<"双栈初始化成功"<<endl;
	
	while(1){
		
		cout<<"请输入的操作的栈号"<<endl;
		cin>>index;
		
		if(index != 1 && index != 0)
			cout<<"输入错误，请重新选择"<<endl;
			 
		else{
			
			while(1){
				
				cout<<"请选择你的操作, 1 进栈， 2 出栈， 3 清空  4 打印栈"<<endl;
				cin>>select;
				
				if(select != 1 && select != 2 && select != 3 && select != 4)
					cout<<"输入错误，请重新选择"<<endl;
				else
					break;
				
			}
		
		switch(select){
			case 1:
				cout<<"青请输入你要输入的数据"<<endl;
				cin>>x;
				push(st, index, x);
				break;
				
			case 2:
				if(pop(st, index, x ) == 1)
					cout<<"你要出栈的数据为"<<x<<endl;
				else
					cout<<"空栈，没有数据"<<endl; 
				break;
				
			case 3:
				clear(st, index);
				cout<<"栈已经清空"<<endl;
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
					cout<<"空栈"<<endl;
				}
				
				cout<<endl;
				break;
			}
		
		}	
	}
} 
