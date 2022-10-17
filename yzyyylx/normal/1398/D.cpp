#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 210
#define M 998244353
using namespace std;

ll R,G,B,r[N],g[N],b[N],dp[N][N][N];

ll dfs(ll u,ll v,ll w)
{
	if((!u)+(!v)+(!w)>=2) return 0;
	if(dp[u][v][w]!=-1) return dp[u][v][w];
	ll res=0;
	if(u&&v) res=max(res,dfs(u-1,v-1,w)+r[u]*g[v]);
	if(u&&w) res=max(res,dfs(u-1,v,w-1)+r[u]*b[w]);
	if(v&&w) res=max(res,dfs(u,v-1,w-1)+g[v]*b[w]);
	return dp[u][v][w]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,t;
	cin>>R>>G>>B;
	for(i=1;i<=R;i++) scanf("%lld",&r[i]);
	for(i=1;i<=G;i++) scanf("%lld",&g[i]);
	for(i=1;i<=B;i++) scanf("%lld",&b[i]);
	sort(r+1,r+R+1);
	sort(g+1,g+G+1);
	sort(b+1,b+B+1);
	cout<<dfs(R,G,B);
}