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

//线性表的数据结构 
typedef struct{
	ElemType* elem;
	int length;
	int listsize;
}SqList;

//线性表的初始化 
Status InitList(SqList &L){
	L.elem = (ElemType* )malloc (INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = INIT_SIZE;
}

//线性表的输入 
Status Input(SqList &L){
	int n, i;
	
	cout<< "请输入你要输入的个数：\n";
	cin>> n;
	
	if(n > INIT_SIZE) 
	 { 
	 	L.elem = (ElemType* )realloc(L.elem,  n - INIT_SIZE);
	    L.listsize = n;
	 } 
	  
	cout<< "请输入你要输入的数据：\n";
	
	for(i = 0; i < n; i++){
		cin>> L.elem[i];
	}
	L.length = n;
		
}

//判断线性表中是否已经存在元素a 
Status Judge(ElemType a, SqList &C){
	int i;
	
	for(i = 0; i < C.length; i++){
		if(a == C.elem[i])
			return false;
	}
	
	return ok;
}

//合并线性表 
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

//输出线性表 
Status Put(SqList &C){
	int i;
	
	for(i = 0; i < C.length; i++){
		cout<< C.elem[i]<<" ";
	}
	cout<<endl;
	return ok;
}

//在线性表L中第i个元素插入新的元素e 
Status ListInsert(SqList &L, int i, ElemType e){
	ElemType* p;
	 
	if(i < 1 || i > L.length + 1) {
		
		cout<< "你输入的位置有问题, 插入失败：\n";
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

//线性表的排序 
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

//删除线性表中的元素
Status ListDelet(SqList &L, int i,  ElemType* e){
	ElemType* q;
	if(i < 1 || i > L.length){
		cout<< "没有找到你要删除的数：\n";
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
	
	cout<< "\n合并后的数组为如下：\n";
	Put(C);
	
	cout<< "\n请输入你要插入的位置和数\n";
	cin>>i >>a;
	
	ListInsert(C, i, a);
	cout<< "\n插入后的数组为：\n";
	Put(C);
	
    Sort(C);
	cout<<"\n排序后的线性表如下：\n";
	Put(C);
	
	cout<<"\n请输入你要删除的数的位置：\n";
	cin>> i;
	
	ListDelet(C, i,&e);
	cout<< "\n你删除的数为:"<<e <<endl;
	cout<<"删除后的线性表如下：\n";
	Put(C);
	
	return 0;
	
	
 } 
 
