#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 50005;
const int BASE = 131;
const int MOD = 1000000007;

int n;
char s[MAXN];
int hash[MAXN];
int pow[MAXN];

void init()
{
	scanf("%s", s);
	n = strlen(s);

	pow[0] = 1;
	for (int i = 0; i < n; ++i)
		pow[i + 1] = (long long)pow[i] * BASE % MOD;
}

void build_hash()
{
	hash[0] = 0;
	for (int i = 0; i < n; ++i)
		hash[i + 1] = ((long long)hash[i] * BASE + s[i] - 'a') % MOD;
}

int get_hash(int l, int r)
{
	int x = (hash[r] - (long long)hash[l] * pow[r - l]) % MOD;
	if (x < 0) x += MOD;
	return x;
}

int lcp(int x, int y)
{
	int l = 0, r = std::min(n - x, n - y) + 1;
	int mid;
	while (l + 1 < r)
	{
		mid = (l + r) >> 1;
		if (get_hash(x, x + mid) == get_hash(y, y + mid)) l = mid;
		else r = mid;
	}
	return l;
}

int lcs(int x, int y)
{
	int l = 0, r = std::min(x, y) + 1;
	int mid;
	while (l + 1 < r)
	{
		mid = (l + r) >> 1;
		if (get_hash(x - mid, x) == get_hash(y - mid, y)) l = mid;
		else r = mid;
	}
	return l;
}

bool exists(int len)
{
	for (int i = 0; i + len < n; i += len)
		if (lcp(i, i + len) + lcs(i, i + len) >= len)
			return true;
	return false;
}

void remove_repeat(int len)
{
	static char s2[MAXN];
	int m = 0;
	int now_hash = 0;
	int i = 0;
	while (i < n)
	{
		if (m >= len && i + len <= n && get_hash(i, i + len) == now_hash) i += len;
		else
		{
			s2[m++] = s[i];
			now_hash = ((long long)now_hash * BASE + s[i] - 'a') % MOD;
			if (m > len)
			{
				now_hash = (now_hash - (long long)(s2[m - len - 1] - 'a') * pow[len]) % MOD;
				if (now_hash < 0) now_hash += MOD;
			}
			++i;
		}
	}

	n = m;
	strncpy(s, s2, n);
}

void solve()
{
	build_hash();
	for (int i = 1; i * 2 <= n; ++i)
		if (exists(i))
		{
			remove_repeat(i);
			build_hash();
		}

	s[n] = '\0';
	printf("%s\n", s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8803.in", "r", stdin);
	freopen("8803.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}