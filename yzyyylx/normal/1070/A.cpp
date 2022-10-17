#pragma GCC optimize("3,Ofast,inline")
#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define N 510
#define M 5010
using namespace std;

int d,s,len[N][M];
bool vis[N][M];
int dp[N][M];
P nxt[N][M],ans;

int dfs(int ys,int sum)
{
//	cout<<ys<<" "<<sum<<endl;
	if(!sum&&!ys) return 0;
	if(vis[ys][sum]) return dp[ys][sum];
	vis[ys][sum]=1;
	dp[ys][sum]=INF;
	int i,tmp;
	for(i=min(sum,9);i>=0;i--)
	{
		tmp=dfs((ys*10+i)%d,sum-i);
		if(tmp>=INF) continue;
		if(dp[ys][sum]==INF)
		{
			dp[ys][sum]=tmp+1;
			nxt[ys][sum]=mp((ys*10+i)%d,sum-i);
			continue;
		}
		if(tmp+1<=dp[ys][sum])
		{
			dp[ys][sum]=tmp+1;
			nxt[ys][sum]=mp((ys*10+i)%d,sum-i);
		}
	}
	return dp[ys][sum];
}

inline void out(int u,int v)
{
	if(!v&&!u) return;
	printf("%d",v-nxt[u][v].se);
	out(nxt[u][v].fi,nxt[u][v].se);
}

int main()
{
	int i,j,tmp,l=INF,t;
	cin>>d>>s;
	for(i=min(s,9);i>=1;i--)
	{
		tmp=dfs(i%d,s-i);
		if(tmp<=l)
		{
			t=i;
			l=tmp;
			ans=mp(i%d,s-i);
		}
	}
	if(l==INF) puts("-1");
	else
	{
		cout<<t;
		out(ans.fi,ans.se);
	}
}