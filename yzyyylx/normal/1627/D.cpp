#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 1000000
#define N 1001000
#define M
using namespace std;
 
ll T,n,m,ans,ds[N];
bool have[N];
 
ll gcd(ll u,ll v){return !v?u:gcd(v,u%v);}
int main()
{
	ll i,j,a,b,p,q,t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		have[t]=1;
	}
	for(i=MN;i>=1;i--)
	{
		ll g=0;
		for(j=i;j<=MN;j+=i) if(have[j]) g=gcd(g,j);
		if(g==i) have[i]=1;
	}
	for(i=1;i<=MN;i++) if(have[i]) ans+=have[i];
	cout<<ans-n;
}