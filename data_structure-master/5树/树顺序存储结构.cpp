#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct{
	int data;
	int pid;
	
}TreeNode;

int main(void){
	
	cout<<"请输入你要输入的节点数的个数"<<endl;
	int n;
	cin>>n;
	
	TreeNode tn[n+1];
	
	cout<<"请输入你要输入的数据和双亲节点的位置"<<endl;
	for(int i=1; i<=n; i++){
		cin>>tn[i].data;
		cin>>tn[i].pid;
		
	}
	
	
	cout<<"树的数据如下 ";
	for(int i=1; i<=n; i++){
		cout<<tn[i].data<<" ";
	}
	
	cout<<"\n请输入你要查找的孩子"<<endl;
	int index;
	cin>>index;
	cout<<"该孩子的数据如下："<<tn[index].data;
	
	if(tn[index].pid == -1){
		cout<<"双亲不存在"<<endl;
	} else{
		cout<<"双亲为"<<tn[tn[index].pid].data; 
	}
	
	cout<<endl;
	
	
} 
