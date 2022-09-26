#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int MOD=1e9+7;
ll add(ll a, ll b)
{
	a+=b;
	a%=MOD;
	if(a<0) a+=MOD;
	return a;
}

ll mult(ll a, ll b)
{
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}

struct fin {
	vector<ll> T;
	fin() {}
	fin(ll N) {T.resize(N+10, 0);}

	ll lastone(ll x) {return x&(x^(x-1));}

	void put(ll pos, ll val) {
		for(ll i = pos+1; i < (ll)T.size(); i += lastone(i))
			T[i] =add(T[i], val);
	}

	ll get(ll pos) {
		ll ret = 0;
		for(ll i = pos+1; i > 0; i -= lastone(i)) ret=add(ret, T[i]);
		return ret;
	}
};

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	ll N; cin >> N;
	vector<ll> V(N);
	vector<ll> pr(N);
	fin F_sumc(N+1), F_sum(N+1);
	ll ans = 0;
	map<int,int> ma;
	for(ll i=0;i<N;i++)
	{
		cin>>V[i];
	}
	for(int i=0;i<N;i++) ma[V[i]]=1;
	int cnt=0;
	for(auto X:ma)
	{
		ma[X.fi]=++cnt;
	}
	for(ll i=0;i<N;i++)
	{
		ll v = V[i];
		pr[i] = i+1;
		ll x = mult(F_sumc.get(ma[V[i]]),v) + F_sum.get(N+1)-F_sum.get(ma[V[i]]);
		x%=MOD;
		if(x<0) x+=MOD;
		ans += mult(x,(N-i));
		ans += mult(V[i],mult((N-i),(i+1)));
		ans%=MOD;
		if(ans<0) ans+=MOD;
		F_sumc.put(ma[V[i]], pr[i]);
		F_sum.put(ma[V[i]], mult(V[i],pr[i]));
	}
	cout<<ans<<'\n';
	return 0;
}