#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int INF = 0x3f3f3f3f;

struct tp{int x,y;};

typedef set < tp > :: iterator IT;

set < tp > l, r;
tp a[3];

inline int vp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	i64 d = (i64)p1.x * p2.y - (i64)p1.y * p2.x;
	if (d > 0) return 1;
	if (d < 0) return -1;
	return 0;
}

bool operator < (tp p1, tp p2)
{
	return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

bool check(int x, int y)
{
	tp p;
	p.x = -INF;
	p.y = y;
	int ymi = l.begin()->y;
	IT it = l.end(), it1;
	it--;
	int yma = it->y;
	if (y < ymi || y > yma) return false;
	it = r.lower_bound(p);
	if (it->y == y)
	{
		if (x > it->x) return false;
	}
	else
	{
		it1 = it;
		it1--;
		p.x = x;
		if (vp(*it1, *it, p) < 0) return false;
	}
	it = l.lower_bound(p);
	if (it->y == y)
	{
		if (x < it->x) return false;
	}
	else
	{
		it1 = it;
		it1--;
		p.x = x;
		if (vp(*it1, *it, p) > 0) return false;
	}
	return true;
}

void update_l(IT it)
{
	IT it1, it2;
	for(;;)
	{
		it1 = it;
		it1++;
		if (it1 == l.end()) break;
		it2 = it1;
		it2++;
		if (it2 == l.end()) break;
		if (vp(*it, *it1, *it2) >= 0)
		{
			l.erase(it1);
		}
		else break;
	}
	for(;;)
	{
		it1 = it;
		if (it1 == l.begin()) break;
		it1--;
		it2 = it1;
		if (it2 == l.begin()) break;
		it2--;
		if (vp(*it2, *it1, *it) >= 0)
		{
			l.erase(it1);
		}
		else break;
	}
}

void update_r(IT it)
{
	IT it1, it2;
	for(;;)
	{
		it1 = it;
		it1++;
		if (it1 == r.end()) break;
		it2 = it1;
		it2++;
		if (it2 == r.end()) break;
		if (vp(*it, *it1, *it2) <= 0)
		{
			r.erase(it1);
		}
		else break;
	}
	for(;;)
	{
		it1 = it;
		if (it1 == r.begin()) break;
		it1--;
		it2 = it1;
		if (it2 == r.begin()) break;
		it2--;
		if (vp(*it2, *it1, *it) <= 0)
		{
			r.erase(it1);
		}
		else break;
	}
}

void add(int x, int y)
{
	if (check(x, y)) return;

	tp p;
	int ymi = l.begin()->y;
	IT it = l.end(), it1, it2;
	it--;
	int yma = it->y;
	if (y > yma || y < ymi)
	{
		p.x = x;
		p.y = y;
		l.insert(p);
		update_l(l.find(p));
		r.insert(p);
		update_r(r.find(p));
	}
	else
	{
		p.x = -INF;
		p.y = y;
		it = r.lower_bound(p);
		if (it->y == y)
		{
//			it = r.begin();
			if (it->x < x)
			{
				p.x = x;
				p.y = y;
				r.erase(it);
				r.insert(p);
				update_r(r.find(p));
			}
		}
		else
		{
			it1 = it;
			it1--;
			p.x = x;
			if (vp(*it1, *it, p) < 0)
			{
				p.x = x;
				r.insert(p);
				update_r(r.find(p));
			}
		}
		p.x = -INF;
		p.y = y;
		it = l.lower_bound(p);
		if (it->y == y)
		{
//			it = l.begin();
			if (it->x > x)
			{
				p.x = x;
				p.y = y;
				l.erase(it);
				l.insert(p);
				update_l(l.find(p));
			}
		}
		else
		{
			it1 = it;
			it1--;
			p.x = x;
			if (vp(*it1, *it, p) > 0)
			{
				p.x = x;
				l.insert(p);
				update_l(l.find(p));
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int q;
	scanf("%d", &q);
	q -= 3;
	forn(i, 3)
	{
		int x, y;
		scanf("%*d%d%d", &x, &y);
		a[i].x = x;
		a[i].y = y;
	}
	sort(a, a+3);
	l.insert(a[0]);
	r.insert(a[0]);
	l.insert(a[2]);
	r.insert(a[2]);
	add(a[1].x, a[1].y);

	forn(tt, q)
	{
		int x, y, z;
		scanf("%d%d%d", &z, &x, &y);
		if (z == 1)
		{
			add(x, y);
		}
		else
		{
			puts(check(x, y) ? "YES" : "NO");
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}