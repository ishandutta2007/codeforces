#include<stdio.h>
int n,k,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		printf("%s\n",n>=1ll*k*k&&!((n^k)&1)?"YES":"NO");
	}
}