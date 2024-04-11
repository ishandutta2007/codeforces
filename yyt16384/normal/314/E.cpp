#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;

int n;
int a[MAXN];
unsigned f_[2 * MAXN];
unsigned *f = f_ + MAXN;

void init()
{
	static char s[MAXN];
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i)
		a[i] = (s[i] == '?');
}

void solve()
{
	f[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		if (a[i])
		{
			int u = std::min(i + 1, n - i - 1);
			unsigned *g = f + u + 1;
			++f;
			while (g > f) *g += *(g - 2) * 25U, --g;
		}
		else
		{
			*(--f) = 0;
		}
	}

	printf("%u\n", f[0]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8805.in", "r", stdin);
	freopen("8805.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}