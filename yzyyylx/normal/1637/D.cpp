#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 10000
#define N 110
#define M 
using namespace std;

ll T,n,m,ans,sum,tot,a[N],b[N];
bool dp[N][N*N];

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j,k;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		ans=tot=0,sum=INF;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]),ans+=a[i]*a[i],tot+=a[i];
		for(i=1;i<=n;i++) scanf("%lld",&b[i]),ans+=b[i]*b[i],tot+=b[i];
		ans*=n-2;
		dp[1][0]=1;
		for(i=1;i<=n;i++)
		{
			for(k=0;k<=MN;k++)
			{
				if(!dp[i][k]) continue;
				if(k+a[i]<=MN) dp[i+1][k+a[i]]=1;
				if(k+b[i]<=MN) dp[i+1][k+b[i]]=1;
			}
		}
		for(i=0;i<=MN;i++)
		{
			if(!dp[n+1][i]) continue;
//			cout<<" "<<i<<endl;
			Min(sum,i*i+(tot-i)*(tot-i));
		}
		printf("%lld\n",ans+sum);
	}
}