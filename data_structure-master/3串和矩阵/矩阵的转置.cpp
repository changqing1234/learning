#include<stdio.h>
#include<iostream>
using namespace std;
typedef int ElemType;
#define m  3
#define n  3
void trsmat(ElemType A[][n],  ElemType B[][n],  int a);
void print(ElemType A[][n], int a);

int main(void){
	ElemType A[m][n] = {
		{13, 45, 53},
		{43, 556, 56},
		{56, 56,767}
	};
	
	ElemType B[m][n] = {
		{214, 66, 676},
		{15, 77, 99},
		{78, 547, 989}
	};
	cout<<"原来的矩阵如下："<<endl;
	print(A, m);
	
	cout<<"转置后的矩阵如下："<<endl;
	trsmat(A, B, m);
	
	print(B, m);
	
	
	return 0;
	
}


//打印二维数组 
void print(ElemType A[][n], int a){
	for(int i=0; i<a; i++){
		for(int j=0; j<n; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	} 
}




void trsmat(ElemType A[][n] , ElemType B[][n], int a){
	for(int i=0; i<a; i++){
		for(int j=0; j<n; j++){
			B[j][i] = A[i][j];
			
		}
	}
}
