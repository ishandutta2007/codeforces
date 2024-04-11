#include<iostream>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/2;j++){
			if(j!=1)printf(" ");
			printf("%d %d",2*(j-1)*n+i,2*j*n+1-i);
		}
		printf("\n");
	}
}