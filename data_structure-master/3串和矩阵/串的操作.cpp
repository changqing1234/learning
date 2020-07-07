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
	
	cout<<"请输入字符串1"<<endl;
	cin>>s;
	cout<<"请输入字符串2"<<endl;
	cin>>s1;
	
	Str str, str1;
	

	strAssign(str, s);	
	strAssign(str1, s1);
	
	print(str);
	print(str1);
	

	
	int value = index(str, str1);
	if(value){
		cout<<"匹配成功，子串的位置是:"<<value<<endl; 
	} else{
		cout<<"匹配不成功"<<endl;
	}
	

}

//赋值字符串 
int strAssign(Str &str,  char *ch){	
	if(str.ch){	
		str.ch = NULL;
	}
	int len = 0;
	char *c = ch;
	
	//求出字符数组的长度 
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

//打印串
void print(Str str){
	cout<<"操作后的串如下:"; 
	cout<<str.ch<<endl;;
} 

//求子串的位置 
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

//取串长度
int strLength(Str str){
	return str.length;
} 

//串比较
int strCompare(Str str1, Str str2){
	for(int i=0; i<str1.length && i<str2.length; i++){
		
		if(str1.ch[i] != str2.ch[i]){
			return str1.ch[i] - str2.ch[i];
			
		}
	}
	
	return str1.length - str2.length;
} 
