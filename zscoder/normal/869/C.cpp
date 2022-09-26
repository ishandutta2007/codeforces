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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct Combi
{
	vector<ll> fact;
	vector<ll> ifact;
	vector<ll> inv;
	vector<ll> pow2;
	const int MOD = 998244353;
	ll add(ll a, ll b)
	{
		a+=b;
		while(a>=MOD) a-=MOD;
		return a;
	}
	ll mult(ll a, ll b)
	{
		return (a*b)%MOD;
	}
	ll modpow(ll a, ll b)
	{
		ll r=1;
		while(b)
		{
			if(b&1) r=mult(r,a);
			a=mult(a,a);
			b>>=1;
		}
		return r;
	}
	ll choose(ll a, ll b)
	{
		if(a<b) return 0;
		if(b==0) return 1;
		if(a==b) return 1;
		return mult(fact[a],mult(ifact[b],ifact[a-b]));
	}
	ll inverse(ll a)
	{
		return modpow(a,MOD-2);
	}
	void init(int _n)
	{
		fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
		fact.resize(_n+1);
		ifact.resize(_n+1);
		inv.resize(_n+1);
		pow2.resize(_n+1);
		pow2[0]=1;
		ifact[0]=1;
		fact[0]=1;
		for(int i=1;i<=_n;i++)
		{
			pow2[i]=add(pow2[i-1],pow2[i-1]);
			inv[i] = inverse(i);
			fact[i]=mult(fact[i-1],i);
			ifact[i]=mult(ifact[i-1],inv[i]);
		}
	}
};

Combi combi;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, c; cin>>a>>b>>c;
	combi.init(5011);
	ll ans[3]={0,0,0};
	for(int i = 0; i <= b; i++)
	{
		ll tmp = combi.choose(b,i);
		tmp = combi.mult(tmp, combi.fact[i]);
		tmp = combi.mult(tmp,combi.choose(a,i));
		ans[0]=combi.add(ans[0],tmp);
	}
	for(int i = 0; i <= c; i++)
	{
		ll tmp = combi.choose(c,i);
		tmp = combi.mult(tmp, combi.fact[i]);
		tmp = combi.mult(tmp,combi.choose(a,i));
		ans[1]=combi.add(ans[1],tmp);
	}
	for(int i = 0; i <= c; i++)
	{
		ll tmp = combi.choose(c,i);
		tmp = combi.mult(tmp, combi.fact[i]);
		tmp = combi.mult(tmp,combi.choose(b,i));
		ans[2]=combi.add(ans[2],tmp);
	}
	cout<<combi.mult(ans[0],combi.mult(ans[1],ans[2]))<<'\n';
}