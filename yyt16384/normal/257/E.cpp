#include <algorithm>
#include <cstdio>
#include <set>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;

struct Data
{
	int id;
	int floor;
};

struct Person
{
	int id;
	long long time;
	int from, to;
};

bool operator<(const Data &x, const Data &y)
{
	return x.floor < y.floor;
}

bool operator>(const Data &x, const Data &y)
{
	return x.floor > y.floor;
}

bool operator<(const Person &x, const Person &y)
{
	return x.time < y.time;
}

int n, m;
Person a[MAXN];
long long ans[MAXN];

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%"LLFORMAT"d%d%d", &a[i].time, &a[i].from, &a[i].to);
		a[i].id = i;
	}
}

void solve()
{
	int now = 1;
	long long nowt = 0;
	std::multiset<Data, std::less<Data> > ups;
	std::multiset<Data, std::greater<Data> > downs;
	std::sort(a, a + n);
	a[n].time = INFLL;
	for (int i = 0; i <= n; ++i)
	{
		while (!ups.empty() || !downs.empty())
		{
			Data dt;
			int dir;
			if (!ups.empty() && ups.begin()->floor == now)
				dir = 1;
			else if (!downs.empty() && downs.begin()->floor == now)
				dir = -1;
			else if (ups.size() >= downs.size())
				dir = 1;
			else
				dir = -1;
			if (dir == 1)
				dt = *ups.begin();
			else
				dt = *downs.begin();
			long long time = (dt.floor - now) / dir;
			if (nowt + time <= a[i].time)
			{
				now += time * dir;
				nowt += time;
				if (dir == 1)
					ups.erase(ups.begin());
				else
					downs.erase(downs.begin());
				int id = dt.id;
				if (id >= 0)
				{
					Data tmp;
					tmp.id = -id - 1;
					tmp.floor = a[id].to;
					if (tmp.floor > now)
						ups.insert(tmp);
					else
						downs.insert(tmp);
				}
				else
					ans[a[-id - 1].id] = nowt;
			}
			else
			{
				now += (a[i].time - nowt) * dir;
				nowt = a[i].time;
				break;
			}
		}
		if (ups.empty() && downs.empty())
			nowt = a[i].time;
		Data tmp;
		tmp.id = i;
		tmp.floor = a[i].from;
		if (tmp.floor > now)
			ups.insert(tmp);
		else
			downs.insert(tmp);
	}

	for (int i = 0; i < n; ++i)
		printf("%"LLFORMAT"d\n", ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9179.in", "r", stdin);
	freopen("9179.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}