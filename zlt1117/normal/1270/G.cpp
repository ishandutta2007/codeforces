#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e6+5;
vector<int>vec[maxn];
int n,a[maxn],pre[maxn];
bool vis[maxn];
inline void init()
{
	FOR(i,1,n)vec[i].clear(),vis[i]=pre[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)vec[i].pb(i-a[i]);
}
inline bool dfs(int u)
{
	if(vis[u])
	{
		vector<int>ans;
		int x=u;
		while(1)
		{
			ans.pb(x);
			x=pre[x];
			if(x==u)break;
		}
		printf("%d\n",sz(ans));
		for(auto x:ans)printf("%d ",x);
		printf("\n");
		return 1;
	}
	vis[u]=1;
	for(auto x:vec[u])
	{
		pre[x]=u;
		if(dfs(x))return true;
	}
	return false;
}
inline void solve()
{
	FOR(i,1,n)if(!vis[i]){if(dfs(i))break;}
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();	
	}
	return 0;
}///