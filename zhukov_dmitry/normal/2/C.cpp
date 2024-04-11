#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

struct tp{ld x,y;};
struct tl{ld a,b,c;};

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

inline ld dist2(tp p1, tp p2)
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

ld distline(tl l, tp p)
{
	return (l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

void norm(tl &l)
{
	ld d = sqrt(l.a * l.a + l.b * l.b);
	l.a /= d;
	l.b /= d;
	l.c /= d;
}

bool onseg(tp p, tp p1, tp p2)
{
	tl l = findline(p1, p2);
	if (fabs(distline(l, p)) > EPS) return false;
	return fabs(dist(p1, p2) - dist(p, p1) - dist(p, p2)) < EPS;
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

int findcircline(tp c, ld r, tl l, tp *ps)
{
	ld h = fabs(distline(l, c));
	if (h > r - EPS) return 0;
	tl l1 = findperp(l, c);
	tp p;
	ld d = sqrt(l.a * l.a + l.b * l.b);
	h = sqrt(fabs(r * r - h * h));
	findpoint(l, l1, p);
	ps[0].x = p.x + l1.a * h / d;
	ps[0].y = p.y + l1.b * h / d;
	ps[1].x = p.x - l1.a * h / d;
	ps[1].y = p.y - l1.b * h / d;
	return (dist(ps[0], ps[1]) > EPS) + 1;
}

int findcirccirc(tp c1, ld r1, tp c2, ld r2, tp *ps)
{
	tl l;
	l.a = 2.0 * (c2.x - c1.x);
	l.b = 2.0 * (c2.y - c1.y);
	l.c = c1.x * c1.x + c1.y * c1.y - c2.x * c2.x - c2.y * c2.y + r2 * r2 - r1 * r1;
	return findcircline(c1, r1, l, ps);
}

tp shift(tp p1, tp p2, ld d)
{
	tp p;
	ld h = dist(p1, p2);
	p.x = p1.x + (p2.x - p1.x) / h * d;
	p.y = p1.y + (p2.y - p1.y) / h * d;
	return p;
}

istream & operator >> (istream &is, tp &p)
{
	is >> p.x >> p.y;
	return is;
}



int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(5);

	tp a[3];
	ld r[3];
	forn(i, 3)
	{
		cin >> a[i] >> r[i];
	}

	forn(i, 3)
	{
		forn(j, i)
		{
			if (r[j] > r[i])
			{
				swap(r[i], r[j]);
				swap(a[i], a[j]);
			}
		}
	}

	if (fabs(r[0] - r[2]) < EPS)
	{
		tl l[2];
		tl lp[2];
		forn(i, 2)
		{
			l[i] = findline(a[i], a[i+1]);
			tp p;
			p.x = (a[i].x + a[i+1].x) * 0.5;
			p.y = (a[i].y + a[i+1].y) * 0.5;
			lp[i] = findperp(l[i], p);
		}
		tp pp;
		findpoint(lp[0], lp[1], pp);
		cout << pp.x << " " << pp.y << endl;
		return 0;
	}

	if (fabs(r[1] - r[2]) < EPS)
	{
		swap(r[0], r[2]);
		swap(a[0], a[2]);
	}

	tp pc[2];
	ld rc[2];
	forn(i, 2)
	{
		ld mi = r[i];
		ld dd = dist(a[i], a[2]);
		ld ma = dd - r[2];
		forn(tt, 239)
		{
			ld q = (mi + ma) * 0.5;
			ld a0 = asin(r[i] / q);
			ld a1 = asin(r[2] / (dd - q));

			if (a0 > a1) mi = q;
			else ma = q;
		}

		tp pp1 = shift(a[i], a[2], mi);
//		cerr << pp1.x << " " << pp1.y << endl;

		tp p1 = a[i];
		ld r1 = r[i];
		tp p2 = a[2];
		ld r2 = r[2];
		if (r1 < r2)
		{
			swap(r1, r2);
			swap(p1, p2);
		}
		mi = dd + r2;
		ma = dd + r2 + 1e+8;
		forn(tt, 239)
		{
			ld q = (mi + ma) * 0.5;
			ld a0 = asin(r1 / q);
			ld a1 = asin(r2 / (q - dd));

			if (a0 > a1) ma = q;
			else mi = q;
		}

		tp pp2 = shift(p1, p2, mi);
//		cerr << pp2.x << " " << pp2.y << endl;

		pc[i].x = (pp1.x + pp2.x) * 0.5;
		pc[i].y = (pp1.y + pp2.y) * 0.5;
		rc[i] = dist(pc[i], pp1);
	}

	tp ps[2];
	int cnt = findcirccirc(pc[0], rc[0], pc[1], rc[1], ps);

	ld ans = 1e+20;
	tp pa;
	pa.x = -1.0;
	pa.y = -1.0;
	forn(i, cnt)
	{
		ld d = dist(ps[i], a[0]);
		if (d < ans)
		{
			ans = d;
			pa = ps[i];
		}
	}

	if (ans < 1e+19)
	{
		cout << pa.x << " " << pa.y << endl;
	}

	return 0;
}