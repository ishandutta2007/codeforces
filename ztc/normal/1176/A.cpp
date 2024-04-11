#include<stdio.h>
long long n;
int m,cnt;
int main(){
	scanf("%d",&m);
	while(m--){
		cnt=0;scanf("%lld",&n);
		while(!(n&1))n>>=1,cnt++;
		while(!(n%3))n/=3,cnt+=2;
		while(!(n%5))n/=5,cnt+=3;
		printf("%d\n",n==1?cnt:-1);
	}
}