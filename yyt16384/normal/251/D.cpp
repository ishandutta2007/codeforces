#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

typedef unsigned long long ULL;

const int MAXN = 100005;
const int BITS = 60;

int n;
ULL a[MAXN];
ULL b[MAXN];
bool used[MAXN];
ULL work[MAXN];
int id[BITS];
bool ans[MAXN];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%"LLFORMAT"u", &a[i]);

	ULL ss = 0;
	for (int i = 0; i < n; ++i)
		ss ^= a[i];
	for (int i = BITS - 1; i >= 0; --i)
		if (!((ss >> i) & 1))
		{
			for (int j = 0; j < n; ++j)
				b[j] = (b[j] << 1) | ((a[j] >> i) & 1);
		}
	for (int i = BITS - 1; i >= 0; --i)
		if ((ss >> i) & 1)
		{
			for (int j = 0; j < n; ++j)
				b[j] = (b[j] << 1) | ((a[j] >> i) & 1);
		}
}

void solve()
{
	ULL ss = 0;
	ULL answork = 0;
	for (int i = BITS - 1; i >= 0; --i)
	{
		int r = -1;
		for (int j = 0; j < n; ++j)
			if (!used[j] && ((b[j] >> i) & 1))
			{
				r = j; break;
			}

		if (r == -1) continue;

		used[r] = true;
		work[r] ^= 1ULL << i;
		id[i] = r;
		if (!((ss >> i) & 1))
		{
			answork ^= work[r];
			ss ^= b[r];
		}

		for (int j = 0; j < n; ++j)
			if (!used[j] && ((b[j] >> i) & 1))
			{
				b[j] ^= b[r];
				work[j] ^= work[r];
			}
	}

	for (int i = 0; i < BITS; ++i)
		if ((answork >> i) & 1)
			ans[id[i]] = true;

	for (int i = 0; i < n; ++i)
		if (ans[i]) printf("2 ");
		else printf("1 ");
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9208.in", "r", stdin);
	freopen("9208.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}