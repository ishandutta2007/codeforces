#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;
const int MAXP = 7;
const int MAXS = 3;

int n;
int a[MAXN];
int c[MAXP];
int match[MAXP + 1];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

bool ok()
{
	int pos[MAXP];
	int l = 0;
	for (int i = 0; i < MAXP; ++i)
	{
		int st, dr;
		if (c[i] >= 0) st = c[i], dr = 1;
		else st = -c[i] - 1, dr = -1;
		pos[st] = i;
		match[i] = l;
		while (l < n - 1 && a[l + 1] - a[l] == dr) ++l;
		if (l < n) ++l;
	}
	if (l < n) return false;
	match[MAXP] = n;

	int pre = -1;
	for (int i = 0; i < MAXP; ++i)
		if (match[pos[i]] < l)
		{
			int now = a[match[pos[i]]];
			if (now < pre) return false;
			pre = now;
		}

	return true;
}

bool search(int x)
{
	static int st[MAXS][2];

	if (ok())
	{
		int ans[MAXS][2];
		int ansn = 0;
		for (int i = x - 1; i >= 0; --i)
			if (match[st[i][0]] < match[st[i][1]] - 1)
			{
				int l = match[st[i][0]];
				int r = match[st[i][1]] - 1;
				int tp[MAXP];
				for (int k = st[i][0]; k < st[i][1]; ++k)
					tp[k] = match[k + 1] - match[k];
				std::reverse(tp + st[i][0], tp + st[i][1]);
				for (int k = st[i][0]; k < st[i][1]; ++k)
					match[k + 1] = match[k] + tp[k];
				ans[ansn][0] = l; ans[ansn][1] = r; ++ansn;
			}

		printf("%d\n", ansn);
		for (int i = ansn - 1; i >= 0; --i)
			printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);

		return true;
	}

	if (x == MAXS) return false;

	for (int i = 0; i < MAXP; ++i)
		for (int j = i + 1; j <= MAXP; ++j)
		{
			std::reverse(c + i, c + j);
			for (int k = i; k < j; ++k) c[k] = -c[k] - 1;
			st[x][0] = i; st[x][1] = j;

			if (search(x + 1)) return true;

			std::reverse(c + i, c + j);
			for (int k = i; k < j; ++k) c[k] = -c[k] - 1;
		}

	return false;
}

void solve()
{
	for (int i = 0; i < MAXP; ++i) c[i] = i;
	search(0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8768.in", "r", stdin);
	freopen("8768.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}