//#pragma GCC optimize("Ofast")
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
const int maxn=1e5+5;
int n,m,a[maxn],x,id[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),x=gi();
	FOR(i,1,n)a[i]=gi(),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return a[x]>a[y];});
}
struct node{int id,val;};
inline bool operator < (const node &a,const node &b){return a.val==b.val?a.id<b.id:a.val>b.val;}
int ans[maxn];
inline void solve()
{
	priority_queue<node>pq;
	FOR(i,1,m)pq.push({i,0});
	FOR(i,1,n)
	{
		node x=pq.top();pq.pop();
		ans[id[i]]=x.id;
		x.val+=a[id[i]];
		pq.push(x);
	}
	puts("YES");
	FOR(i,1,n)printf("%d ",ans[i]);
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