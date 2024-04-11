#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 998244353
using namespace std;
 
ll T,n,m,sum[N],dp[2][N],qz[N];
 
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Add(ll &u,ll v){u=(u+v)%M;}
int main()
{
	ll i,j;
	bool now=1,cur=0;
	cin>>n>>m;
	dp[now][0]=1;
	for(ll len=m;len<=m+700;len++)
	{
		swap(now,cur);
		dp[now][0]=0;
		for(i=1;i<=n;i++)
		{
			if(i>=len) qz[i]=(qz[i-len]+dp[cur][i-len])%M;
			else qz[i]=0;
			dp[now][i]=qz[i];
			Add(sum[i],dp[now][i]);
		}
//		for(i=0;i<=n;i++) cout<<dp[now][i]<<" ";puts("");
	}
	for(i=1;i<=n;i++) printf("%lld ",sum[i]);
}