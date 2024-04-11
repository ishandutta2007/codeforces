#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000005,mod=998244353;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
int n;
int a[N],aa[N],dp[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=(a[i-1]+read())%mod;
	int inv=Pow(2,mod-2);
	for (int i=1;i<=n;i++)
		aa[i]=(1LL*a[i]*Pow(inv,i)+aa[i-1])%mod;
//	for (int i=1;i<=n;i++)
//		a[i]=(a[i-1]+a[i])%mod;
	dp[0]=0;
	for (int i=1;i<=n;i++){
		dp[i]=(1LL*aa[i]*Pow(2,i-1)+1LL*inv*a[i]+dp[i-1])%mod;
		dp[i]=(dp[i]+dp[i-1])%mod;
	}
	printf("%d",(dp[n]-dp[n-1]+mod)%mod);
	return 0;
}
/*
dp[i] = (dp[j]+s[i-j]*(2^(j-1)))
	  = dp[j] (0<=j<i) + 2^(i-1) s[j] * (1/2)^j (0<j<=i)*/