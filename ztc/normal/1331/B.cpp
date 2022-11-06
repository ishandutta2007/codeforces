#include<stdio.h>
int n;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)if(n%i==0)return printf("%d%d",i,n/i)&0;
}