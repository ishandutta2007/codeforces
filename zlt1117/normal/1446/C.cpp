#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
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
map<int,int>mp;
const int maxn=2e5+5,maxt=30,maxm=7e6+5;
int root,n,a[maxn],siz[maxm];
int son[maxm][2],dp[maxm];
int tot;
inline void insert(int &u,int val,int step)
{
	if(!u)u=++tot;
	if(step==-1)return siz[u]=dp[u]=1,void();
	if((val>>step)&1)insert(son[u][1],val,step-1);
	else insert(son[u][0],val,step-1);
}
int ans;
inline void dfs(int u,int step)
{
	if(step==-1)return ;
	if(son[u][0])dfs(son[u][0],step-1),siz[u]+=siz[son[u][0]];
	if(son[u][1])dfs(son[u][1],step-1),siz[u]+=siz[son[u][1]];
	dp[u]=max(dp[son[u][0]]+min(siz[son[u][1]],1),dp[son[u][1]]+min(siz[son[u][0]],1));
}
inline void init()
{

}
inline void input()
{///change maxt
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	FOR(i,1,n)insert(root,a[i],maxt);
	dfs(root,maxt);
	printf("%d\n",n-dp[root]);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}