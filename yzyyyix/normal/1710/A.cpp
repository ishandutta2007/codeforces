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

ll T,n,m,K,num[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		ll tot=0;
		bool ok=0;
		scanf("%lld%lld%lld",&m,&n,&K);
		for(i=1;i<=K;i++) scanf("%lld",&num[i]);
		sort(num+1,num+K+1);
		for(i=1;i<=K;i++)
		{
			if(num[i]>=m*2)
			{
				tot+=(num[i]/m);
				if(num[i]>=3*m) ok=1;
			}
		}
		if(tot>=n && (ok || !(n&1)))
		{
			puts("Yes");
			continue;
		}
		tot=ok=0;
		for(i=1;i<=K;i++)
		{
			if(num[i]>=n*2)
			{
				tot+=(num[i]/n);
				if(num[i]>=3*n) ok=1;
			}
		}
		if(tot>=m && (ok || !(m&1)))
		{
			puts("Yes");
			continue;
		}
		puts("No");
	}
}