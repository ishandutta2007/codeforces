#include <cstdio>
#include <queue>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXM = 100005;
const int MAXNUM = 314000000;

int m, n;
std::vector<int> cc[MAXM];
int cx[MAXM];
int cv[MAXM];
std::vector<int> rls[MAXN];
std::vector<int> ind[MAXN];
int ansmin[MAXN];
int ansmax[MAXN];

void init()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
	{
		int p, k;
		scanf("%d%d", &p, &k);
		--p;
		cc[p].reserve(k);
		for (int j = 0; j < k; ++j)
		{
			int x;
			scanf("%d", &x);
			if (x == -1) ++cv[i];
			else
			{
				--x;
				cc[i].push_back(x);
				ind[x].push_back(i);
			}
		}
		cx[i] = p;
		rls[p].push_back(i);
	}
}

void solve1()
{
	std::priority_queue<std::pair<int, int> > pq;
	static int deg[MAXM];

	for (int i = 0; i < m; ++i)
		deg[i] = cc[i].size();

	for (int i = 0; i < m; ++i)
		if (!deg[i])
			pq.push(std::make_pair(-cv[i], cx[i]));

	for (int i = 0; i < n; ++i)
		ansmin[i] = -1;

	while (!pq.empty())
	{
		std::pair<int, int> px = pq.top();
		pq.pop();
		if (ansmin[px.second] != -1) continue;
		int x = px.second;
		ansmin[x] = -px.first;
		for (int i = 0; i < (int)ind[x].size(); ++i)
		{
			int rl = ind[x][i];
			--deg[rl];
			if (deg[rl] == 0)
			{
				int sumw = cv[rl];
				for (int j = 0; j < (int)cc[rl].size(); ++j)
				{
					sumw += ansmin[cc[rl][j]];
					if (sumw > MAXNUM) sumw = MAXNUM;
				}
				pq.push(std::make_pair(-sumw, cx[rl]));
			}
		}
	}
}

void getmaxans(int x)
{
	if (ansmax[x] != -1) return;
	ansmax[x] = -2;
	int max = 0;
	for (int i = 0; i < (int)rls[x].size(); ++i)
	{
		int rl = rls[x][i];
		int sumw = cv[rl];
		bool suminf = false;
		for (int j = 0; j < (int)cc[rl].size(); ++j)
			if (ansmin[cc[rl][j]] == -1)
			{
				sumw = -1; break;
			}
		if (sumw == -1) continue;
		for (int j = 0; j < (int)cc[rl].size(); ++j)
		{
			int u = cc[rl][j];
			if (ansmax[u] == -1) getmaxans(u);
			if (ansmax[u] == -2)
			{
				suminf = true;
				continue;
			}
			sumw += ansmax[u];
			if (sumw > MAXNUM) sumw = MAXNUM;
		}
		if (suminf) return;
		if (sumw > max) max = sumw;
	}
	ansmax[x] = max;
}

void solve2()
{
	for (int i = 0; i < n; ++i)
		ansmax[i] = -1;
	for (int i = 0; i < n; ++i)
		if (ansmin[i] != -1 && ansmax[i] == -1)
			getmaxans(i);
}

void output()
{
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", ansmin[i], ansmax[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8761.in", "r", stdin);
	freopen("8761.out", "w", stdout);
#endif

	init();
	solve1();
	solve2();
	output();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}