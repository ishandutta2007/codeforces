#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define pb push_back
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std; 
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=2e6+5;
int n,p[maxn],M=62;
ll val[maxn],k;
int a[maxn],b[maxn],siz[maxn];///maybe
int son[maxn][2];
inline void init()
{
	
}
inline void input()
{
	n=gi();scanf("%lld",&k);
	FOR(i,2,n)
	{
		p[i]=gi();scanf("%lld",&val[i]);
		val[i]^=val[p[i]];
	}
}
inline void solve()
{
	///at first we at position 0
	ll ans=0;
	for(int j=M;j>=0;--j)
	{
		FOR(i,0,n)son[i][0]=son[i][1]=siz[i]=0;///last 
		int cnt=0;ll sum=0;
		FOR(i,1,n)
		{
			int &p=son[a[i]][val[i]>>j&1];///the current position
			if(!p)p=++cnt;
			a[i]=p,siz[p]++;///the next position
		}
		///how many zeros
		FOR(i,1,n)sum+=siz[son[b[i]][val[i]>>j&1]];
		bool op=0;
		if(k>sum)k-=sum,ans|=1LL<<j,op=1;///right
		///if the next position(match) will be changed or not
		FOR(i,1,n)b[i]=son[b[i]][(val[i]>>j&1)^op];///the same or not
	}
	printf("%lld\n",ans);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}