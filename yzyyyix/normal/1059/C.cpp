#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1010
#define M
using namespace std;

ll n,cnt[N],now=1,mx[N];

inline void dfs(ll n,ll js)
{
	if(n==1)
	{
		printf("%lld ",js);
		return;
	}
	if(n==3)
	{
		printf("%lld %lld %lld\n",js,js,js*3);
		return;
	}
	ll i,j;
	for(i=1;i<=n;i+=2)
	{
		printf("%lld ",js);
	}
	dfs(n/2,js*2);
}

int main()
{
	ll i,j,ii,jj,t;
	cin>>n;
	dfs(n,1);
}