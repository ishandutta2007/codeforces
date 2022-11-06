#include<stdio.h>
int n,m;
int main(){
	scanf("%d",&n);
	printf("%d\n",m=n+2>>1);
	for(int i=1;i<=m;i++)printf("%d %d\n",1,i);
	n-=m-1;
	for(int i=2;i<=n;i++)printf("%d %d\n",i,m);
}