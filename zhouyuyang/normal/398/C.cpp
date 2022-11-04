#include<cstdio>
int n,i;
int main(){
	scanf("%d",&n);
	if(n==5)return puts("1 2 3\n1 3 3\n2 4 2\n4 5 1\n3 4\n3 5"),0;
	for(i=1;i<=n/2;i++)printf("%d %d 1\n",i,i+n/2);
	for(;i<n;i++)printf("%d %d %d\n",i,i+1,i*2-1-n/2*2);
	for(i=1;i<n/2;i++)printf("%d %d\n",i,i+1);
	puts("1 3");
}