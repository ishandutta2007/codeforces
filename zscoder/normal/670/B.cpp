#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll id[100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n, k; cin >> n >> k;
	for(ll i = 1; i <= n; i++)
	{
		cin >> id[i];
	}
	ll pos = 0;
	ll cnt = 0;
	while(1)
	{
		cnt++; pos += cnt;
		if(k <= pos)
		{
			ll l = cnt*(cnt - 1)/2;
			cout << id[k-l];
			return 0;
		}
	}
	return 0;
}