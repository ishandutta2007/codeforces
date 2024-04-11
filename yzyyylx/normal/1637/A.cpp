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

ll T,n,m,mx[N],mn[N],num[N];

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		mx[1]=num[1],mn[n]=num[n];
		for(i=2;i<=n;i++) mx[i]=max(mx[i-1],num[i]);
		for(i=n-1;i>=1;i--) mn[i]=min(mn[i+1],num[i]);
		for(i=1;i<n;i++) if(mx[i]>mn[i+1]) break;
		if(i<n) puts("YES");
		else puts("NO");
	}
}