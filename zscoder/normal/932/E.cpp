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

const int MOD = (1e9 + 7);

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
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
	if(b<0) return 0;
	int r=1;
	while(b)
	{
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
int choose(int a, int b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	/*
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
	*/
	int res=1;
	for(int i=a;i>=a-b+1;i--)
	{
		res=mult(res,i);
	}	
	res=mult(res,ifact[b]);
	return res;
}
int inverse(int a)
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
		fact[i]=mult(fact[i-1],i);
		//ifact[i]=mult(ifact[i-1],inv[i]);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--)
	{
		ifact[i] = mult(ifact[i + 1], i + 1);
	}
	for(int i=1;i<=_n;i++)
	{
		inv[i] = mult(fact[i-1],ifact[i]);
	}
}

int fix(ll x)
{
	x%=MOD;
	if(x<0) x+=MOD;
	return x;
}

int dp[100011];

int k;

int compute(int n)
{
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans = add(ans, mult(choose(n,i),dp[i]));
	}
	return ans;
}

int solve(int N, int K)
{
	return mult(modpow(2,N-K), choose(N,K));
}

int ster[5111][5111];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(100001);
	int n;
	cin>>n>>k;
	dp[0] = 0;
	for(int i=1;i<=100000;i++) dp[i] = modpow(i,k);
	ster[0][0]=1;
	for(int i=1;i<=5011;i++)
	{
		for(int j=1;j<=5011;j++)
		{
			ster[i][j]=add(ster[i-1][j-1], mult(j, ster[i-1][j]));
		}
	}
	//cerr<<compute(n)<<'\n';
	int ans = 0;
	for(int i=0;i<=k;i++)
	{
		int coeff = mult(ster[k][i],fact[i]);
		ans=add(ans,mult(coeff,solve(n,i)));
	}
	cout<<ans<<'\n';
}