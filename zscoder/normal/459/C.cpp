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

int a[1001][1001];

void out(ll n, ll d, ll k)
{
	vector<ll> digits;
	ll ntmp = n;
	for(int i = 0; i < d; i++)
	{
		digits.pb(n%k);
		n/=k;
	}
	for(int i = 0; i < d; i++)
	{
		a[ntmp][i] = digits[i] + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, d, k;
	cin >> n >> k >> d;
	ll ans = 1;
	for(int i = 0; i < d; i++)
	{
		ans *= k;
		if(ans >= n) break;
	}
	if(n > ans)
	{
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		out(i, d, k);
	}
	for(int i = 0; i < d; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[j][i] << ' ';
		}
		cout << '\n';
	}
}