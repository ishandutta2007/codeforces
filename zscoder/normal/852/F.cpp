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

struct Combi
{
	vector<ll> fact;
	vector<ll> ifact;
	vector<ll> inv;
	vector<ll> pow2;
	int MOD;
	ll add(ll a, ll b)
	{
		a+=b;
		a%=MOD;
		if(a<0) a+=MOD;
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
	void init(int _n, int _MOD)
	{
		fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
		fact.resize(_n+1);
		ifact.resize(_n+1);
		inv.resize(_n+1);
		pow2.resize(_n+1);
		MOD=_MOD;
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

int P;
ll powr[1111111];

ll mult(ll a, ll b)
{
	return (a*b)%P;
}

ll add(ll a, ll b)
{
	a+=b;
	a%=P;
	if(a<0) a+=P;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,m,a;
	cin>>n>>m>>a>>P;
	Combi combi;
	powr[0]=1; powr[1]=a%P;
	ll cyc = 0;
	if(powr[1]==1) cyc=1;
	for(int i=2;i<=1111110;i++)
	{
		powr[i]=mult(powr[i-1],a);
		if(powr[i]==1&&cyc==0)
		{
			cyc=i;
		}
	}
	//cerr<<cyc<<'\n';
	ll cur = 0;
	combi.init(1011111,cyc);
	vector<ll> res(n);
	for(int i=0;i<n;i++)
	{
		//cerr<<m<<' '<<i<<'\n';
		cur = combi.add(cur,combi.choose(m,i));
		res[n-i-1] = powr[cur];
	}
	for(int i=0;i<n;i++)
	{
		cout<<res[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}