#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
	srand(2317);
	cout.precision(10);
	cout.setf(ios::fixed);
	#ifdef LOCAL
	freopen("c.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int a[200001];
int cnt[200002];
int n;

bool check(int r)
{
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < r; ++i)
		cnt[a[i]]++;
	for (int i = 0; i < r; ++i)
		if (n - 1 - i >= r)
		{
			--cnt[a[n - 1 - i]];
			if (cnt[a[n - 1 - i]] < 0)
				return false;
		}
	for (int i = r; i < n; ++i)
		if (n - 1 - i >= r && a[i] != a[n - 1 - i])
			return false;
	int ones = 0;
	for (int i = 0; i <= n; ++i)
		ones += cnt[i] % 2;
	return ones <= 1;
}

int solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int len = 0;
	while (len < n && a[len] == a[n - 1 - len])
		++len;
	if (len * 2 >= n)
	{
		ll ans = 0;
		for (int i = 0; i <= n; ++i)
			ans += i;
		cout << ans << '\n';
		return 0;
	}
	
	int lb = len, rb = n + 1;
	while (lb + 1 < rb)
	{
		int c = (lb + rb) / 2;
		if (check(c))
			rb = c;
		else
			lb = c;
	}
	if (rb == n + 1)
	{
		cout << 0 << '\n';
		return 0;
	}
	int b1 = rb;
	
	reverse(a, a + n);
	lb = len, rb = n + 1;
	while (lb + 1 < rb)
	{
		int c = (lb + rb) / 2;
		if (check(c))
			rb = c;
		else
			lb = c;
	}
	assert(rb != n + 1);
	int b2 = rb;
	
	ll ans = ll(len + 1) * ll(len + 1);
	if (b1 + len < n)
		ans += ll(len + 1) * ll(n - b1 - len);
	if (b2 + len < n)
		ans += ll(len + 1) * ll(n - b2 - len);
	cout << ans << '\n';
	return 0;
}