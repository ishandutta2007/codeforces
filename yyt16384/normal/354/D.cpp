#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXK = 100005;
const int MAXS = 805;
const int INF = 0x3f3f3f3f;

int n, k, s;
std::vector<int> a_[MAXN];
int *a[MAXN];
int *b[MAXN];
int f[2][MAXS];

void init()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		--r; --c;
		a_[c].push_back(n - r - 1);
	}
	for (int i = 0; i < n; ++i)
	{
		a[i] = &*a_[i].begin();
		b[i] = a[i] + a_[i].size();
	}
	for (int i = 0; i < n; ++i)
		std::sort(a[i], b[i], std::greater<int>());
}

void solve()
{
	static int up[MAXK];
	int now = 0;
	s = (int)sqrt(6 * k);
	f[now][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		now ^= 1;
		int *anow = a[n - i];
		int *bnow = b[n - i];
		int *fnow = f[now];
		int *fpre = f[now ^ 1];
		int *upnow = up + s + 1;
		*upnow = 0;
		for (register int p = s; p >= 0; --p)
		{
			--upnow;
			*upnow = *(upnow + 1);
			while (anow < bnow && *anow >= p)
			{
				++*upnow;
				++anow;
			}
		}
		fnow[0] = INF;
		for (register int p = 0; p <= s; ++p)
		{
			register int v = fpre[p ? p - 1 : 0] + p * (p + 1) / 2 + (p ? 2 : 0) + 3 * up[p];
			if (v < fnow[0])
				fnow[0] = v;
		}
		for (register int p = 1; p <= s; ++p)
		{
			fnow[p] = fnow[p - 1];
			register int v = fpre[p - 1] + 3 * up[p];
			if (v < fnow[p])
				fnow[p] = v;
		}
	}
	printf("%d\n", f[now][0]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9192.in", "r", stdin);
	freopen("9192.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}