#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
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
const int maxn=5e5+5;
int n,a[maxn];
deque<int>q;
int vis[maxn];
bool ok[maxn];
inline void init()
{
	FOR(i,1,n)a[i]=vis[i]=ok[i]=0;
	while(!q.empty())q.pop_back();
}
inline void input()
{
	n=gi();
	ok[1]=1;
	FOR(i,1,n)a[i]=gi(),vis[a[i]]++,q.push_back(a[i]);
	FOR(i,1,n)if(!vis[i]){ok[1]=0;break;}
}
inline void solve()
{
	FOR(i,1,n)
	{
		if(vis[i]==0)break;
		ok[n-i+1]=1;
		if(vis[i]>=2)break;
		else if(q.empty())break;
		if(q.front()!=i&&q.back()!=i)break;
		if(q.front()==i)q.pop_front();
		else q.pop_back();
	}
	FOR(i,1,n)if(ok[i])putchar('1');else putchar('0');
	putchar('\n');
}
int main()
{
	int T=gi();
	while(T--)
	{		
		init();
		input();
		solve();
	}
	return 0;
}