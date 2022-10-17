#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 
#define N 200100
#define M 
using namespace std;

ll T,n,m,num[N];
P mn,mx;

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		mn=mp(INF,0);
		mx=mp(-INF,0);
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			mn=min(mn,mp(num[i],i));
			mx=max(mx,mp(num[i],i));
		}
		printf("%lld %lld\n",mn.se,mx.se);
	}
}