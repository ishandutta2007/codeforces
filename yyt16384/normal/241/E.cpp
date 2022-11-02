#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1005;
const int MAXM = 5005;

struct Edge
{
	int x, y;
	int id;
};

int n, m;
Edge a[MAXM];
bool viss[MAXN];
bool vist[MAXN];
int dis[MAXN];

bool cmpx(const Edge &x, const Edge &y)
{
	return x.x < y.x;
}

bool cmpy(const Edge &x, const Edge &y)
{
	return x.y > y.y;
}

bool cmpid(const Edge &x, const Edge &y)
{
	return x.id < y.id;
}

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		--a[i].x; --a[i].y;
		a[i].id = i;
	}
}

void solve()
{
	std::sort(a, a + m, cmpx);
	viss[0] = true;
	for (int i = 0; i < m; ++i)
		viss[a[i].y] |= viss[a[i].x];

	std::sort(a, a + m, cmpy);
	vist[n - 1] = true;
	for (int i = 0; i < m; ++i)
		vist[a[i].x] |= vist[a[i].y];

	for (int i = 0; i <= n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < m; ++j)
			if (viss[a[j].x] && vist[a[j].y])
			{
				if (dis[a[j].x] + 2 < dis[a[j].y])
				{
					dis[a[j].y] = dis[a[j].x] + 2;
					flag = true;
				}
				if (dis[a[j].y] - 1 < dis[a[j].x])
				{
					dis[a[j].x] = dis[a[j].y] - 1;
					flag = true;
				}
			}
		if (!flag)
			break;
		if (i == n && flag)
		{
			printf("No\n");
			return;
		}
	}

	std::sort(a, a + m, cmpid);
	printf("Yes\n");
	for (int i = 0; i < m; ++i)
	{
		if (!viss[a[i].x] || !vist[a[i].y])
			printf("1\n");
		else
			printf("%d\n", dis[a[i].y] - dis[a[i].x]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9227.in", "r", stdin);
	freopen("9227.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}