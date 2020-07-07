#include<stdio.h>
#include<iostream>
using namespace std;

//汉诺塔问题, 将x的盘借助y搬到z上， z为目的盘，y为辅助盘 
void hanoi(int n, char x,  char y, char z){
	if(n == 1){
		cout<<"将盘子1"<<"从"<<x<<"搬到"<<z<<endl; 
		
	}else{
		hanoi(n-1, x, z, y);
		cout<<"将盘子"<<n<<"从"<<x<<"搬到"<<z<<endl;
		hanoi(n-1, y, x, z);
	}
	
	
} 

int main(void){
	
	int n;
	cout<<"请输入盘子的个数"<<endl;
	cin>>n;
	
	hanoi(n, 'x', 'y', 'z');
	
} 
