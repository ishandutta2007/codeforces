#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 
#define M 
#define MN 
using namespace std;

ll n,m,a[2],b[2];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,p;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		a[p&1]++;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&p);
		b[p&1]++;
	}
	cout<<min(a[0],b[1])+min(a[1],b[0]);
}