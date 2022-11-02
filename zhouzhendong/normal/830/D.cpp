#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=405,mod=1e9+7;
int n;
int Inv[N],Fac[N];
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
int C(int x,int y){
	if (y<0||y>x)
		return 0;
	return 1LL*Fac[x]*Inv[y]%mod*Inv[x-y]%mod;
}
int dp[N][N];
int main(){
	n=read();
	for (int i=Fac[0]=1;i<=n;i++)
		Fac[i]=1LL*Fac[i-1]*i%mod;
	Inv[n]=Pow(Fac[n],mod-2);
	for (int i=n;i>=1;i--)
		Inv[i-1]=1LL*Inv[i]*i%mod;
	memset(dp,0,sizeof dp);
	dp[1][1]=dp[1][0]=1;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;j+k<=n;k++){
				int tmp=1LL*dp[i-1][j]*dp[i-1][k]%mod;
				dp[i][j+k]=(tmp+dp[i][j+k])%mod;
				dp[i][j+k]=(2LL*tmp*(j+k)+dp[i][j+k])%mod;
				dp[i][j+k+1]=(tmp+dp[i][j+k+1])%mod;
				dp[i][j+k-1]=(2LL*tmp*C(j+k,2)+dp[i][j+k-1])%mod;
			}
	cout << dp[n][1];
	return 0;
}