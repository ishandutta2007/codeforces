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
const int maxn=1e5+5;
const int mod=998244353;
int n;
int id[maxn][2],num1,num2,num3,num4;
int ans;
int fac[maxn<<1],inv[maxn<<1];
void prework()
{
	fac[0]=1;for(int i=1;i<=2*n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=2*n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=2*n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int C(int n,int m){if(n<m||m<0)return 0;return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int calc()
{
	for(int i=1;i<=n;i++)
		if(id[i][0]&&id[i][0]==id[i][1])return 0;
	int ret=1;for(int i=1;i<=n;i++)if(!id[i][0]&&!id[i][1])(ret*=2)%=mod;
	return ret;
}
int main()
{
	n=read();
	prework();
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		if(s[0]=='?')id[i][0]=0;
		else if(s[0]=='W')id[i][0]=1;
		else id[i][0]=-1;
		if(s[1]=='?')id[i][1]=0;
		else if(s[1]=='W')id[i][1]=1;
		else id[i][1]=-1;
	}
	ans=(ans-calc()+mod)%mod;
	int del=2;
	for(int i=1;i<=n;i++)if(id[i][0]==1||id[i][1]==-1){del--;break;}
	for(int i=1;i<=n;i++)if(id[i][0]==-1||id[i][1]==1){del--;break;}
	(ans+=del)%=mod;
	for(int i=1;i<=n;i++)
	{
		if(id[i][0]&&id[i][1]){if(id[i][0]==id[i][1])num4+=id[i][0];}
		else if(id[i][0]==1||id[i][1]==1)num1++;
		else if(id[i][0]==-1||id[i][1]==-1)num2++;
		else num3++;
	}
	(ans+=C(num1+num2+num3+num3,num2+num3-num4))%=mod;
	printf("%d\n",ans);
	return 0;
}