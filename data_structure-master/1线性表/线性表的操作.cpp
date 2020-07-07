#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
using namespace std;

typedef int Status;
typedef int ElemType;
#define ok 1
#define false 0
#define INIT_SIZE 20
#define error -1

//���Ա�����ݽṹ 
typedef struct{
	ElemType* elem;
	int length;
	int listsize;
}SqList;

//���Ա�ĳ�ʼ�� 
Status InitList(SqList &L){
	L.elem = (ElemType* )malloc (INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = INIT_SIZE;
}

//���Ա������ 
Status Input(SqList &L){
	int n, i;
	
	cout<< "��������Ҫ����ĸ�����\n";
	cin>> n;
	
	if(n > INIT_SIZE) 
	 { 
	 	L.elem = (ElemType* )realloc(L.elem,  n - INIT_SIZE);
	    L.listsize = n;
	 } 
	  
	cout<< "��������Ҫ��������ݣ�\n";
	
	for(i = 0; i < n; i++){
		cin>> L.elem[i];
	}
	L.length = n;
		
}

//�ж����Ա����Ƿ��Ѿ�����Ԫ��a 
Status Judge(ElemType a, SqList &C){
	int i;
	
	for(i = 0; i < C.length; i++){
		if(a == C.elem[i])
			return false;
	}
	
	return ok;
}

//�ϲ����Ա� 
Status MergeList(SqList A, SqList B, SqList &C){
	int i;

	C.elem = (ElemType* )malloc(A.length * sizeof(ElemType));
	for(i = 0; i < A.length; i++){
		C.elem[i] =  A.elem[i]; 
	}
	
	C.length = A.length;
	
	for(i = 0; i < B.length; i++){
		if(Judge(B.elem[i],  C)){	
			C.elem = (ElemType* )realloc(C.elem, sizeof(ElemType));
			C.elem[C.length++] = B.elem[i];
			
		}
			
			
	}
	return ok;
}

//������Ա� 
Status Put(SqList &C){
	int i;
	
	for(i = 0; i < C.length; i++){
		cout<< C.elem[i]<<" ";
	}
	cout<<endl;
	return ok;
}

//�����Ա�L�е�i��Ԫ�ز����µ�Ԫ��e 
Status ListInsert(SqList &L, int i, ElemType e){
	ElemType* p;
	 
	if(i < 1 || i > L.length + 1) {
		
		cout<< "�������λ��������, ����ʧ�ܣ�\n";
		exit(0);
	}
	
	L.elem = (ElemType* )realloc(L.elem, sizeof(ElemType));
	if(!L.elem) exit(0);
	
	ElemType* q = &(L.elem[i - 1]);
	
	for(p = &(L.elem[L.length - 1]); p >= q; --p) 
	*(p + 1) = *p;
	
	*q = e;
	++L.length;
	return ok;
	
	
}

//���Ա������ 
Status Sort(SqList &L){
	int i, j;
	ElemType item;
	
	for(i = 0; i < L.length - 1; i++)
		for(j = i + 1; j < L.length; j++){
			if(L.elem[j] < L.elem[i])
			{
				item = L.elem[i];
				L.elem[i] = L.elem[j];
				L.elem[j] = item;
			}
		}
		
		return ok;
}

//ɾ�����Ա��е�Ԫ��
Status ListDelet(SqList &L, int i,  ElemType* e){
	ElemType* q;
	if(i < 1 || i > L.length){
		cout<< "û���ҵ���Ҫɾ��������\n";
		exit(0);
	}
	
	q = &L.elem[i - 1];
	*e = L.elem[i - 1];
	
	for(ElemType* p = &L.elem[L.length - 1]; p >= q; ++q)
		*q = *(q + 1); 
		L.length--;
	
	
} 

int main(void)
{
	SqList A, B, C;
	int a, i, e;
	
	InitList(A), InitList(B);
	Input(A), Input(B);
	MergeList(A, B, C);
	
	cout<< "\n�ϲ��������Ϊ���£�\n";
	Put(C);
	
	cout<< "\n��������Ҫ�����λ�ú���\n";
	cin>>i >>a;
	
	ListInsert(C, i, a);
	cout<< "\n����������Ϊ��\n";
	Put(C);
	
    Sort(C);
	cout<<"\n���������Ա����£�\n";
	Put(C);
	
	cout<<"\n��������Ҫɾ��������λ�ã�\n";
	cin>> i;
	
	ListDelet(C, i,&e);
	cout<< "\n��ɾ������Ϊ:"<<e <<endl;
	cout<<"ɾ��������Ա����£�\n";
	Put(C);
	
	return 0;
	
	
 } 
 
