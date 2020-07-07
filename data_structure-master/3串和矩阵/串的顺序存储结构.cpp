#include<stdio.h>
#include<iostream>
using namespace std;

#define maxSize 20

//串的顺序结构 
typedef struct{
	char ch[maxSize];
	int length; 
}Str; 


//串的赋值操作 
int strAssign(Str &str, char *c){
	int i;
	for(i=0; c[i] != '\0'; i++){
		str.ch[i] = c[i];
	}
	
	str.ch[i+1] = '\0';
	str.length = i;
}

//串的置换
int replace(Str &s1, int i, int j, Str &s2){
	//超出的串的最大范围 
	if(i+j >= maxSize){
		return 0;
	}
	
	//链接s2 
	for(int k=0; k<=s2.length; k++){
		s1.ch[i+k] = s2.ch[k];
	}
	
	return 1;
	
}

//打印串
void print(Str &str){
	cout<<"串为: "; 
	for(int i=0; str.ch[i] != '\0'; i++){
		cout<<str.ch[i];
	}
	
	cout<<endl;
} 

//判断是否为子串
int index(Str &s1, Str & s2){
	int i,j, k;
	i = 0;
	j = 0;
	k = 0;
	
	//当主串跟子串不匹配时，子串回到第一个位置，主串接着下一个位置比较 
	while(i<s1.length && j<s2.length){
		if(s1.ch[i] == s2.ch[j]){
			i++;
			j++;
			
		}else{
			
			j=0;
			k++;
			i = k;
			
		}
	}
	 
	//比较成功，就返回第一个成功字符的地址 
	if(j == s2.length)
		return k;
	return 0;
} 


//串的反转
void reverse(Str &str){
	int i, j;
	i = 0;
	j = str.length-1;
	char temp;
	
	while(i != j){
		temp = str.ch[i];
		str.ch[i] = str.ch[j];
		str.ch[j] = temp;
		i++;
		j--;
	}
} 

int main(void){
	Str s1, s2;
	
	strAssign(s1, (char*)"hello world");
	print(s1);
	
	strAssign(s2, (char*)"world");
	print(s2); 
	
	cout<<"子串的位置在："<<index(s1, s2)<<endl;;
	
	reverse(s1);
	print(s1);
}










