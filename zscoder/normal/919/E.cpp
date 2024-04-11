#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

ll MOD;

int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}

int mult(int a, int b)
{
	return (a*1LL*b)%MOD;
}

int modpow(int a, int b)
{
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a); b>>=1;
	}
	return r;
}

int inv(int a)
{
	return modpow(a,MOD-2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a,b,x; cin>>a>>b>>MOD>>x;
	ll ans=0;
	for(ll i=0;i<=min(x,MOD-2);i++)
	{
		//congruent to i mod MOD - 1
		ll v = mult(b, inv(modpow(a,i)));
		//congruent to v mod MOD
		v %= MOD;
		if(v<0) v+=MOD;
		ll tmp = MOD*ll(i - v) + v;
		tmp%=(MOD*(MOD-1));
		if(tmp<0) tmp+=(MOD*(MOD-1));
		if(x>=tmp)
		{
			ans += (x - tmp)/(MOD*(MOD-1)) + 1;
		}
	}
	if(b==0) ans--;
	cout<<ans<<'\n';
}