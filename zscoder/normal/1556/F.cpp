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

int a[22];
int p[22][22];
int scc[(1<<15)]; //probability of the people in mask having scc

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	init(55555);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			p[i][j]=mult(a[i],inverse(a[i]+a[j]));
			//cerr<<i<<' '<<j<<' '<<p[i][j]<<'\n';
		}
	}
	scc[0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		int j=i;
		int ans = 1;
		while(1)
		{
			if(j!=i&&j>0)
			{
				//scc is j, and the rest goes
				int prob = 1;
				for(int k=0;k<n;k++)
				{
					if(!(i&(1<<k))) continue;
					if(j&(1<<k))
					{
						for(int l=0;l<n;l++)
						{
							if(!(i&(1<<l))) continue;
							if(!(j&(1<<l)))
							{
								//k -> l must be true
								rmult(prob, p[k][l]);
							}
						}
					}
				}
				//cerr<<i<<' '<<j<<": "<<prob<<'\n';
				rmult(prob,scc[j]);
				radd(ans,MOD-prob);
			}
			if(j==0) break;
			j = (j-1)&i;
		}
		scc[i] = ans;
		//cerr<<i<<' '<<scc[i]<<'\n';
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		int winners = __builtin_popcount(i);
		int prob = 1;
		for(int k=0;k<n;k++)
		{
			if(i&(1<<k))
			{
				for(int l=0;l<n;l++)
				{
					if(!(i&(1<<l)))
					{
						//k -> l must be true
						rmult(prob, p[k][l]);
					}
				}
			}
		}
		rmult(prob,scc[i]);
		radd(ans,mult(winners,prob));
	}
	cout<<ans<<'\n';
}