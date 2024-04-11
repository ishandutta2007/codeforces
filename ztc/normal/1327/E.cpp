#include<stdio.h>
#define mod 998244353
int pow[200002],n;
int main(){
	scanf("%d",&n);pow[0]=1;
	for(int i=1;i<=n;i++)pow[i]=10ll*pow[i-1]%mod;
	for(int i=1;i<n;i++){
		printf("%lld ",(18ll*pow[n-i]+81ll*pow[n-i-1]*(n-i-1))%mod);
	}printf("10");
}