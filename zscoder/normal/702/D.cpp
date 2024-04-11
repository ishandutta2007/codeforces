#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); 
	ll d, k, a, b, t;
	cin >> d >> k >> a >> b >> t;
	ll ans = 0;
	if(d <= k)
	{
		ans = d*a;
	}
	else
	{
		ll q = d/k; ll r = d%k;
		ans = k*a + (d-k)*b;
		ans = min(ans, q*(k*a+t)+r*a);
		ans = min(ans, q*(k*a+t)-t+r*b);
	}
	cout << ans;
	return 0;
}