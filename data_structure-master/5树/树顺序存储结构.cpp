#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct{
	int data;
	int pid;
	
}TreeNode;

int main(void){
	
	cout<<"��������Ҫ����Ľڵ����ĸ���"<<endl;
	int n;
	cin>>n;
	
	TreeNode tn[n+1];
	
	cout<<"��������Ҫ��������ݺ�˫�׽ڵ��λ��"<<endl;
	for(int i=1; i<=n; i++){
		cin>>tn[i].data;
		cin>>tn[i].pid;
		
	}
	
	
	cout<<"������������ ";
	for(int i=1; i<=n; i++){
		cout<<tn[i].data<<" ";
	}
	
	cout<<"\n��������Ҫ���ҵĺ���"<<endl;
	int index;
	cin>>index;
	cout<<"�ú��ӵ��������£�"<<tn[index].data;
	
	if(tn[index].pid == -1){
		cout<<"˫�ײ�����"<<endl;
	} else{
		cout<<"˫��Ϊ"<<tn[tn[index].pid].data; 
	}
	
	cout<<endl;
	
	
} 
