#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXC = 3000005;
const int MAXP = 25;

int l, r, p;

int primecnt;
int prime[MAXP];

int cn;
int c[MAXC];

int f[MAXC];
bool vis[MAXC];

void findprime(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		bool fl = true;
		for (int j = 2; j * j <= i; ++j)
			if (i % j == 0)
			{
				fl = false; break;
			}
		if (fl) prime[primecnt++] = i;
	}
}

void search(int x, int s)
{
	if (x == primecnt)
	{
		c[cn++] = s;
		return;
	}

	while (true)
	{
		search(x + 1, s);
		if ((long long)s * prime[x] <= r) s *= prime[x];
		else break;
	}
}

void init()
{
	scanf("%d%d%d", &l, &r, &p);
	findprime(p);
	search(0, 1);
	std::sort(c, c + cn);
}

void solve()
{
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	vis[0] = true;

	for (int i = 2; i <= p; ++i)
	{
		int k = 0;
		for (int j = 0; j < cn && (long long)c[j] * i <= r; ++j)
		{
			while (k < cn && c[k] < c[j] * i) ++k;
			if (f[j] + 1 < f[k])
			{
				f[k] = f[j] + 1;
				if (f[k] + i <= p) vis[k] = true;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < cn; ++i)
		if (c[i] >= l && vis[i])
			++sum;
	printf("%d\n", sum);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8791.in", "r", stdin);
	freopen("8791.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}