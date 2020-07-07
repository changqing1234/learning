#include<stdio.h>
#include<iostream>
using namespace std;

#define maxSize 20

//����˳��ṹ 
typedef struct{
	char ch[maxSize];
	int length; 
}Str; 


//���ĸ�ֵ���� 
int strAssign(Str &str, char *c){
	int i;
	for(i=0; c[i] != '\0'; i++){
		str.ch[i] = c[i];
	}
	
	str.ch[i+1] = '\0';
	str.length = i;
}

//�����û�
int replace(Str &s1, int i, int j, Str &s2){
	//�����Ĵ������Χ 
	if(i+j >= maxSize){
		return 0;
	}
	
	//����s2 
	for(int k=0; k<=s2.length; k++){
		s1.ch[i+k] = s2.ch[k];
	}
	
	return 1;
	
}

//��ӡ��
void print(Str &str){
	cout<<"��Ϊ: "; 
	for(int i=0; str.ch[i] != '\0'; i++){
		cout<<str.ch[i];
	}
	
	cout<<endl;
} 

//�ж��Ƿ�Ϊ�Ӵ�
int index(Str &s1, Str & s2){
	int i,j, k;
	i = 0;
	j = 0;
	k = 0;
	
	//���������Ӵ���ƥ��ʱ���Ӵ��ص���һ��λ�ã�����������һ��λ�ñȽ� 
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
	 
	//�Ƚϳɹ����ͷ��ص�һ���ɹ��ַ��ĵ�ַ 
	if(j == s2.length)
		return k;
	return 0;
} 


//���ķ�ת
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
	
	cout<<"�Ӵ���λ���ڣ�"<<index(s1, s2)<<endl;;
	
	reverse(s1);
	print(s1);
}










