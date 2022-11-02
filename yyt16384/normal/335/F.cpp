#include <algorithm>
#include <cstdio>
#include <functional>
#include <set>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 500005;

int n;
int a[MAXN];
int m;
std::pair<int, int> c[MAXN];
long long sum;

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

void solve()
{
	for (int i = 0; i < n; ++i)
		sum += a[i];
	std::sort(a, a + n, std::greater<int>());
	for (int i = 0; i < n; ++i)
	{
		if (i == 0 || a[i] != a[i - 1])
			c[m++].first = a[i];
		++c[m - 1].second;
	}

	std::multiset<int> fr;
	for (int k = 0, tot = 0; k < m; ++k)
	{
		int v = c[k].first;
		int cnt = c[k].second;
		int maxa = std::min(cnt, tot);
		int nextsz = std::min(std::min((int)fr.size() + cnt, tot), (tot + cnt) / 2);
		int rem = maxa - (nextsz - fr.size());

		std::multiset<int>::iterator it = fr.begin();
		static int rem_v[MAXN];
		for (int i = 0; i < rem; ++i)
		{
			rem_v[rem - i - 1] = *it;
			++it;
		}
		fr.erase(fr.begin(), it);

		int add = nextsz - fr.size();
		static int add_v[MAXN];
		for (int i = 0; i < add; ++i)
			add_v[i] = v;
		if ((tot + maxa) % 2)
			add_v[add++] = 0;
		for (int i = 0; i < rem; ++i)
			if (rem_v[i] > add_v[i])
			{
				add_v[i] = rem_v[i];
				add_v[add - i - 1] -= rem_v[i] - v;
			}
		while (add > 0 && add_v[add - 1] <= 0)
			--add;
		fr.insert(add_v, add_v + add);
		tot += cnt;
	}

	for (std::multiset<int>::const_iterator i = fr.begin(); i != fr.end(); ++i)
		sum -= *i;
	printf("%"LLFORMAT"d\n", sum);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9183.in", "r", stdin);
	freopen("9183.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}