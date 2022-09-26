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
	const int MOD = 1e9 + 7;
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

ll choose(ll a, ll b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	ll tmp = combi.ifact[b];
	ll ans=1;
	for(ll i = a; i >= a - b + 1; i--)
	{
		ans=combi.mult(ans,i);
	}
	ans=combi.mult(ans,tmp);
	return ans;
}

ll get(ll a, ll b)
{
	if(b==0) return 1;
	if(b==1) return a;
	return choose(a+b-1,b);
}

ll dp[101][101][101];
ll dp2[51][51][51][51];
ll c[101][101];

ll calc(int n, int m);
ll calc2(int n, int m, int k, int mx);

ll solve(int n, int m, int maxarg)
{
	if(dp[n][m][maxarg]!=-1) return dp[n][m][maxarg];
	ll ans=0;
	if(n==0)
	{
		if(m==1) return (dp[n][m][maxarg]=1);
		else return 0;
	}
	//iterate through how much flow the first step should give
	if(m<=1) return 0;
	//m>1
	//check how much flow we go for newbie
	if(maxarg<=0)
	{
		return (dp[n][m][maxarg]=0);
	}
	ans = solve(n,m,maxarg-1);
	for(int z = 1; z*maxarg+1<=m; z++)
	{
		//i have z graphs with maxarg flow
		//flow remaining = m - 1 - maxarg*z
		for(int i = 0; i <= n - z; i++)
		{
			//use i in total
			////cerr<<n-z-i<<' '<<m-maxarg*z<<' '<<maxarg-1<<'\n';
			ll coeff = solve(n - z - i, m - maxarg*z, min(m-maxarg*z,maxarg-1));
			if(coeff==0) continue;
			//i times, create z graphs on both sides
			ans = combi.add(ans, combi.mult(coeff,calc2(i, maxarg, z, i)));
		}
	}
	////cerr<<"SOLVE : "<<n<<' '<<m<<' '<<maxarg<<' '<<ans<<'\n';
	return (dp[n][m][maxarg]=ans);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	combi.init(10000);
	int n,m; cin>>n>>m;
	memset(c,-1,sizeof(c));
	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));
	cout<<solve(n,m,m)<<'\n';
}

ll calc(int n, int m)
{
	if(c[n][m]!=-1) return c[n][m];
	ll ans = 0;
	for(int i = 0; i <= n; i++)
	{
		for(int j = m; j <= m + n; j++)
		{
			for(int k = m; k <= m + n; k++)
			{
				if(min(j,k)!=m) continue;
				ans = combi.add(ans, combi.mult(solve(i,j,j),solve(n-i,k,k)));
			}
		}
	}
	//cerr<<"CALC : "<<n<<' '<<m<<' '<<ans<<'\n';
	return (c[n][m]=ans);
}

ll calc2(int n, int m, int k, int mx)
{
	if(dp2[n][m][k][mx]!=-1) return dp2[n][m][k][mx];
	////cerr<<"CALC 2 : "<<n<<' '<<m<<' '<<k<<' '<<mx<<'\n';
	if(k==0)
	{
		if(n==0) return 1;
		else return 0;
	}
	if(k==1)
	{
		if(mx<n) return 0;
		else return calc(n,m);
	}
	if(mx==0)
	{
		if(n==0)
		{
			return get(calc(0,m),k);
		}
		else
		{
			return 0;
		}
	}
	ll ans = calc2(n,m,k,mx-1);
	for(int i = 1; i*mx<=n&&i<=k; i++)
	{
		ans = combi.add(ans,combi.mult(calc2(n-i*mx,m,k-i,mx-1),get(calc(mx,m),i)));
	}
	return (dp2[n][m][k][mx]=ans);
}