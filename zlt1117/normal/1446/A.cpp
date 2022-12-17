#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
int n,T;
ll W;
struct node
{
	int x,w;
	inline bool operator<(const node &b)const
	{
		return w>b.w;
	}
}a[maxn];
bool vis[maxn];
inline void init()
{
	FOR(i,1,n)vis[i]=0;
}
inline void input()
{
	n=gi();scanf("%lld",&W);
	FOR(i,1,n)
	{
		a[i].x=i,a[i].w=gi();
	}
	sort(a+1,a+n+1);
	ll now=0;int pos=1;
	int cnt=0;
	while(pos<=n&&now<=W)
	{
		if(now+a[pos].w>W)pos++;
		else 
		{
			cnt++;
			now+=a[pos].w;
			vis[a[pos].x]=1;
			if(now>=(W+1)/2&&now<=W)
			{
				printf("%d\n",cnt);
				FOR(i,1,n)if(vis[i])printf("%d ",i);
				printf("\n");
				return ;
			}
			pos++;
		}
	}
	printf("-1\n");
}
inline void solve()
{

}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}