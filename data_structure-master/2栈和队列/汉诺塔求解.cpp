#include<stdio.h>
#include<iostream>
using namespace std;

//��ŵ������, ��x���̽���y�ᵽz�ϣ� zΪĿ���̣�yΪ������ 
void hanoi(int n, char x,  char y, char z){
	if(n == 1){
		cout<<"������1"<<"��"<<x<<"�ᵽ"<<z<<endl; 
		
	}else{
		hanoi(n-1, x, z, y);
		cout<<"������"<<n<<"��"<<x<<"�ᵽ"<<z<<endl;
		hanoi(n-1, y, x, z);
	}
	
	
} 

int main(void){
	
	int n;
	cout<<"���������ӵĸ���"<<endl;
	cin>>n;
	
	hanoi(n, 'x', 'y', 'z');
	
} 
