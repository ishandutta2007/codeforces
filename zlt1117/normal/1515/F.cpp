//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
const int maxn=3e5+5;
vector<pair<int,int>>e[maxn];
int fa[maxn],n,m,x;
ll sum,a[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),x=gi();
	FOR(i,1,n)a[i]=gi(),sum+=a[i];
}
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
vector<int>answers,answers2;
inline void dfs(int u,int fa,int i)
{
	for(auto x:e[u])
	{
		int i=x.first,v=x.second;
		//cerr<<u<<' '<<v<<' '<<i<<endl;
		if(v==fa)continue;
		dfs(v,u,i);
	}
	if(u==1)return ;
	if(a[u]>=x)answers.pb(i),a[fa]+=a[u]-x;
	else answers2.pb(i);
}
inline void solve()
{
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		if(get(u)!=get(v))
		{
			e[u].pb({i,v});
			e[v].pb({i,u});
			fa[get(u)]=get(v);
		}
	}
	if(sum<1ll*x*(n-1))puts("NO");
	else
	{
		dfs(1,0,0);
		puts("YES");
		for(int x:answers)printf("%d\n",x);reverse(answers2.begin(),answers2.end());
		for(int x:answers2)printf("%d\n",x);
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