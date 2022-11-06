#include<stdio.h>
long long a,n,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%d%d",&n,&a);
		printf("%lld\n",a*2);
	}
}