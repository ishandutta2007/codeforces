#include <algorithm>
#include <cstdio>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

typedef std::pair<int, int> Pii;

const int MAXN = 1005;

int n;
int a[MAXN];
std::vector<Pii> ans;

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

void move(int x, int y)
{
	a[y] -= a[x];
	a[x] *= 2;
	ans.push_back(std::make_pair(x, y));
}

void work(int &x, int &y, int &z)
{
	if (a[x] > a[y])
		std::swap(x, y);
	if (a[x] > a[z])
		std::swap(x, z);
	if (a[y] > a[z])
		std::swap(y, z);

	if (a[x] == 0) return;

	int t = a[y] / a[x];
	while (t)
	{
		if (t & 1)
			move(x, y);
		else
			move(x, z);
		t >>= 1;
	}

	work(x, y, z);
}

void solve()
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		if (a[i] > 0)
			++cnt;
	if (cnt <= 1)
	{
		printf("-1\n");
		return;
	}

	int x = -1, y = -1;
	for (int i = 0; i < n; ++i)
		if (a[i] > 0)
		{
			if (x == -1)
				x = i;
			else if (y == -1)
			{
				y = i;
				break;
			}
		}

	for (int i = y + 1; i < n; ++i)
		if (a[i] > 0)
		{
			int t = i;
			work(t, x, y);
		}

	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9221.in", "r", stdin);
	freopen("9221.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}