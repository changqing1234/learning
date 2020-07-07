#include<stdio.h>
#include<iostream>
using namespace std;
//���Ա�Ĳ��ҡ����롢ɾ������ 

#define maxSize 100
typedef struct{
	
	int data[maxSize];
	int length;
	
}Sqlist;

int findElem(Sqlist L, int e);
int insertElem(Sqlist &L, int p, int e);
int deleteElem(Sqlist &L, int p , int &e);
void print(Sqlist L);

int main(void){
	Sqlist L;
	L.length = 0;
	
	int e; 
	
	
	//��˳����в�������
	 insertElem(L, 0, 45);
	 insertElem(L, 1, 30);
	print(L);
	
	//��������
	int index = findElem(L, 45);
	cout<<"�����ݵ�λ���ڵ�"<<index+1<<"λ"<<endl; 
	 
	
	// ��˳�����ɾ������
	deleteElem(L, 0, e); 
	print(L);
	
	
	
}

void print(Sqlist L){
	printf("�������˳��������Ϊ: ");
	
	for(int i=0; i<L.length; i++){
		printf("%d ", L.data[i]);
	} 
	printf("\n");
}


int findElem(Sqlist L, int e){
	int i;
	for(int i=0; i<L.length; i++){
		if(e == L.data[i]){
			return i;
		}
		
		return -1;
	}
}


int insertElem(Sqlist &L, int p, int e){
	if(p<0 || p>L.length || L.length == maxSize){
		return 0;
	}
	
	for(int i=L.length-1; i>=p; i--){
		L.data[i+1] =  L.data[i];
	}
	L.data[p] =  e;
	++(L.length);
	
	return 1;
}

int deleteElem(Sqlist &L, int p, int &e){
	
	int i; 
	if(p<0 || p>L.length-1)
		return 0;
		
		e = L.data[p];
		
		for(int i=p; i<L.length; i++){
			L.data[i] = L.data[i+1];
		
		}
		
		--(L.length);
		return 1;
		
}



