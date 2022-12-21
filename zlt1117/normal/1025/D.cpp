#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define pb push_back
#define sz(x) (int)(x.size())
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
const int maxn=705;
bitset<maxn>dp[maxn][maxn];
bitset<maxn>vis[maxn][maxn];
int n,a[maxn];
inline void init()
{

}
inline bool dfs(int x,int l,int r)///root is x and left=l right=r
{
	if(l>r)return 1;
	if(vis[x][l][r])return dp[x][l][r];
	vis[x][l][r]=1;
	if(l==r&&__gcd(a[x],a[l])!=1)return dp[x][l][r]=1;
	FOR(k,l,r)
	if(__gcd(a[k],a[x])!=1&&dfs(k,l,k-1)&&dfs(k,k+1,r))
	return dp[x][l][r]=1;
	return dp[x][l][r]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1);
	printf(dfs(0,1,n)?"Yes\n":"No\n");
}
inline void solve()
{

}
int main()
{
	init();
	input();
	solve();
	return 0;
}