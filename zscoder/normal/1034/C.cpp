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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

ll a[1111111];
vi adj[1111111];
ll sub[1111111];
int cnt[1111111];

int ma[1111111];
int dp[1111111];

void dfs(int u, int p)
{
	sub[u]=a[u];
	for(int v:adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		sub[u]+=sub[v];
	}
}
int T[1111111];
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	init(1001111);
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(int i=0;i+1<n;i++)
	{
		int p; scanf("%d",&p); p--;
		adj[p].pb(i+1);
	}
	dfs(0,-1); ll S=sub[0];
	for(int i=0;i<n;i++)
	{
		ll g=__gcd(sub[i],S);
		ll tmp = S/g;
		if(tmp<=n)
		{
			T[tmp]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			ma[j]+=T[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(S%i==0)
		{
			cnt[i]=(ma[i]==i?1:0);
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(!cnt[i]) {continue;}
		dp[i]=1;
		for(int j=2*i;j<=n;j+=i)
		{
			if(!cnt[j]) continue;
			dp[i]=add(dp[i],dp[j]);
		}
	}
	printf("%d\n", dp[1]);
}