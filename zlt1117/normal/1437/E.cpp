#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
int n,k,now[maxn],a[maxn],b[maxn],dp[maxn],len=0;
bool vis[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),k=gi();
	FOR(i,1,n)a[i]=gi(),a[i]-=i;
	FOR(i,1,k)b[i]=gi(),vis[b[i]]=1;
	FOR(i,2,k)
	{
		if(a[b[i]]<a[b[i-1]])
		{
			printf("-1\n");
			exit(0);
		}
	}
}
inline void solve()
{
	int now1=-1e9;
	FOR(i,1,n)
	{
		if(a[i]<now1)continue;
		if(vis[i])now1=max(now1,a[i]);
		if(a[i]>=now[len])now[++len]=a[i];
		else
		{
			int pos=upper_bound(now+1,now+len+1,a[i])-now;
			now[pos]=a[i];
			if(vis[i])len=pos;
		}
	}
	printf("%d\n",n-len);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}