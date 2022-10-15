#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5,mod=998244353;
int n;
char s[maxn];
int fac[maxn],inv[maxn];
void prework()
{
	n=1e5;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m){if(n<m)return 0;return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	T=read();prework();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')cnt0++;
		for(int i=1;i<n;i++)if(s[i]=='1'&&s[i+1]=='1')cnt1++,i++;
		printf("%d\n",C(cnt0+cnt1,cnt1));
	}
	return 0;
}