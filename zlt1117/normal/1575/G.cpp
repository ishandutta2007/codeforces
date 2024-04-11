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
const int maxn=1e5+5,M=1e5,mod=1e9+7;
int n,a[maxn];
bool vis[maxn];
vector<int>factors[maxn];
vector<int>p;
int phi[maxn];
inline void seive(int n)
{
	vis[1]=1;phi[1]=1;
	FOR(i,2,n)
	{
		if(!vis[i])p.pb(i),phi[i]=i-1;
		for(int x:p)
		{
			if(i*x>n)break;
			if(i%x)vis[i*x]=1,phi[i*x]=phi[i]*phi[x];
			else {vis[i*x]=1,phi[i*x]=phi[i]*x;break;}
		}
	}
	FOR(i,1,n)for(int j=i;j<=n;j+=i)factors[j].pb(i);
}
inline void init()
{

}
inline void input()
{
	seive(M);
	n=gi();FOR(i,1,n)a[i]=gi();
}
bool bk[maxn];
int cnt[maxn];
inline void solve()
{
	int ans=0;
	FOR(i,1,n)
	{
		int sum=0;
		vector<int>v;
		for(int j=i;j<=n;j+=i)
		{
			for(int x:factors[a[j]])
			{
				if(!bk[x])bk[x]=1,v.pb(x);
				cnt[x]++;
			}
		}
		for(int x:v)sum=(sum+1ll*cnt[x]*cnt[x]*phi[x])%mod;
		for(int x:v)bk[x]=0,cnt[x]=0;
		ans=(ans+1ll*sum*phi[i])%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}