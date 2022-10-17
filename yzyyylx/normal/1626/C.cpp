#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN
#define N 110
#define M 
using namespace std;
 
ll T,n,m,ans,mn,K[N],H[N],st[N],dp[N][N];
char str[N];
 
inline ll S(ll u){return (1+u)*u/2;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j,k,t;
	cin>>T;
	while(T--)
	{
		memset(dp,0x3f,sizeof(dp));
		ans=mn=INF;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&K[i]);
		for(i=1;i<=n;i++) scanf("%lld",&H[i]),st[i]=K[i]-H[i];
		for(i=1;i<=n;i++)
		{
			Min(mn,st[i]);
			Min(dp[i][0],S(K[i]-mn));
		}
		for(i=1;i<=n;i++)
		{
			mn=INF;
			if(H[i]<=K[i]-K[i-1]) for(j=0;j<i-1;j++) Min(dp[i][i-1],S(H[i])+dp[i-1][j]);
			for(j=i-1;j>=0;j--)
			{
				Min(mn,st[j+1]);
				t=mn;
				for(k=i+1;k<=n;k++)
				{
					if(st[k]<K[j]) break;
					Min(t,st[k]);
//					cout<<" "<<k<<" "<<t<<" "<<mn<<endl;
					Min(dp[k][j],dp[i][j]+S(K[k]-t)-S(K[i]-mn));
				}
//				Min(dp[i][i],dp[i][j]);
			}
		}
		for(i=0;i<n;i++) Min(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
}