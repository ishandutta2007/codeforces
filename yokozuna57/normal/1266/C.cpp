#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	int r,c;
	scanf("%d%d",&r,&c);
	if(r == 1 && c == 1){
		puts("0");
	}
	else if(r == 1){
		for(int i = 1 ; i <= c ; i ++){
			printf("%d%c",i+1,(i==c)?'\n':' ');
		}
	}
	else if(c == 1){
		for(int i = 1 ; i <= r ; i ++){
			printf("%d\n",i+1);
		}
	}
	else {
		for(int i = 1 ; i <= r ; i ++){
			for(int j = 1 ; j <= c ; j ++){
				printf("%d%c",i*(r+j),(j==c)?'\n':' ');
			}
		}
	}
}