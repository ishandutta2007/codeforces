#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 5005;

int n, m;
int a[MAXN];
int posl[MAXN];
int sg[MAXN];

void init()
{
	static char s[MAXN];
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0, sum = 0; i < n; ++i)
	{
		if (i > 0 && i < n - 1 && s[i - 1] == s[i + 1]) ++sum;
		else if (sum > 0) a[m] = sum + 2, posl[m++] = i - sum, sum = 0;
	}
}

void solve()
{
	sg[1] = sg[2] = 0;
	for (int i = 3; i <= n; ++i)
	{
		static bool vis[MAXN];
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j < i - 1; ++j)
			vis[sg[j] ^ sg[i - j - 1]] = true;
		sg[i] = 0;
		while (vis[sg[i]]) ++sg[i];
	}

	int xsum = 0;
	for (int i = 0; i < m; ++i) xsum ^= sg[a[i]];
	if (xsum == 0) printf("Second\n");
	else
	{
		printf("First\n");
		for (int i = 0; i < m; ++i)
			for (int j = 1; j < a[i] - 1; ++j)
				if ((xsum ^ sg[a[i]] ^ sg[j] ^ sg[a[i] - j - 1]) == 0)
				{
					printf("%d\n", posl[i] + j);
					return;
				}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8802.in", "r", stdin);
	freopen("8802.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}