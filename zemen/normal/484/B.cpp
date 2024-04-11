#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;

#define NAME "b"

int a[200002];
bool used[2000103];
int best[2000103];

int main()
{
	#ifdef LOCAL
	freopen(NAME ".in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	int maxn = a[n - 1];
	for (int i = 0; i < n; ++i)
		used[a[i]] = true;
	for (int i = 1; i <= maxn * 2 + 3; ++i)
		best[i] = used[i] ? i : best[i - 1];
	
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; a[i] * j <= maxn; ++j)
		{
			const int rb = a[i] * (j + 1) - 1;
			int cres = best[rb] - a[i] * j;
			if (cres < a[i])
				res = max(res, cres);
		}
	}
	cout << res << '\n';
}