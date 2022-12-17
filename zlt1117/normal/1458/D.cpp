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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e6+5;
vector<pair<int,int>>e[maxn];
int n,pre[maxn],cur[maxn];
bool vis[maxn];
char s[maxn];
vector<int>answers;
inline void init()
{
	FOR(i,0,n*2)e[i].clear(),pre[i]=0,cur[i]=0,vis[i]=0;
	answers.clear();
}
inline void input()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n)pre[i]=pre[i-1]+(s[i]=='1'?1:-1),e[pre[i-1]+n].pb({pre[i]+n,i});
}
inline void dfs(int u)
{
	for(int &i=cur[u];i<sz(e[u]);++i)
	{
		if(vis[e[u][i].second])continue;
		vis[e[u][i].second]=1;
		int v=e[u][i].first;
		dfs(v);
		answers.pb(v==u-1?0:1);
	}
}
inline void solve()
{
	FOR(i,0,2*n)sort(e[i].begin(),e[i].end());
	dfs(n);
	reverse(answers.begin(),answers.end());
	for(int x:answers)printf("%d",x);
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