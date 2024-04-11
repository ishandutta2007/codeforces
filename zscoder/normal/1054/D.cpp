#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
map<int,int> ma;

ll c2(ll x)
{
	return (x*(x+1))/2;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,k; cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int bit = (1<<k)-1;
	for(int i=0;i<=n;i++) 
	{
		ma[a[i]]++; 
		ma[a[i]^bit]++; ma[a[i]^bit]--;
	}
	ll mn = 0;
	for(ii X:ma)
	{
		int v=X.fi;
		if(v<(bit^v))
		{
			int x = ma[v]; int y = ma[bit^v];
			int half = (x+y)/2; int half2 = x+y-half;
			mn += c2(half) + c2(half2);
		}
	}
	ll ans = c2(n+1) - mn;
	cout<<ans<<'\n';
}