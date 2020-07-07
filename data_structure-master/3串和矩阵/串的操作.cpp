#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct{
	char *ch;
	int length;
	
}Str;

int strAssign(Str &str, char *ch);
int index(Str str1, Str subString);
int strLength(Str str);
int strCompare(Str str1, Str str2);
void print(Str str);

int main(void){
	
	char s[30];
	char s1[30];
	
	cout<<"�������ַ���1"<<endl;
	cin>>s;
	cout<<"�������ַ���2"<<endl;
	cin>>s1;
	
	Str str, str1;
	

	strAssign(str, s);	
	strAssign(str1, s1);
	
	print(str);
	print(str1);
	

	
	int value = index(str, str1);
	if(value){
		cout<<"ƥ��ɹ����Ӵ���λ����:"<<value<<endl; 
	} else{
		cout<<"ƥ�䲻�ɹ�"<<endl;
	}
	

}

//��ֵ�ַ��� 
int strAssign(Str &str,  char *ch){	
	if(str.ch){	
		str.ch = NULL;
	}
	int len = 0;
	char *c = ch;
	
	//����ַ�����ĳ��� 
	while(*c){
		++len;
		++c;
	}
	
	if(len == 0){
		str.ch = NULL;
		str.length = 0;
		return 1;
		
	}else{
		str.ch = (char*) malloc(sizeof(char) * (len+1));
		if(str.ch == NULL){
			return 0;
			
		}else{
			c = ch;
			for(int i=0; i<=len; i++){
				str.ch[i] = *c;
				++c;
			}
			
			str.length = len;
			return 1;
		}
	}
	
}

//��ӡ��
void print(Str str){
	cout<<"������Ĵ�����:"; 
	cout<<str.ch<<endl;;
} 

//���Ӵ���λ�� 
int index(Str str1, Str subString){
	int i, j, k;
	i = j = k = 0;
	
	while(i < str1.length && j < subString.length){
		if(str1.ch[i] == subString.ch[j]){
			i++;
			j++;
			
		}else{
			j=0;
			i = ++k;
		}
		
		if(j = subString.length){
			return k+1;
			
		}else{
			return 0;
		}
		
	}
}

//ȡ������
int strLength(Str str){
	return str.length;
} 

//���Ƚ�
int strCompare(Str str1, Str str2){
	for(int i=0; i<str1.length && i<str2.length; i++){
		
		if(str1.ch[i] != str2.ch[i]){
			return str1.ch[i] - str2.ch[i];
			
		}
	}
	
	return str1.length - str2.length;
} 
