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
map<ll,bool>mm;

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		mm.clear();
		bool ok=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			ok|=(mm.count(num[i]-m)|mm.count(num[i]+m));
			mm[num[i]]=1;
		}
		puts(ok?"YES":"NO");
	}
}