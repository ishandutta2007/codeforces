#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=1e6+5,M=1e6;
int fa[maxn],mind[maxn];
bool vis[maxn];
int pri[maxn],cnt;
inline void init()
{
	vis[0]=vis[1]=1;
	FOR(i,2,maxn-1)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
			mind[i]=i;
		}
		FOR(j,1,cnt)
		{
			int x=pri[j];
			if(1ll*i*x>=maxn)break;
			if(i%x){vis[i*x]=1;mind[i*x]=x;}
			else {vis[i*x]=1;mind[i*x]=x;break;}
		}
	}
}
inline vector<int> division(int x)
{
	vector<int>ret;
	while(x!=1)
	{
		ret.pb(mind[x]);
		x/=mind[x];
	}
	return ret;
}
int n,Q,a[maxn],s,t;
set<int>S[maxn];
int now[maxn];
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void input()
{
	n=gi(),Q=gi();
	FOR(i,1,n)a[i]=gi(),fa[i]=i;
	FOR(i,1,n)
	{
		vector<int>d=division(a[i]);
		//auto ed=unique(d.begin(),d.end());
		for(auto x=d.begin();x!=d.end();++x)
		{
			int v=*x;
			if(!now[v])now[v]=get(i);
			else fa[get(now[v])]=get(i);
		}
	}
	FOR(i,1,n)fa[i]=get(i);
}
inline void solve()
{
	//FOR(i,1,n)printf("fa[%d]=%d\n",i,get(i));
	FOR(i,1,n)
	{
		vector<int>d=division(a[i]+1);
		//auto ed=unique(d.begin(),d.end());
		for(auto v=d.begin();v!=d.end();++v)
		{
			int x=*v;
			if(now[x]&&get(now[x])!=get(i))
			{
				S[get(now[x])].insert(get(i));
				//S[get(i)].insert(get(now[x]));
			}
		}
		for(int x:d)for(int y:d)S[get(now[x])].insert(get(now[y]));
	}
	FOR(i,1,Q)
	{
		s=gi(),t=gi();
		if(get(s)==get(t))puts("0");
		else if(S[get(s)].count(get(t))||S[get(t)].count(get(s)))puts("1");
		else puts("2");
	}
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