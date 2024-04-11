#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int n;
bool ok[MAXN];
int edgey[2 * MAXN];
int edgew[2 * MAXN];
int enext[2 * MAXN];
int ehead[MAXN];
int edgen;

int que[MAXN];
int fa[MAXN];
int faw[MAXN];
int dep[MAXN];

int len_down[MAXN];
int pt_down[MAXN];

int len_down2[MAXN];
int pt_down2[MAXN];

int len_up[MAXN];
int pt_up[MAXN];
int pt2_up[MAXN];

int len_tot[MAXN];
int pt_tot[MAXN];
int pt2_tot[MAXN];

int sum[MAXN];

void addedge(int x, int y, int w)
{
	edgey[edgen] = y;
	edgew[edgen] = w;
	enext[edgen] = ehead[x];
	ehead[x] = edgen++;
}

void init()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x;
		scanf("%d", &x);
		--x;
		ok[x] = true;
	}
	memset(ehead, -1, sizeof(ehead));
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		addedge(x, y, w);
		addedge(y, x, w);
	}
}

void BFS()
{
	int qb = 0, qe = 1;
	que[0] = 0;
	fa[0] = -1;
	faw[0] = -1;
	dep[0] = 0;
	while (qb < qe)
	{
		int x = que[qb++];
		for (int i = ehead[x]; i != -1; i = enext[i])
			if (edgey[i] != fa[x])
			{
				fa[edgey[i]] = x;
				faw[edgey[i]] = edgew[i];
				dep[edgey[i]] = dep[x] + 1;
				que[qe++] = edgey[i];
			}
	}
}

void work_down()
{
	for (int i = 0; i < n; ++i)
	{
		if (ok[i])
		{
			len_down[i] = 0;
			pt_down[i] = i;
		}
		else
		{
			len_down[i] = -INF;
			pt_down[i] = -1;
		}
	}
	for (int i = n - 1; i >= 1; --i)
	{
		int x = que[i];
		int f = fa[x];
		int len = len_down[x] + faw[x];
		if (len > len_down[f])
		{
			len_down[f] = len;
			pt_down[f] = pt_down[x];
		}
		else if (len == len_down[f])
			pt_down[f] = f;
	}
}

void work_down2()
{
	for (int i = 0; i < n; ++i)
	{
		static int sons[MAXN];
		static int len_pre[MAXN];
		static int pt_pre[MAXN];
		static int len_suf[MAXN];
		static int pt_suf[MAXN];
		int sonn = 0;
		for (int j = ehead[i]; j != -1; j = enext[j])
			if (edgey[j] != fa[i])
				sons[sonn++] = edgey[j];
		len_pre[0] = -INF;
		pt_pre[0] = -1;
		for (int j = 0; j < sonn; ++j)
		{
			int x = sons[j];
			int len = len_down[x] + faw[x];
			if (len > len_pre[j])
			{
				len_pre[j + 1] = len;
				pt_pre[j + 1] = pt_down[x];
			}
			else if (len == len_pre[j])
			{
				len_pre[j + 1] = len;
				pt_pre[j + 1] = i;
			}
			else
			{
				len_pre[j + 1] = len_pre[j];
				pt_pre[j + 1] = pt_pre[j];
			}
		}
		len_suf[sonn] = -INF;
		pt_suf[sonn] = -1;
		for (int j = sonn - 1; j >= 0; --j)
		{
			int x = sons[j];
			int len = len_down[x] + faw[x];
			if (len > len_suf[j + 1])
			{
				len_suf[j] = len;
				pt_suf[j] = pt_down[x];
			}
			else if (len == len_suf[j + 1])
			{
				len_suf[j] = len;
				pt_suf[j] = i;
			}
			else
			{
				len_suf[j] = len_suf[j + 1];
				pt_suf[j] = pt_suf[j + 1];
			}
		}
		for (int j = 0; j < sonn; ++j)
		{
			int x = sons[j];
			int len1 = len_pre[j];
			int pt1 = pt_pre[j];
			int len2 = len_suf[j + 1];
			int pt2 = pt_suf[j + 1];
			if (len1 > len2)
			{
				len_down2[x] = len1;
				pt_down2[x] = pt1;
			}
			else if (len1 < len2)
			{
				len_down2[x] = len2;
				pt_down2[x] = pt2;
			}
			else
			{
				len_down2[x] = len1;
				pt_down2[x] = i;
			}
		}
	}
}

void work_up()
{
	for (int i = 0; i < n; ++i)
	{
		if (ok[i])
		{
			len_up[i] = 0;
			pt_up[i] = i;
			pt2_up[i] = i;
		}
		else
		{
			len_up[i] = -INF;
			pt_up[i] = -1;
			pt2_up[i] = -1;
		}
	}
	for (int i = 1; i < n; ++i)
	{
		int x = que[i];
		int f = fa[x];
		int len1 = len_up[f] + faw[x];
		int pt1 = pt_up[f];
		int len2 = len_down2[x] + faw[x];
		int pt2 = pt_down2[x];
		if (len1 > len2)
		{
			len_up[x] = len1;
			pt_up[x] = pt1;
			pt2_up[x] = pt2_up[f];
		}
		else if (len1 < len2)
		{
			len_up[x] = len2;
			pt_up[x] = pt2;
			pt2_up[x] = f;
		}
		else
		{
			len_up[x] = len1;
			pt_up[x] = f;
			pt2_up[x] = f;
		}
	}
}

void work_tot()
{
	for (int i = 0; i < n; ++i)
	{
		int len1 = len_down[i];
		int pt1 = pt_down[i];
		int len2 = len_up[i];
		int pt2 = pt_up[i];
		if (len1 > len2)
		{
			len_tot[i] = len1;
			pt_tot[i] = pt1;
			pt2_tot[i] = i;
		}
		else if (len1 < len2)
		{
			len_tot[i] = len2;
			pt_tot[i] = pt2;
			pt2_tot[i] = pt2_up[i];
		}
		else
		{
			len_tot[i] = len1;
			pt_tot[i] = i;
			pt2_tot[i] = i;
		}
	}
}

void work_ans()
{
	for (int i = 0; i < n; ++i)
		if (ok[i])
		{
			int x = i;
			int y = pt_tot[i];
			int z = pt2_tot[i];
			++sum[x];
			++sum[y];
			--sum[z];
			if (z)
				--sum[fa[z]];
		}
	for (int i = n - 1; i >= 1; --i)
	{
		int x = que[i];
		int f = fa[x];
		sum[f] += sum[x];
	}
	int max = 0;
	int num = 0;
	for (int i = 0; i < n; ++i)
		if (!ok[i])
		{
			if (sum[i] > max)
			{
				max = sum[i];
				num = 1;
			}
			else if (sum[i] == max)
				++num;
		}
	printf("%d %d\n", max, num);
}

void solve()
{
	BFS();
	work_down();
	work_down2();
	work_up();
	work_tot();
	work_ans();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9215.in", "r", stdin);
	freopen("9215.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}