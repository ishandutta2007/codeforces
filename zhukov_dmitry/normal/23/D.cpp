#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)

template <class _T> inline _T sqr(const _T& x) { return x * x; }

typedef long double ld;

const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

struct tp{ld x,y;};
struct tl{ld a,b,c;};

tp p[4];
tp a[8];

ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

ld dist2(tp p1, tp p2)
{
	return (sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

tl findline(tp p1, tp p2)
{
	tl l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -l.a * p1.x - l.b * p1.y;
	return l;
}

tl findperp(tl l, tp p)
{
	tl l1;
	l1.a = l.b;
	l1.b = -l.a;
	l1.c = -l1.a * p.x - l1.b * p.y;
	return l1;
}

ld vp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.y - p1.y * p2.x;
}

ld sp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.x + p1.y * p2.y;
}

bool findpoint(tl l1, tl l2, tp& p)
{
	ld d = l1.a * l2.b - l1.b * l2.a;
	if (fabs(d) < EPS) return false;
	p.x = (l1.b * l2.c - l1.c * l2.b) / d;
	p.y = (l1.c * l2.a - l1.a * l2.c) / d;
	return true;
}

tp shifth(tp p1, tp p2, ld d)
{
	tp p;
	p.x = p1.x + (p2.x - p1.x) * d;
	p.y = p1.y + (p2.y - p1.y) * d;
	return p;
}

bool check(tp *a, int n)
{
	a[n] = a[0];
	ld s = 0.0;
	forn(i, n)
	{
		s += a[i].x * a[i+1].y - a[i].y * a[i+1].x;
	}
	if (s < 0.0)
	{
		s = -s;
		reverse(a, a+n);
		a[n] = a[0];
	}
	forn(i, n)
	{
		forn(j, n)
		{
			if (j == i || j == (i+1) % n) continue;
			if (vp(a[i], a[i+1], a[j]) <= 0 + EPS) return false;
		}
	}
	return true;
}

bool solve(tp *p, tp *a)
{
	tl l1 = findline(p[0], p[1]);
	tl l2 = findline(p[0], p[2]);
	tp p1 = shifth(p[0], p[1], 0.5);
	tp p2 = shifth(p[0], p[2], 0.5);
	tl l3 = findperp(l1, p1);
	tl l4 = findperp(l2, p2);
	tp p3;
	if (!findpoint(l3, l4, p3)) return false;
	tp p4 = shifth(p3, p[0], 2.0);
	tl l5 = l3;
	l5.c = -l5.a * p4.x - l5.b * p4.y;
	tl l6 = l4;
	l6.c = -l6.a * p4.x - l6.b * p4.y;
	if (!findpoint(l3, l6, a[1])) return false;
	if (!findpoint(l4, l5, a[2])) return false;
	a[0] = shifth(a[1], p[1], 2.0);
	a[3] = shifth(a[2], p[2], 2.0);

	return check(a, 4);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		forn(i, 3)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			p[i].x = x;
			p[i].y = y;
		}

		bool ok = false;
		forn(i, 3)
		{
			if (solve(p, a))
			{
				ok = true;
				break;
			}
			swap(p[0], p[1]);
			swap(p[1], p[2]);
		}
		if (ok)
		{
			puts("YES");
			forn(i, 4)
			{
				if (i) putchar(' ');
				printf("%0.11lf %0.11lf", (double)a[i].x, (double)a[i].y);
			}
			puts("");
		}
		else
		{
			puts("NO\n");
		}
	}

	return 0;
}