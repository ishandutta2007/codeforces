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
#define mk make_pair
#define iter set<int>::iterator
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
const int maxn=205;
struct node
{
	int x,y;
}a[maxn];
int n,k;
bool vis[maxn];
inline void init()
{
	memset(vis,0,sizeof(vis));
}
inline void input()
{
	n=gi();k=gi();
	FOR(i,1,k)a[i].x=gi(),a[i].y=gi(),vis[a[i].x]=vis[a[i].y]=1;
}
inline bool inter(node x,node y)
{
	if(x.x>y.x)swap(x,y);
	return y.x>x.x&&y.x<x.y&&x.y<y.y;
}
inline void solve()
{
	vector<int>nvis;
	FOR(i,1,2*n)if(!vis[i])nvis.pb(i);
	int t=n-k;
	FOR(i,0,sz(nvis)-1)
	{
		a[++k].x=nvis[i];
		a[k].y=nvis[i+t];
		if(k==n)break;
	}
	FOR(i,1,n)if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	int ans=0;
	FOR(i,1,n)
	{
		FOR(j,i+1,n)
		{
			ans+=inter(a[i],a[j]);
		}
	}
	printf("%d\n",ans);
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