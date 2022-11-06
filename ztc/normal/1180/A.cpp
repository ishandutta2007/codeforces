#include<stdio.h>
long long n;
int main(){
	scanf("%lld",&n);
	printf("%lld",n*(n-1)*2+1);
}