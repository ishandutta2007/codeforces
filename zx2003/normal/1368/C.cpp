#include<bits/stdc++.h>
int n,i,j;
int main(){
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	puts("0 0");
	for(i=1;i<=n+1;++i){
		printf("%d %d\n",i,-i);
		printf("%d %d\n",i-1,-i);
		printf("%d %d\n",i,1-i);
	}
}