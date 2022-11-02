#include <algorithm>
#include <cstdio>
#include <map>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

struct Board
{
	int h, l, r;

	friend bool operator<(const Board &x, const Board &y)
	{
		return x.h < y.h;
	}
};

typedef std::map<int, int>::iterator IterMap;

int n;
Board a[MAXN];
int f[MAXN];

void init()
{
	int t;
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r);

	a[n].h = 0;
	a[n].l = -INF;
	a[n].r = INF;
	++n;

	a[n].h = t;
	a[n].l = -INF;
	a[n].r = INF;
	++n;
}

void solve()
{
	std::sort(a, a + n);
	std::map<int, int> mp;
	mp[-INF - 1] = 0;
	mp[INF + 1] = 0;

	f[0] = 2 * INF;
	for (int i = 1; i < n; ++i)
	{
		IterMap st = mp.lower_bound(a[i].l);
		IterMap it;
		for (it = st, --it; it->first < a[i].r; ++it)
		{
			IterMap pre = it;
			if (pre != mp.begin()) --pre;
			IterMap suc = it;
			++suc;

			int nowx = it->second;
			int prex = pre->second;
			int sucx = suc->second;
			if ((a[nowx].h >= a[prex].h || a[nowx].l >= a[prex].r || a[i].l >= a[prex].r) &&
					(a[nowx].h >= a[sucx].h || a[nowx].r <= a[sucx].l || a[i].r <= a[sucx].l))
			{
				int ll = std::max(a[i].l, a[nowx].l);
				int rr = std::min(a[i].r, a[nowx].r);
				int ww = std::min(f[nowx], rr - ll);
				if (ww > f[i]) f[i] = ww;
			}
		}

		--it;
		int last = it->second;
		++it;
		mp.erase(st, it);
		if (a[i].r != it->first) mp[a[i].r] = last;
		mp[a[i].l] = i;
	}

	printf("%d\n", f[n-1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8778.in", "r", stdin);
	freopen("8778.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}