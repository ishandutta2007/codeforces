#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MOD = 1000000007;

int n1, n2;
char s1[MAXN];
char s2[MAXN];
bool ok[MAXN];
int f[MAXN];
int sf[MAXN];

void init()
{
	scanf("%s%s", s1, s2);
	n1 = strlen(s1);
	n2 = strlen(s2);
}

void work_KMP()
{
	static int p[MAXN];
	p[0] = -1;
	p[1] = 0;
	for (int i = 2, j = 0; i <= n2; ++i)
	{
		while (j > 0 && s2[j] != s2[i-1])
			j = p[j];
		if (s2[j] == s2[i-1]) ++j;
		p[i] = j;
	}

	for (int i = 0, j = 0; i < n1; ++i)
	{
		while (j > 0 && s2[j] != s1[i])
			j = p[j];
		if (s2[j] == s1[i]) ++j;
		if (j == n2) ok[i-n2+1] = true;
	}
}

void solve()
{
	work_KMP();
	f[0] = 1;
	sf[0] = 1;
	for (int i = 1, last = -1; i <= n1; ++i)
	{
		if (i >= n2 && ok[i-n2])
			last = i - n2;
		f[i] = f[i-1];
		if (last != -1)
			(f[i] += sf[last]) %= MOD;
		sf[i] = (sf[i-1] + f[i]) % MOD;
	}

	int ans = (f[n1] + MOD - 1) % MOD;
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}