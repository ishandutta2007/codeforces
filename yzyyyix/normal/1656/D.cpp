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
inline ll get(ll u){return (ll)sqrt(u)+((ll)sqrt(u)*(ll)sqrt(u)!=u);}
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		n<<=1;
		for(m=n;(m%2)==0;m>>=1);
		if(m>1 && m<get(n+m)) printf("%lld\n",m);
		else if(n/m>1 && n/m<get(n+n/m)) printf("%lld\n",n/m);
		else puts("-1");
	}
}