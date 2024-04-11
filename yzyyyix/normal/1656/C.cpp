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
map<ll,ll>cnt;

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		cnt.clear();
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			cnt[num[i]]++;
		}
		if(!cnt[1])
		{
			puts("YES");
			continue;
		}
		if(cnt[0] || cnt[2])
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[num[i]+1]) break;
		}
		if(i<=n) puts("NO");
		else puts("YES");
	}
}