#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
void swap(char& ch1, char& ch2){
	char temp = ch1;
	ch1 = ch2;
	ch2 = temp;
	
}
int main(void){
	char s1[] = "gfgff";
	cout<<"�ַ���Ϊ"<<s1<<endl;
	
	int len1 = strlen(s1);
	
	int i = 0;
	int j = len1 - 1;
	
	while(i < j){
		swap(s1[i] , s1[j]);
		++i;
		--j;
		
	}
	
	cout<<"��ת��Ĵ����£�"<<endl;
	cout<<s1;
	
	
} 
