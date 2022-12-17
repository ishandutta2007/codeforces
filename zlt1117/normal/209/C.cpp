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
int n,m;
int d[maxn],fa[maxn];
inline int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
inline void merge(int u,int v){fa[get(u)]=get(v);}
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		d[u]++,d[v]++;
		merge(u,v);
		vis[get(u)]=vis[get(v)]=1;
	}
}
int cnt[maxn];
inline void solve()
{
	int ans=0;
	FOR(i,1,n)cnt[get(i)]+=d[i]&1;
	int counter=0;vis[1]=1;
	FOR(i,1,n)
	{
		if(get(i)==i&&vis[i])
		{
			++counter;
			ans+=cnt[i]==0?1:cnt[i]/2;
		}
	}
	if(counter==1)printf("%d\n",cnt[get(1)]/2);
	else printf("%d\n",ans);
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