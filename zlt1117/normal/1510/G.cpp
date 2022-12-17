//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=105;
int dep[maxn];
int n,k;
int p[maxn],siz[maxn];
vector<int>e[maxn];
bool vis[maxn];
vector<int>ans;
int nxt[maxn];
inline void init()
{
	FOR(i,1,n)e[i].clear(),dep[i]=0;
	FOR(i,1,n)vis[i]=0,siz[i]=0,dep[i]=0,nxt[i]=0;
}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,2,n)p[i]=gi(),e[p[i]].pb(i),dep[i]=dep[p[i]]+1;
	for(int i=n;i>=1;--i)siz[i]++,siz[p[i]]+=siz[i];
}
inline void color(int x,int &k)
{
	ans.pb(x);k--;
	if(k==0)return ;
	for(auto v:e[x])
	{
		if(vis[v])continue;
		color(v,k);
		ans.pb(x);
		if(k==0)return ;
	}
}
inline void solve()
{
	ans.clear();
	PII best={0,0};
	FOR(i,1,n)best=max(best,{dep[i],i});
	int x=best.second;
	int len=0;
	while(x)vis[x]=1,nxt[p[x]]=x,x=p[x],len++;
	x=1;len--;
	if(k<=len)
	{
		ans.pb(x);
		k--;
		FOR(i,1,k)
		{
			x=nxt[x];
			ans.pb(x);
		}
	}
	else
	{
		len++;
		while(k>len)
		{
			len--;k--;
			ans.pb(x);
			for(auto v:e[x])
			{
				if(v==nxt[x])continue;
				int res=k-len,res2=k-len;
				if(k>len)color(v,res),ans.pb(x);
				k-=res2-res;
			}
			x=nxt[x];
		}
//		for(int x:ans)cerr<<x<<' ';
//		cerr<<endl;
		while(x)ans.pb(x),x=nxt[x];
	}
	printf("%d\n",sz(ans)-1);
	for(int x:ans)printf("%d ",x);
	puts("");
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
/*
6
1
6 5
1 1 2 2 2
*/