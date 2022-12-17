#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define pb push_back
#define PII pair<int,int>
#define db double
#define ll long long
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
#define poly vector<int> 
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
const int maxn=155;
const ll inf=1e18;
int n,m,len;
struct Matrix
{
	bitset<maxn>a[maxn];
	inline void clear(){FOR(i,1,n)a[i]=0;}
	inline void init(){clear();FOR(i,1,len)a[i][i]=1;}
}now,g;
inline Matrix operator * (const Matrix a,const Matrix b)
{
	Matrix c;c.clear();
	FOR(i,1,len)
	{
		FOR(k,1,len)
		{
			if(a.a[i][k])c.a[i]|=b.a[k];
		}
	}
	return c;
}
ll dis[maxn][maxn];
ll ans=inf;
struct edge{int u,v,w;}e[maxn];
inline void init()
{
	
}
inline void input()
{
	n=gi(),m=gi();
	len=n;
	FOR(i,1,m)e[i].u=gi(),e[i].v=gi(),e[i].w=gi();
	sort(e+1,e+m+1,[&](edge a,edge b){return a.w<b.w;});
	FOR(i,1,n)now.a[i][i]=1;
}
inline Matrix qpow(Matrix a,int k)
{
	Matrix ret;ret.init();
	while(k)
	{
		if(k&1)ret=ret*a;
		a=a*a;k>>=1;
	}
	return ret;
}
inline void solve()
{
	int last=0;
	FOR(i,1,n)FOR(j,1,n)dis[i][j]=i==j?0:inf;
	FOR(i,1,m)
	{
		now=now*qpow(g,e[i].w-last);
		last=e[i].w;
		g.a[e[i].u][e[i].v]=1;///change 
		///u->v
		FOR(u,1,n)FOR(v,1,n)dis[u][v]=min(dis[u][e[i].u]+dis[e[i].v][v]+1,dis[u][v]);
		FOR(j,1,n)if(now.a[1][j])ans=min(ans,e[i].w+dis[j][n]); 
	}
	if(ans==inf)printf("Impossible\n");
	else printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}