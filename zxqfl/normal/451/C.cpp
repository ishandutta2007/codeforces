#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool ssolve(ll n, ll k, ll d1, ll d2)
{
	ll a = 3000000000000;
	ll b = a + d1;
	ll c = b + d2;

	if ((a + b + c) % 3 != k % 3)
		return false;

	ll diff = (a + b + c - k) / 3;

	ll arr[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	loop(i, 3)
	{
		if (arr[i] < diff)
			return false;
		arr[i] -= diff;
	}

	sort(arr, arr + 3);

	ll needed = arr[2] * 2 - arr[1] - arr[0];

	return n - k >= needed;
}

bool solve(ll n, ll k, ll d1, ll d2)
{
	if (n % 3 != 0)
		return false;

	return
			ssolve(n, k, d1, d2) ||
			ssolve(n, k, -d1, d2) ||
			ssolve(n, k, d1, -d2) ||
			ssolve(n, k, -d1, -d2);
}

int main()
{
	int T;
	rint(T);

	rep(T)
	{
		ll n, k, d1, d2;
		scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
		printf("%s\n", solve(n, k, d1, d2) ? "yes" : "no");
	}
}