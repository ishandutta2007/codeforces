#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
int h,n;
vector<int>e[maxn];
int vis[maxn];
int fa[maxn],dep[maxn],cnt[maxn];
inline void init()
{

}
inline void input()
{
	scanf("%d",&h);
	n=(1<<h)-1;
}
inline void dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(auto x:e[u])
	{
		if(x==fa[u])continue;
		fa[x]=u;
		dfs(x);
	}
}
inline int query(int u,int v,int w)
{
	printf("? %d %d %d\n",u,v,w);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
inline void explore(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
}
inline void solve()
{
	FOR(i,1,420)
	{
		int x=rd%n+1,y=rd%n+1,z=rd%n+1;
		while((x==y)||(x==z)||(y==z))x=rd%n+1,y=rd%n+1,z=rd%n+1;
		cnt[query(x,y,z)]++;
	}
	int maxv1=0,maxv2=0;
	FOR(i,1,n)
	{
		if(cnt[i]>=cnt[maxv1])maxv2=maxv1,maxv1=i;
		else if(cnt[i]>=cnt[maxv2])maxv2=i;
	}
	FOR(i,1,n)if(i!=maxv1&&i!=maxv2&&query(maxv1,maxv2,i)==i){explore(i),exit(0);}
}
int main()
{
	srand(time(NULL));
	init();
	input();
	solve();
	return 0;
}