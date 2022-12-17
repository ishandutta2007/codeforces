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
const int maxn=1e5+5;
int now[maxn];
int id[maxn],id2[maxn],n,a[maxn],b[maxn],pos[maxn],pa[maxn],pb[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),id[i]=i;
	FOR(i,1,n)b[i]=gi(),id2[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]<a[y];});
	sort(id2+1,id2+n+1,[&](int x,int y){return b[x]<b[y];});
	FOR(i,1,n)pa[id[i]]=i;
	FOR(i,1,n)pb[id2[i]]=i;
}
bool vis[maxn];
int nxta[maxn],nxtb[maxn];
inline int get(int *a,int x)
{
	if(x==a[x])return x;
	return a[x]=get(a,a[x]);
}
inline void solve()
{
	FOR(i,1,n+1)nxta[i]=i,vis[i]=0;
	FOR(i,1,n+1)nxtb[i]=i;
	queue<int>q;
	q.push(id[n]);vis[id[n]]=vis[id2[n]]=1;
	q.push(id2[n]);nxta[n]=n+1;nxtb[n]=n+1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		int x=get(nxta,pa[u]);
		while(x<=n)
		{
			vis[id[x]]=1;q.push(id[x]);
			x=nxta[x]=get(nxta,x+1);
		}
		x=get(nxtb,pb[u]);
		while(x<=n)
		{
			vis[id2[x]]=1;q.push(id2[x]);
			x=nxtb[x]=get(nxtb,x+1);
		}
	}
	FOR(i,1,n)printf("%d",vis[i]);
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