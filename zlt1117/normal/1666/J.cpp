#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()
#define mk make_pair
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
const int maxn=205;
ll n,c[maxn][maxn],dp[maxn][maxn],best[maxn][maxn],pre[maxn][maxn];
inline void input()
{
	n=gi();
	FOR(i,1,n)FOR(j,1,n)c[i][j]=gi(),pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+c[i][j];
}
int fa[maxn];
inline void dfs(int l,int r,int t)
{
	if(l>r)return ;
	int now=best[l][r];
	fa[now]=t;
	dfs(l,now-1,now),dfs(now+1,r,now);
}
bool vis[maxn][maxn];
inline ll get(int a,int b,int c,int d)
{
	a--,b--;
	return pre[c][d]-pre[a][d]-pre[c][b]+pre[a][b];
}
//inline ll cost(int l,int k,int r)
//{
//	ll ans=get(l,k+1,k,r)+get(k,l,r,k-1);
//	return ans;
//}
inline void DP(int l,int r)
{
	if(l>r)return dp[l][r]=0,void();
	if(vis[l][r]||l>r)return ;
	FOR(k,l,r)DP(l,k-1),DP(k+1,r);
	FOR(k,l,r)
	{
		if(dp[l][k-1]+dp[k+1][r]<dp[l][r])
		{
			best[l][r]=k;
			dp[l][r]=dp[l][k-1]+dp[k+1][r];
		}
	}
	dp[l][r]+=get(l,1,r,l-1)+get(l,r+1,r,n);
	vis[l][r]=1;
}
inline void solve()
{
	memset(dp,0x3f,sizeof(dp));
	DP(1,n);
	//cerr<<dp[1][n]<<endl;
	dfs(1,n,0);
	FOR(i,1,n)printf("%d ",fa[i]);
	puts("");
}
int main()
{
	input();
	solve();
	return 0;
}