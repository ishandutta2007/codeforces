#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <vector>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXK = 10005;
const int MAXS = 25;
const int INF = 0x3f3f3f3f;

template<class W, int MAXN>
struct Heap
{
	int n;
	int a[MAXN];
	int pos[MAXN];

	void shift_down(int x);
	void shift_up(int x);
	void clear();
	void build();
	void pop();
	void insert(int x);
};

template<class W, int MAXN>
void Heap<W, MAXN>::shift_down(int x)
{
	if (x * 2 + 1 >= n)
		return;
	int p = (x * 2 + 2 >= n ? x * 2 + 1 :
			W()(a[x * 2 + 1], a[x * 2 + 2]) ? x * 2 + 1 : x * 2 + 2);
	if (W()(a[p], a[x]))
	{
		int tmp = a[p];
		a[p] = a[x];
		a[x] = tmp;
		pos[a[x]] = x;
		pos[a[p]] = p;
		shift_down(p);
	}
}

template<class W, int MAXN>
void Heap<W, MAXN>::shift_up(int x)
{
	if (x == 0)
		return;
	int p = (x - 1) / 2;
	if (W()(a[x], a[p]))
	{
		int tmp = a[p];
		a[p] = a[x];
		a[x] = tmp;
		pos[a[x]] = x;
		pos[a[p]] = p;
		shift_up(p);
	}
}

template<class W, int MAXN>
void Heap<W, MAXN>::clear()
{
	n = 0;
	memset(pos, -1, sizeof(pos));
}

template<class W, int MAXN>
void Heap<W, MAXN>::build()
{
	for (int i = 0; i < n; ++i)
		pos[a[i]] = i;
	for (int i = n - 1; i >= 0; --i)
		shift_down(i);
}

template<class W, int MAXN>
void Heap<W, MAXN>::pop()
{
	pos[a[0]] = -1;
	--n;
	if (n)
	{
		a[0] = a[n];
		pos[a[0]] = 0;
		shift_down(0);
	}
}

template<class W, int MAXN>
void Heap<W, MAXN>::insert(int x)
{
	a[n++] = x;
	pos[x] = n - 1;
	shift_up(n - 1);
}

struct CmpW;

int n, m, k;
long long pos[MAXN];
int w[MAXN];
long long sk[MAXS];
int skn;
std::vector<int> c[MAXK];
long long minpos[MAXK];
Heap<CmpW, MAXN> hp;

struct CmpW
{
	bool operator()(const int &x, const int &y)
	{
		return w[x] > w[y] || (w[x] == w[y] && x < y);
	}
};

struct CmpDis
{
	bool operator()(const int &x, const int &y)
	{
		return minpos[x] < minpos[y];
	}
};

bool cmp_pos(const int &x, const int &y)
{
	return pos[x] < pos[y];
}

void input()
{
	scanf("%*d%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%"LLFORMAT"d%d", &pos[i], &w[i]);
		--pos[i];
	}
}

void init()
{
	for (int i = 0; i < n; ++i)
		c[pos[i] % k].push_back(i);
	for (int i = 0; i < k; ++i)
		std::sort(c[i].begin(), c[i].end(), cmp_pos);
	memset(minpos, INF, sizeof(minpos));
	minpos[0] = 0;
	hp.clear();
	for (int i = 0; i < k; ++i)
		while (!c[i].empty() && pos[c[i].back()] >= minpos[i])
		{
			hp.a[hp.n++] = c[i].back();
			c[i].pop_back();
		}
	hp.build();
}

void work_minpos()
{
	Heap<CmpDis, MAXK> ds;
	ds.clear();
	ds.n = k;
	for (int i = 0; i < k; ++i)
		ds.a[i] = i;
	ds.build();
	for (int i = 0; i < k; ++i)
	{
		int x = ds.a[0];
		ds.pop();
		for (int j = 0; j < skn; ++j)
			if (minpos[x] + sk[j] < minpos[(x + sk[j]) % k])
			{
				minpos[(x + sk[j]) % k] = minpos[x] + sk[j];
				ds.shift_up(ds.pos[(x + sk[j]) % k]);
			}
	}
	for (int i = 0; i < k; ++i)
		while (!c[i].empty() && pos[c[i].back()] >= minpos[i])
		{
			hp.insert(c[i].back());
			c[i].pop_back();
		}
}

void solve()
{
	while (m--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			long long x;
			scanf("%"LLFORMAT"d", &x);
			sk[skn++] = x;
			work_minpos();
		}
		else if (type == 2)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			w[x] -= y;
			if (pos[x] >= minpos[pos[x] % k])
				hp.shift_down(hp.pos[x]);
		}
		else if (type == 3)
		{
			if (hp.n)
			{
				int minp = hp.a[0];
				hp.pop();
				printf("%d\n", w[minp]);
			}
			else
				printf("0\n");
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9200.in", "r", stdin);
	freopen("9200.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}