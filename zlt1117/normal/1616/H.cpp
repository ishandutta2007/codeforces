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
const int maxn=1.5e5+5,M=30,mod=998244353;
int n,x,a[maxn];
inline int qpow(int x,int k)
{
	if(x==0)return 1;
	int ret=1;
	while(k)
	{
		if(k&1)ret=1ll*ret*x%mod;
		k>>=1,x=1ll*x*x%mod;
	}
	return ret;
}
inline int count(int step,vector<int>&a,vector<int>&b,int x)
{
	if(!sz(a)||!sz(b))return 0;
	if(step==-1)return (1ll*(qpow(2,sz(a))-1)*(qpow(2,sz(b))-1))%mod;
	vector<int>pla,plb,pra,prb;
	for(int x:a)x>>step&1?pra.pb(x):pla.pb(x);
	for(int x:b)x>>step&1?prb.pb(x):plb.pb(x);
	if(x>>step&1)
	{
		int ret=0;
		int va=count(step-1,pla,prb,x);
		ret=1ll*va*(qpow(2,sz(plb))+qpow(2,sz(pra))-1)%mod;
		int vb=count(step-1,pra,plb,x);
		ret=(ret+1ll*vb*(qpow(2,sz(pla))+qpow(2,sz(prb))-1))%mod;
		ret=(ret+1ll*(qpow(2,sz(pla))-1)*(qpow(2,sz(plb))-1))%mod;
		ret=(ret+1ll*(qpow(2,sz(prb))-1)*(qpow(2,sz(pra))-1))%mod;
		ret=(ret+1ll*va*vb)%mod;
		ret=(ret%mod+mod)%mod;
		return ret;
	}
	else 
	{
		int ret=0;
		ret=count(step-1,pla,plb,x);
		ret+=count(step-1,pra,prb,x);
		return ret%mod;
	}
}
int ans;
inline void dfs(int step,vector<int>&now,int x)
{
	if(now.empty())return ;
	if(step==-1)
	{
		return ans=(ans+qpow(2,sz(now))-1+mod)%mod,void();
	}
	vector<int>pl,pr;
	FOR(i,0,sz(now)-1)
	{
		if(now[i]>>step&1)pr.pb(now[i]);
		else pl.pb(now[i]);
	}
	if(x>>step&1)
	{ 
		ans+=(qpow(2,sz(pl))-1);ans%=mod;
		ans+=(qpow(2,sz(pr))-1);ans%=mod;
		ans=(ans+mod)%mod;
		ans=(ans+count(step-1,pl,pr,x))%mod;
	}
	else
	{
		dfs(step-1,pl,x);
		dfs(step-1,pr,x);
	}
}
inline void init()
{

}
inline void input()
{
	n=gi(),x=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	vector<int>v;
	FOR(i,1,n)v.pb(a[i]);
	dfs(M-1,v,x);
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
/*
7 7
1 2 3 4 5 6 7
127
4 7 
2 3 4 5
*/