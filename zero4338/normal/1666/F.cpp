#include<bits/stdc++.h>
#define int long long
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
const int maxn=5e3+5,mod=998244353;
int n,a[maxn],cnt[maxn],f[maxn][maxn],inv[maxn];
signed main()
{
	inv[0]=inv[1]=1;
	for(int i=2;i<=5e3;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=5e3;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		memset(cnt,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n;j++)f[i][j]=0;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=a[n];i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=a[n-1];i++)
		{
			f[i][0]=1;
			f[i][1]=((ll)(cnt[i]-cnt[i-1])*cnt[i-1]%mod*(cnt[i-1]-1)%mod+f[i-1][1])%mod;
			for(int j=2;j<=cnt[i]/2;j++)
			{
				f[i][j]=0;
				(f[i][j]+=f[i-1][j])%=mod;
				(f[i][j]+=(ll)(cnt[i]-cnt[i-1])*f[i-1][j-1]%mod*(cnt[i-1]-2*(j-1)-1)%mod)%=mod;
			}
		}
		if(a[n-1]==a[n])puts("0");
		else
		{
			for(int i=1;i<=a[n];i++)f[a[n-1]][n/2-1]=(ll)f[a[n-1]][n/2-1]*inv[cnt[i]-cnt[i-1]]%mod;
			f[a[n-1]][n/2-1]=(f[a[n-1]][n/2-1]%mod+mod)%mod;
			printf("%lld\n",f[a[n-1]][n/2-1]);
		}
	}
}