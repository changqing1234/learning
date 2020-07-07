#include<stdio.h>
#include<iostream>
using namespace std;

//µÝ¹éÇó½×³Ë 
int get(int n){
	
	if(n > 0){
		int k = get(--n);
		cout<<n<<"µÄ½×³ËÎª"<<k<<endl;
		return (n+1) * k;
		
		
	}else{
		return 1;
	}
	
}

int main(void){
	int n;
	cout<<"ÇëÊäÈë½×³ËÊý"<<endl;
	cin>>n;
	
	cout<<n<<"µÄ½×³ËÎª£º"<<get(n)<<endl;
	 
	
}
