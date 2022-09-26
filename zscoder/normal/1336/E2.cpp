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

vector<int> fact;
vector<int> ifact;
vector<int> inv;
vector<int> pow2;
const int MOD = 998244353;
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
int mult(int a, int b)
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
	if(a<0||b<0) return 0;
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

ll cnt[60];
ll a[60];
int dp[60][60];

void dfs(ll x, int n) //stop at n<0
{
	if(n<0)
	{
		cnt[__builtin_popcountll(x)]++;
		return ;
	}
	dfs(x,n-1);
	dfs(x^a[n],n-1);
}

ll basis[60];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; cin>>n>>m;
	init(255000);
	int rank=0;
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		for(int j=m-1;j>=0;j--)
		{
			if(!(x&(1LL<<j))) continue;
			if(basis[j]==0)
			{
				basis[j]=x; a[rank]=x; rank++; break;
			}
			x=min(x,x^basis[j]);
		}
	}
	if(rank<=27)
	{
		dfs(0,rank-1);
		for(int i=0;i<=m;i++)
		{
			cnt[i]%=MOD;
			if(cnt[i]<0) cnt[i]+=MOD;
			cout<<mult(cnt[i],pow2[n-rank]);
			if(i+1<=m) cout<<' ';
		}
		cout<<'\n';
	}
	else
	{
		//construct orthogonal basis (note that we want popcount(i&x)=0 mod 2 which happens when dot product of the vector with all vectors in our basis in Z_2 is 0
		vi bad;
		vi good;
		for(int i=m-1;i>=0;i--)
		{
			for(int j=i-1;j>=0;j--)
			{
				basis[i]=min(basis[i],basis[i]^basis[j]);
			}
			if(!basis[i]) bad.pb(i); //leading bit not in basis
			else 
			{
				good.pb(i);
			}
		}
		assert(int(good.size())==rank);
		int ct=0;
		for(int i=0;i<m-rank;i++) //construct orthogonal basis via rotation method
		{
			ll ans = (1LL<<bad[i]);
			for(int j=0;j<rank;j++)
			{
				if(basis[good[j]]&(1LL<<bad[i]))
				{
					ans^=(1LL<<good[j]);
				}
			}
			a[ct++]=ans;
		}
		for(int i=0;i<ct;i++)
		{
			for(int v:good)
			{
				assert(__builtin_popcountll(basis[v]&a[i])%2==0);
			}
		}
		assert(ct==m-rank);
		dfs(0,ct-1);
		for(int i=0;i<=m;i++)
		{
			cnt[i]%=MOD;
			if(cnt[i]<0) cnt[i]+=MOD;
			//cerr<<i<<' '<<cnt[i]<<'\n';
		}
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=m;j++)
			{
				//compute w(i,j)
				for(int k=0;k<=m;k++) 
				{
					int sgn=1;
					if(k&1) sgn=MOD-1;
					else sgn=1;
					radd(dp[i][j],mult(sgn,mult(choose(j,k),choose(m-j,i-k))));
				}
				//cerr<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			}
		}
		for(int i=0;i<=m;i++)
		{
			ll ans = 0;
			for(int j=0;j<=m;j++)
			{
				ans=add(ans,mult(cnt[j],dp[i][j]));
			}
			ans = mult(ans,inverse(pow2[ct]));
			ans = mult(ans,pow2[n-rank]);
			cout<<ans;
			if(i+1<=m) cout<<' ';
		}
	}
}