#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	ll a;
	cin >> a;
	ll n = ll(1e17);
	n *= 18;
	//cout << n << endl;
	n %= a;
	ll k = n;
	//cout << n << endl;
	for(int i = 0; i < 44; i++)
	{
		n = (n + k)%a;
	}
	//cout << n << endl;
	if(n < 0)
	{
		n += a;
	}
	ll c = a - n; ll d = c + ll(1e18) - 1LL;
	cout << c << " " << d;
	return 0;
}