#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 50005;
const int MAXBITS = 30;
const int MOD = 1000000007;

struct data
{
	int l1, r1, mid1;
	int l2, r2, mid2;

	data() {}
	data(int l1_, int r1_,
	     int l2_, int r2_)
		: l1(l1_), r1(r1_), l2(l2_), r2(r2_) {}
};

int n;
long long m;
unsigned a[MAXN];
long long ans;
data c[MAXN];
int cn;
data c2[MAXN];
int c2n;
int ss[MAXN];

void init()
{
	scanf("%d%"LLFORMAT"d", &n, &m);
	m *= 2;
	for (int i = 0; i < n; ++i)
		scanf("%u", &a[i]);
	std::sort(a, a + n);
}

void add(int l1, int r1, int l2, int r2)
{
	if (l1 == r1 || l2 == r2) return;
	c2[c2n++] = data(l1, r1, l2, r2);
}

long long countans(int l1, int r1, int l2, int r2, int bit)
{
	long long sum = 0;
	sum += (long long)(ss[r1] - ss[l1]) * ((r2 - l2) - (ss[r2] - ss[l2]));
	sum += (long long)((r1 - l1) - (ss[r1] - ss[l1])) * (ss[r2] - ss[l2]);
	return sum * (1U << bit);
}

void solve()
{
	c[cn++] = data(0, n, 0, n);

	for (int i = MAXBITS - 1; i >= 0; --i)
	{
		long long sum = 0;
		for (int j = 0; j < cn; ++j)
		{
			c[j].mid1 = std::lower_bound(a + c[j].l1, a + c[j].r1,
			                             1U << i) - a;
			c[j].mid2 = std::lower_bound(a + c[j].l2, a + c[j].r2,
			                             1U << i) - a;
			sum += (long long)(c[j].mid1 - c[j].l1) * (c[j].r2 - c[j].mid2);
			sum += (long long)(c[j].r1 - c[j].mid1) * (c[j].mid2 - c[j].l2);
		}

		for (int j = 0; j < n; ++j)
			a[j] &= (1U << i) - 1;

		c2n = 0;
		if (m <= sum)
		{
			ans += m * (1U << i);

			for (int j = 0; j < cn; ++j)
			{
				add(c[j].l1, c[j].mid1, c[j].mid2, c[j].r2);
				add(c[j].mid1, c[j].r1, c[j].l2, c[j].mid2);
			}
		}
		else
		{
			ans += sum * (1U << i);
			m -= sum;
			for (int j = 0; j < i; ++j)
			{
				ss[0] = 0;
				for (int k = 0; k < n; ++k)
					ss[k + 1] = ss[k] + ((a[k] >> j) & 1);
				for (int k = 0; k < cn; ++k)
				{
					ans += countans(c[k].l1, c[k].mid1, c[k].mid2, c[k].r2, j);
					ans += countans(c[k].mid1, c[k].r1, c[k].l2, c[k].mid2, j);
				}
			}

			for (int j = 0; j < cn; ++j)
			{
				add(c[j].l1, c[j].mid1, c[j].l2, c[j].mid2);
				add(c[j].mid1, c[j].r1, c[j].mid2, c[j].r2);
			}
		}

		if (c2n > n) return;
		cn = c2n;
		for (int j = 0; j < cn; ++j)
			c[j] = c2[j];
	}

	ans /= 2;
	ans %= MOD;
	printf("%d\n", (int)ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8799.in", "r", stdin);
	freopen("8799.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}