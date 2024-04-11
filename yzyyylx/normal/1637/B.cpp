#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;

ll T,n,m,mx[N],mn[N],num[N],ans;

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		for(i=1;i<=n;i++)
		{
			ans+=i*(n-i+1);
			if(!num[i]) ans+=i*(n-i+1);
		}
		printf("%lld\n",ans);
	}
}