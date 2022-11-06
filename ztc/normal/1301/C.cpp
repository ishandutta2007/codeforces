#include<stdio.h>
long long a,b,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&a,&b);
		long long p=(a-b)/(b+1),q=p+1;
		long long v=(a-b)%(b+1),u=b+1-v;
		printf("%lld\n",a*(a+1)/2-u*p*(p+1)/2-v*q*(q+1)/2);
	}
}