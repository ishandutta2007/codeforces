#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0z3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;

ll T,n,m,num[N],qz[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]),qz[i]=qz[i-1]^num[i];
		map<ll,ll>mm;
		mm[0]=1;
		ll ans=n;
		for(i=1;i<=n;i++)
		{
			if(mm.count(qz[i]))
			{
				mm.clear();
				ans--;
			}
			mm[qz[i]]=1;
		}
		printf("%lld\n",ans);
	}
}