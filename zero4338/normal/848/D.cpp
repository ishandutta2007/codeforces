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
const int maxn=55,mod=1e9+7;
int n,m;
int f[maxn][maxn],g[maxn][maxn],F[maxn][maxn],h[maxn][maxn],inv[maxn];
int tran(int n,int m,int x,int y)
{
	int ret=0,now=1;
	for(int i=0;i*x<=n&&i*y+1<=m;i++)
	{
		(ret+=(ll)f[n-i*x][m-i*y]*now%mod*inv[i]%mod)%=mod;
		now=(ll)now*(i+g[x][y])%mod;
	}
	return ret;
}
int main()
{
	n=read();m=read();
	f[0][1]=1;
	inv[0]=inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)F[i-1][j]=(F[i-1][j+1]+f[i-1][j])%mod;
		for(int j=i;j>=1;j--)
		{
			for(int k=0;k<i;k++)(h[i][j]+=(ll)F[k][j]*F[i-k-1][j]%mod)%=mod;
			g[i][j]=(h[i][j]-h[i][j+1]+mod)%mod;
		}
		for(int j=1;j<=i;j++)
			for(int x=n;x>=0;x--)
				for(int y=x+1;y>=1;y--)
					f[x][y]=tran(x,y,i,j);
	}
	printf("%d\n",f[n][m]);
	return 0;
}