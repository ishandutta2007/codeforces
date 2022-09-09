#include <cstdio>
#include <iostream>
using namespace std;
int a,b,i,f;
int main(){
	cin>>a>>b;
	for(i=1;;i+=2){
		if(a<i){
			puts("Vladik");	
			return 0;
		}
		a-=i;
		if(b<i+1){
			puts("Valera");
			return 0;
		}
		b-=i+1;
	}
	return 0;
}