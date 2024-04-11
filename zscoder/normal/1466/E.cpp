#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = (1e9 + 7);
int add(int a, int b)
{
	a+=b;
	while(a>=MOD) a-=MOD;
	return a;
}
void radd(int &a, int b)
{
	a=add(a,b); 
}
ll mult(ll a, ll b)
{
	return (a*1LL*b)%MOD;
}
void rmult(int &a, int b)
{
	a=mult(a,b);
}
int modpow(int a, int b)
{
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
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
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

int cnt[63];
int dp[63][63];
int lul[63];

void solve()
{
	int n; scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		ll v; scanf("%lld",&v);
		int sz=0;
		for(int j=0;j<61;j++)
		{
			if(v&(1LL<<j))
			{
				cnt[j]++; dp[j][j]++; 
				lul[sz++]=j;
			}
		}
		for(int x=0;x<sz;x++)
		{
			for(int y=x+1;y<sz;y++)
			{
				dp[lul[x]][lul[y]]++; dp[lul[y]][lul[x]]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<61;i++)
	{
		for(int j=0;j<61;j++)
		{
			ll res = (1LL<<i)%MOD;
			if(res<0) res+=MOD;
			ll res2 = (1LL<<j)%MOD;
			if(res2<0) res2+=MOD;
			ll coeff = mult(res,res2);
			int ct = mult(cnt[i],mult(dp[i][j],n));
			radd(ct,mult(cnt[i],mult(cnt[i]-dp[i][j],cnt[j])));
			radd(ans,mult(coeff,ct));
		}
	}	
	cout<<ans<<'\n';
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t; scanf("%d",&t);
	init(511111);
	while(t--) solve();
}