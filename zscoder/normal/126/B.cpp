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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

void no(){cout << "Just a legend";}

const int MOD = 1e9 + 7;

ll mult(ll a, ll b)
{
	return (a*b)%MOD;
}

ll add(ll a, ll b)
{
	return (a+b)%MOD;
}

ll pow27[2000001];
const int C = 27;
ll dp[1000001];
int inv27;

ll modpow(ll a, ll b)
{
	ll r = 1;
	while(b)
	{
		if(b&1) r = (r*a)%MOD;
		a = (a*a)%MOD;
		b>>=1;
	}
	return r;
}

ll inv(ll a)
{
	return modpow(a, MOD - 2);
}

ll hsh(int l, int r)
{
	if(l > r) return 0;
	if(l == 0) return dp[r];
	else return mult((dp[r] - dp[l - 1] + MOD)%MOD, modpow(inv27, l));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	inv27 = inv(27);
	string s; cin >> s;
	int n = s.length();
	pow27[0] = 1;
	for(int i = 1; i < 2000001; i++)
	{
		pow27[i] = mult(pow27[i-1], C);
	}
	for(int i = 0; i < n; i++)
	{
		dp[i] = mult(pow27[i], s[i] - 'a' + 1);
		if(i > 0) dp[i] = add(dp[i], dp[i - 1]);
	}	
	vi valid;
	for(int i = 0; i < n - 1; i++)
	{
		if(hsh(0, i) == hsh(n - 1 - i, n - 1)) valid.pb(i+1);
	}
	if(valid.empty()) {no(); return 0;}
	int lo = 0; int hi = valid.size() - 1;
	int ans = -1;
	while(lo <= hi)
	{
		int mid = (lo+hi)>>1;
		bool good = false;
		for(int i = 1; i + valid[mid] - 1 < n - 1; i++)
		{
			if(hsh(i, i + valid[mid] - 1) == hsh(0, valid[mid] - 1))
			{
				good = true;
				break;
			}
		}
		if(good)
		{
			ans = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	if(ans == -1){no(); return 0;}
	cout << s.substr(0, valid[ans]);
}