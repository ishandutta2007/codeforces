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

ll a[500001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll S = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i]; S += a[i];
	}
	ll ans = 0;
	vector<int> p, s;
	if(S%3 != 0){cout<<0; return 0;}
	ll pref = 0;
	for(int i = 0; i < n; i++)
	{
		pref += a[i];
		if(pref == S/3) p.pb(i+1);
	}
	ll suf = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		suf += a[i];
		if(suf == S/3) s.pb(i);
	}
	reverse(s.begin(), s.end());
	/*
	for(int i = 0; i < p.size(); i++)
	{
		cout << p[i] << ' ';
	}
	cout << '\n';
	for(int i = 0; i < s.size(); i++)
	{
		cout << s[i] << ' ';
	}
	cout << '\n';
	*/
	for(int i = 0; i < p.size(); i++)
	{
		ll val = p[i];
		int pos = upper_bound(s.begin(), s.end(), val) - s.begin();
		ans += int(s.size()) - pos;
	}
	cout << ans;
}