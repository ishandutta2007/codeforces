#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
ll mod=1000000007;
int a[35];
int b[35];
int c[35];
ll f[2][2][2][35];
ll g[2][2][2][35];
//iabc 
ll solve(ll x,ll y,ll k)
{
	if(x<0||y<0)
		return 0;
	//0~x,0~y,i^j<=k
	int i;
	int mx=1;
	for(i=1;i<=32;i++)
	{
		a[i]=x&1;
		b[i]=y&1;
		c[i]=k&1;
		x>>=1;
		y>>=1;
		k>>=1;
	}
	i--;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[1][1][1][i]=1;
	int i1,j1,k1,i2,j2,k2;
	for(;i;i--)
	{
		for(i1=0;i1<=1;i1++)
			for(j1=0;j1<=1;j1++)
				for(k1=0;k1<=1;k1++)
					for(i2=0;i2<=(i1?a[i]:1);i2++)
						for(j2=0;j2<=(j1?b[i]:1);j2++)
						{
							if(k1&&((i2^j2)>c[i]))
								continue;
							k2=k1&((i2^j2)==c[i]);
							f[i1&&(a[i]==i2)][j1&&(b[i]==j2)][k2][i-1]+=f[i1][j1][k1][i];
							g[i1&&(a[i]==i2)][j1&&(b[i]==j2)][k2][i-1]+=g[i1][j1][k1][i]*2+f[i1][j1][k1][i]*(i2^j2);
							f[i1&&(a[i]==i2)][j1&&(b[i]==j2)][k2][i-1]%=mod;
							g[i1&&(a[i]==i2)][j1&&(b[i]==j2)][k2][i-1]%=mod;
						}
	}
	ll ans=0;
	for(i1=0;i1<=1;i1++)
		for(j1=0;j1<=1;j1++)
			for(k1=0;k1<=1;k1++)
			{
				ans+=f[i1][j1][k1][0]+g[i1][j1][k1][0];
				ans%=mod;
			}
	return ans;
}
int main()
{
//	freopen("cf809c.in","r",stdin);
//	freopen("cf809c.out","w",stdout);
	int q;
	scanf("%d",&q);
	ll x,y,x1,x2,y1,y2,k;
	int i;
	for(i=1;i<=q;i++)
	{
//		scanf("%I64d%I64d%I64d",&x,&y,&k);
//		printf("%I64d\n",solve(x,y,k));
		scanf("%I64d%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2,&k);
		ll ans=0;
		ans+=solve(x2-1,y2-1,k-1);
		ans-=solve(x1-2,y2-1,k-1);
		ans-=solve(x2-1,y1-2,k-1);
		ans+=solve(x1-2,y1-2,k-1);
		ans=(ans%mod+mod)%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}