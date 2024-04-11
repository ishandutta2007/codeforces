#include<stdio.h>
#define mod 998244353ll
long long a,b,cnt=0,n;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){scanf("%lld",&a);b=0;
		long long k=1000000000ll;
		while(k!=0){
			b*=100;b+=a/k;
			a%=k;k/=10;
		}cnt=(cnt+b%mod*11)%mod;
	}printf("%lld",cnt*n%mod);
}