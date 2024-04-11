#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=105,mod=1e9+7;
int n;
vector<int>a[maxn];
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*x*ret%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline int det(vector<int>*a)
{
	int ans=1;
	FOR(i,1,n-1)
	{
		int now=i;
		FOR(j,i,n-1)if(a[j][i]!=0){now=j;break;}
		if(now!=i)swap(a[now],a[i]),ans=(mod-ans)%mod;
		if(a[i][i]==0)return 0;
		ans=1ll*ans*a[i][i]%mod;
		int inv=qpow(a[i][i],mod-2);
		FOR(j,i,n-1)a[i][j]=1ll*a[i][j]*inv%mod;
		FOR(j,i+1,n-1)
		{
			int now=a[j][i];
			FOR(k,i,n-1)a[j][k]=(a[j][k]-1ll*now*a[i][k]%mod+mod)%mod;
		}
	}
	return ans;
}
inline vector<int>lagrange(vector<int>x,vector<int>y)
{
	int n=sz(x);
	vector<int>a(n+1),b(n+1),c(n+1),ans(n);
	FOR(i,0,n-1)///
	{
		a[i]=1;
		FOR(j,0,n-1)if(i!=j)a[i]=1ll*a[i]*(x[i]-x[j]+mod)%mod;
		a[i]=1ll*qpow(a[i],mod-2)*y[i]%mod;
	}
	b[0]=1;///
	FOR(i,0,n-1)
	{
		for(int j=n;j>=1;--j)b[j]=(b[j-1]-1ll*b[j]*x[i]%mod+mod)%mod;
		b[0]=1ll*b[0]*(mod-x[i])%mod;
	}
	FOR(i,0,n-1)
	{
		c[0]=1ll*b[0]*qpow(mod-x[i],mod-2)%mod;
		int temp=qpow(x[i],mod-2);
		FOR(j,1,n-1)c[j]=1ll*temp*(c[j-1]-b[j]+mod)%mod;
		FOR(j,0,n-1)ans[j]=(ans[j]+1ll*a[i]*c[j]%mod)%mod;
	}
	return ans;
}
bool vis[maxn][maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		vis[u][v]=vis[v][u]=1;
	}
}
vector<int>x,y;
inline void solve()
{
	FOR(i,1,n)a[i].resize(n+1);
	FOR(k,1,n)///
	{
		x.pb(k);
		FOR(i,1,n)FOR(j,1,n)a[i][j]=0;
		FOR(i,1,n)
		{
			FOR(j,i+1,n)
			{
				if(vis[i][j])
				{
					a[i][i]+=k;
					a[i][j]+=mod-k;
					a[j][i]+=mod-k;
					a[j][j]+=k;
				}
				else
				{
					a[i][i]+=1;
					a[i][j]+=mod-1;
					a[j][i]+=mod-1;
					a[j][j]+=1;
				}
			}
		}
		//printf("%d\n",k);
		//FOR(i,1,n)FOR(j,1,n)printf("a[%d][%d]=%d\n",i,j,a[i][j]);
		//puts("");
		y.pb(det(a));
	}
	//FOR(i,0,n-1)printf("%d %d\n",x[i],y[i]);
	vector<int>ans=lagrange(x,y);
	FOR(i,0,n-1)printf("%d ",ans[i]);
	puts("");
}
int main()
{
	//freopen("1.in","r",stdin);
	input();
	solve();
	return 0;
}