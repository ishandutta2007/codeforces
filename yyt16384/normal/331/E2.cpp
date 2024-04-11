#include <algorithm>
#include <cstdio>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 55;
const int MAXS = 10105;
const int MOD = 1000000007;

int n;
bool g[MAXN][MAXN];
std::vector<int> e[MAXN][MAXN];
std::vector<int> tr[MAXS];
int f[MAXS];

void input()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y, nv;
		scanf("%d%d%d", &x, &y, &nv);
		--x; --y;
		std::vector<int> ev(nv);
		for (int j = 0; j < nv; ++j)
		{
			int v;
			scanf("%d", &v);
			--v;
			ev[j] = v;
		}
		g[x][y] = true;
		e[x][y] = ev;
	}
}

int check_edge(const std::vector<int> &a, int x, int y)
{
	if (a.empty()) return -1;
	for (std::vector<int>::const_iterator i = a.begin(); i + 1 != a.end(); ++i)
		if (*i == x && *(i + 1) == y) return i - a.begin();
	return -1;
}

int walk(std::vector<int> &a, int now, bool reverse)
{
	for (int k = 0; (int)a.size() < 2 * n && k < (int)a.size(); ++k)
	{
		if ((!reverse && !g[now][a[k]]) || (reverse && !g[a[k]][now]))
			return -1;
		if (!reverse)
			a.insert(a.end(), e[now][a[k]].begin(), e[now][a[k]].end());
		else
		{
			a.insert(a.end(), e[a[k]][now].rbegin(), e[a[k]][now].rend());
		}
		now = a[k];
	}
	if ((int)a.size() >= 2 * n) return -1;
	return now;
}

void add_trans(int x, int y, int len)
{
	for (int i = 0; i + len <= 2 * n; ++i)
		tr[i * (2 * n) + x].push_back((i + len) * (2 * n) + y);
}

void init()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (g[i][j])
			{
				int pos;
				if ((pos = check_edge(e[i][j], i, j)) != -1)
				{
					std::vector<int> tmpl(e[i][j].begin(), e[i][j].begin() + pos);
					std::reverse(tmpl.begin(), tmpl.end());
					int nowl = walk(tmpl, i, true);

					std::vector<int> tmpr(e[i][j].begin() + (pos + 2), e[i][j].end());
					int nowr = walk(tmpr, j, false);

					if (nowl != -1 && nowr != -1)
						add_trans(nowl, nowr + n, tmpl.size() + tmpr.size() + 1);
				}
				if (e[i][j].empty())
				{
					add_trans(i + n, j, 1);
				}
				if (!e[i][j].empty() && e[i][j].front() == j)
				{
					std::vector<int> tmp(e[i][j].begin() + 1, e[i][j].end());
					int now = walk(tmp, j, false);

					if (now != -1)
						add_trans(i + n, now + n, tmp.size() + 1);
				}
				if (!e[i][j].empty() && e[i][j].back() == i)
				{
					std::vector<int> tmp(e[i][j].begin(), e[i][j].end() - 1);
					std::reverse(tmp.begin(), tmp.end());
					int now = walk(tmp, i, true);

					if (now != -1)
						add_trans(now, j, tmp.size() + 1);
				}
			}
}

void solve()
{
	int totstate = (2 * n + 1) * (2 * n);

	for (int i = 0; i < n; ++i)
		f[i] = 1;
	for (int i = 0; i < totstate; ++i)
		for (std::vector<int>::const_iterator j = tr[i].begin(); j != tr[i].end(); ++j)
			(f[*j] += f[i]) %= MOD;

	for (int i = 1; i <= 2 * n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
			(sum += f[i * (2 * n) + j + n]) %= MOD;
		printf("%d\n", sum);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8785.in", "r", stdin);
	freopen("8785.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}