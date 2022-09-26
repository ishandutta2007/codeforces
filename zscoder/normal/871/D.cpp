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

std::vector <int> prime;
const int MAXN = 10000011;
bool is_composite[MAXN];
int phi[MAXN];
int smallestpf[MAXN];
int mobius[MAXN];
int pi[MAXN];
ll cnt[MAXN];

void sieve (int n) {
	memset(is_composite, 0, sizeof(is_composite));
	mobius[1] = 1;
	for (int i = 2; i < n; ++i) 
	{
		if (!is_composite[i]) {
			prime.push_back (i);
			smallestpf[i] = i;
			phi[i] = i - 1;					//i is prime
			mobius[i] = -1;
		}
		for (int j = 0; j < prime.size (); ++j) {
			if(ll(i)*prime[j]>n) break;
			is_composite[i * prime[j]] = true;
			smallestpf[i*prime[j]] = min(smallestpf[i], prime[j]);
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				mobius[i*prime[j]] = 0;
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
				mobius[i*prime[j]] = mobius[i]*mobius[prime[j]];
			}
		}
	}
}

ll n; 

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	smallestpf[1] = 1;
	cin>>n;
	sieve(n+10);
	ll base = 0;
	for(int v = 2; v <= n; v++)
	{
		base += v - 1 - phi[v];
	}
	for(int v=2;v<=n;v++)
	{
		cnt[smallestpf[v]]++;
	}
	ll res2 = 0;
	for(int v = 0; v < prime.size(); v++)
	{
		ll p = prime[v];
		for(int k = v; (k < prime.size()&&(p*prime[k]<=n)); k++)
		{
			ll q = prime[k];
			if(p==q) res2+=(cnt[p]*(cnt[p]-1))/2;
			else res2 += cnt[p]*cnt[q];
		}
	}
	ll cntp=0;
	for(int i=0;i<prime.size();i++)
	{
		if(prime[i]<=n&&prime[i]*2>n)
		{
			cntp++;
		}
	}
	ll cntrem = 0;
	cntrem += cntp*(n-2) - (cntp*(cntp-1))/2;
	cntrem = ((n-1)*(n-2))/2 - cntrem;
	ll res3 = cntrem - res2;
	ll ans = -base;
	ans += res2*2LL;
	ans += res3*3LL;
	cout<<ans<<'\n';
}