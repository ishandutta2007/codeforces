#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e6 + 3;

ll power(ll base, ll exp)
{
	ll ans = 1;
    while(exp)
    {
		if(exp&1) ans = (ans*base)%MOD;
		base = (base*base)%MOD;
		exp>>=1;
	}
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	if(n <= 63 && k > (1LL<<n))
	{
		cout << 1 << " " << 1;
		return 0;
	}
	ll v2 = 0;
	int digits = __builtin_popcountll(k - 1);
	v2 = k - 1 - digits;
	ll ntmp = n % (MOD - 1);
	if(ntmp < 0) ntmp += (MOD - 1);
	ll ktmp = k % (MOD - 1);
	if(ktmp < 0) ktmp += (MOD - 1);
	ll v2tmp = v2 % (MOD - 1);
	if(v2tmp < 0) v2tmp += (MOD - 1);
	ll exponent = ntmp*(ktmp - 1) - v2tmp;
	exponent %= (MOD - 1);
	if(exponent < 0) exponent += MOD - 1;
	ll denom = power(2, exponent);
	ll numpart = 0;
	if(k - 1 >= MOD)
	{
		numpart = 0;
	}
	else
	{
		ll prod = 1;
		ll ntmp2 = power(2, ntmp);
		prod = power(2, v2tmp);
		prod = power(prod, MOD - 2);
		if(prod < 0) prod += MOD;
		for(ll y = 1; y <= k - 1; y++)
		{
			prod = (prod * (ntmp2 - y))%MOD;
		}
		numpart = prod;
	}
	ll num = (denom - numpart)%MOD;
	num %= MOD; denom %= MOD;
	if(num < 0) num += MOD;
	if(denom < 0) denom += MOD;
	cout << num << " " << denom;
	return 0;
}