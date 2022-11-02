#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXL1 = 1000005;
const int MAXL2 = 205;
const int MAXK = 2005;
const int BASE = 173;
const int MOD = 1038574661;

int l1, l2, k;
char s1[MAXL1];
char s2[MAXL2];
int cnt, pt;
int hashpart[MAXK];
int hashres[MAXL2];
bool f[MAXK][MAXL2];
bool c[MAXK][MAXL2];
bool hassol;
bool ans[MAXK];

void init()
{
	fgets(s1, MAXL1, stdin);
	fgets(s2, MAXL2, stdin);
	scanf("%d", &k);
	l1 = strlen(s1) - 1;
	l2 = strlen(s2) - 1;
}

void work(int c2)
{
	for (int i = 0; i < c2; ++i)
	{
		hashres[i] = 0;
		for (int j = i; j < l2; j += c2)
			hashres[i] = ((long long)hashres[i] * BASE + s2[j]) % MOD;
	}

	memset(f, 0, sizeof(f));
	f[k][c2] = true;
	for (int i = k - 1; i >= 0; --i)
	{
		int minj = std::max(0, c2 + i - k);
		int maxj = std::min(c2, i);
		for (int j = minj; j <= maxj; ++j)
		{
			if (f[i+1][j])
			{
				f[i][j] = true;
				c[i][j] = false;
			}
			else if (hashpart[i] == hashres[j] && f[i+1][j+1])
			{
				f[i][j] = true;
				c[i][j] = true;
			}
		}
	}

	if (!f[0][0]) return;

	static bool now[MAXK];
	for (int i = 0, j = 0; i < k; ++i)
	{
		now[i] = c[i][j];
		j += c[i][j];
	}

	if (!hassol || memcmp(now, ans, k * sizeof(bool)) < 0)
	{
		hassol = true;
		memcpy(ans, now, k * sizeof(bool));
	}
}

void solve()
{
	cnt = l1 / k;
	pt = l1 % k;

	for (int i = 0; i < k; ++i)
	{
		hashpart[i] = 0;
		for (int j = i; j < l1; j += k)
			hashpart[i] = ((long long)hashpart[i] * BASE + s1[j]) % MOD;
	}

	for (int i = 1; i <= k && i <= l2; ++i)
	{
		int rem = l2 - i * cnt;
		if (rem >= 0 && rem <= i && rem <= pt && i - rem <= k - pt)
			work(i);
	}

	if (!hassol) printf("0\n");
	else
	{
		for (int i = 0; i < k; ++i)
			printf("%d", ans[i]);
		printf("\n");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9161.in", "r", stdin);
	freopen("9161.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}