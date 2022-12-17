#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
const int maxn=2e5+5;
vector<int>e[maxn];
int vis[maxn];
int s,n,m,pre[maxn];
inline void input()
{
	n=gi(),m=gi();s=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		e[u].pb(v);
	}
}
inline void solve()
{
	queue<int>q;
	int cnt=0;
	for(int x:e[s])vis[x]=++cnt,q.push(x),pre[x]=s;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:e[u])
		{
			if(v==s)continue;
			if(!vis[v])q.push(v),vis[v]=vis[u],pre[v]=u;
			else if(vis[v]!=vis[u])
			{
				vector<int>patha,pathb;
				for(int x=v;x;x=pre[x])patha.pb(x);
				pathb.pb(v);
				for(int x=u;x;x=pre[x])pathb.pb(x);
				reverse(patha.begin(),patha.end());
				reverse(pathb.begin(),pathb.end());
				puts("Possible");
				printf("%d\n",sz(patha));
				for(int x:patha)printf("%d ",x);
				puts("");
				printf("%d\n",sz(pathb));
				for(int x:pathb)printf("%d ",x);
				puts("");
				return ;
			}
		}
	}
	puts("Impossible");
}
int main()
{
	input();
	solve();
	return 0;
}