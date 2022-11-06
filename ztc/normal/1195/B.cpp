#include<stdio.h>
long long n,k,a;
int main(){
	scanf("%lld%lld",&n,&k);
	for(long long i=1;;i++){
		if(i*(i+1)/2-n+i==k)return printf("%lld",n-i)&0;
	}
}