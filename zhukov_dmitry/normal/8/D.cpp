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
const ld EPS = 1e-14;
const ld EPS2 = 1e-14;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{ld x,y;};

ld t1, t2;
tp p0, p1, p2;
ld d01, d02, d12;

ld dist(tp p1, tp p2)
{
	return sqrtl(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

ld dist2(tp p1, tp p2)
{
	return (sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

void rot(tp &p, ld aa)
{
	ld sn = sinl(aa);
	ld cs = cosl(aa);
	tp pn;
	pn.x = p.x * cs - p.y * sn;
	pn.y = p.y * cs + p.x * sn;
	p = pn;
}

ld solve(ld mi, ld ma)
{
	ld ans = 0.0;
	ld ma0 = ma;
	forn(tt, 74)
	{
		ld q = (mi + ma) * 0.5;

		ld mmi = 0.0;
		ld mma = 1e+4;
		ld cs = cosl(q);
		ld sn = sinl(q);
		tp pp;
		if (t2 < EPS)
		{
			pp.x = d02 - d02 * q / ma0;
			pp.y = 0.0;
		}
		else
		{
			forn(tt2, 123)
			{
				ld qq = (mmi + mma) * 0.5;
				tp ppm;
				ppm.x = qq * cs;
				ppm.y = qq * sn;

				*(dist(p0, ppm) + dist(ppm, p2) <= d02 + t2 ? &mmi : &mma) = qq;
			}

			ld qq = (mmi + mma) * 0.5;
			pp.x = qq * cs;
			pp.y = qq * sn;
		}

		*(dist(p0, pp) + dist(pp, p1) <= d01 + t1 ? &ma : &mi) = q;

		if (dist(p0, pp) + dist(pp, p1) <= d01 + t1 + EPS2 && dist(p0, pp) + dist(pp, p2) <= d02 + t2 + EPS2)
		{
			ans = max(ans, dist(p0, pp));
		}
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >> t1 >> t2;
	cin >> p0.x >> p0.y;
	cin >> p2.x >> p2.y;
	cin >> p1.x >> p1.y;

	d01 = dist(p0, p1);
	d02 = dist(p0, p2);
	d12 = dist(p1, p2);
	if (d01 < 1e-7 || d02 < 1e-7 || d12 < 1e-7 || p0.x < -101.0 || p0.x > 101.0 || p1.x < -101.0 || p1.x > 101.0 || p1.x < -101.0 || p1.x > 101.0 || p0.y < -101.0 || p0.y > 101.0 || p1.y < -101.0 || p1.y > 101.0 || p1.y < -101.0 || p1.y > 101.0) for(;;);

	if (d01 + d12 <= d02 + t2 + EPS)
	{
		cout << min(d01 + d12 + t1, d02 + t2) << endl;
	}
	else
	{
		ld ans = 0.0;

		if (d02 + d12 + d12 <= d01 + d12 + t1 + EPS)
		{
			ld dd = d01 + d12 + t1 - d02 - d12 - d12;
			ans = d02 + min(dd, t2);
			if (dd < t2)
			{
				ans = max(ans, d02 + dd + (t2 - dd) * 0.5);
			}
			cout << ans << endl;
			return 0;
		}

		p1.x -= p0.x;
		p1.y -= p0.y;
		p2.x -= p0.x;
		p2.y -= p0.y;
		p0.x = p0.y = 0.0;

		ld aa = atan2(p2.y, p2.x);
		rot(p1, -aa);
		rot(p2, -aa);

		if (p1.y < 0.0) p1.y *= -1;

		ld dt = (d01 + d12 + t1 - (d02 + t2)) * 0.5;
		tp pc;
		pc.x = p1.x + (p2.x - p1.x) / d12 * dt;
		pc.y = p1.y + (p2.y - p1.y) / d12 * dt;

		if (dist(p0, pc) + dist(pc, p1) <= d01 + t1 + EPS && dist(p0, pc) + dist(pc, p2) <= d02 + t2 + EPS)
		{
			ans = d02 + t2 - dist(pc, p2);
			cout << ans << endl;
			return 0;
		}

		ld ma = fabs(atan2(p1.y, p1.x));
		ld mi = 0.0;

		ans = max(ans, solve(mi, ma));

		cout << ans << endl;
	}

	return 0;
}