//#pragma GCC optimize(4)
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
const int maxn=2e5+5;
vector<int>vec[maxn];
int n,w[maxn],ind[maxn];
ll ans;
vector<int>vv;
inline void init()
{
	vv.clear();
	ans=0;
	FOR(i,1,n)vec[i].clear(),ind[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)w[i]=gi(),ans+=w[i];
	FOR(i,1,n-1)
	{
		int u=gi(),v=gi();
		ind[u]++,ind[v]++;
		vec[u].pb(v);
		vec[v].pb(u);
	}
}
inline void solve()
{
	queue<int>q;
	FOR(i,1,n)if(ind[i]==1)q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:vec[x])
		{
			if(ind[v]>=2)
			{
				vv.pb(w[v]);
				ind[v]--;
				if(ind[v]==1)q.push(v);
			}
		}
	}
	sort(vv.begin(),vv.end(),greater<int>());
	printf("%lld ",ans);
	for(auto x:vv)
	{
		ans+=x;
		printf("%lld ",ans);
	}
	printf("\n");
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
}