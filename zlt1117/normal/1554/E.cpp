//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline void chkmax(int &x,int y){if(x<y)x=y;}
inline void chkmin(int &x,int y){if(x>y)x=y;}
const int maxn=1e5+5,mod=998244353;
vector<int>e[maxn];
int n,ans[maxn],d[maxn],t[maxn];
inline int qpow(int x,int k)
{
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline void init()
{
	FOR(i,0,n)e[i].clear(),ans[i]=d[i]=t[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		e[u].pb(v),e[v].pb(u);
	}
}
inline bool dfs(int u,int x,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		if(!dfs(v,x,u))return false;
	}
	if(t[u]%x==0)t[fa]++;
	else if((t[u]+1)%x!=0)return false;
	else t[u]++;
	return true;
}
inline void solve()
{
	ans[1]=qpow(2,n-1);
	FOR(i,2,n-1)
	{
		if((n-1)%i==0)
		{
			FOR(j,0,n)t[j]=0;
			if(dfs(1,i,0))
			{
				int now=0;
				FOR(j,1,n)now=__gcd(now,t[j]);
				ans[i]=now==i;
			}
			ans[1]=(ans[1]-ans[i]+mod)%mod;
		}
	}
	FOR(i,1,n)printf("%d ",ans[i]);puts("");
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}