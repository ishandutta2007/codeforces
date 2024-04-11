#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;

int n;
int next[MAXN];
bool vis[MAXN];

void init()
{
	scanf("%d", &n);
}

void search(int x)
{
	if (vis[x]) return;
	vis[x] = true;
	int y = (x + n/2) % n;
	if (vis[y])
	{
		next[x] = (4*x+1 - next[y]) % n;
		search(next[x]);
	}
	else
	{
		next[x] = 2*x % n;
		search(next[x]);
		if (!vis[y])
		{
			next[x] ^= 1;
			search(next[x]);
		}
	}
}

void solve()
{
	if (n % 2)
	{
		printf("-1\n");
		return;
	}

	search(0);

	int x = 0;
	do
	{
		printf("%d ", x);
		x = next[x];
	}while (x != 0);
	printf("0\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9224.in", "r", stdin);
	freopen("9224.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}