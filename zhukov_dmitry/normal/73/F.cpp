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

#define clr(x) memset((x), 0, sizeof(x))
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

typedef double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{ld x,y;};

int n, k;
tp a[10240];
ld ang[10240];
ld w[10240];
tp p1, p2;
ld b0[10240];
ld tt;

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

inline bool hit(ld s, int i)
{
	if (w[i] < EPS) return false;
	ld da = fabs(ang[i] - b0[i]);
	da = min(da, 2.0 * PI - da);
	ld t = da / w[i];
	if (t <= tt) return true;

	int z = 2;
	forn(j, z)
	{
		ld mi = j * 1.0 / z;
		ld ma = (j + 1.0) / z;
		forn(tt, 101)
		{
			if (ma - mi < 1e-11) break;
			ld q1 = (mi * 2.0 + ma) / 3.0;
			ld q2 = (mi + 2.0 * ma) / 3.0;
	    
			tp pp1, pp2;
			pp1.x = p1.x + (p2.x - p1.x) * q1;
			pp1.y = p1.y + (p2.y - p1.y) * q1;
			pp2.x = p1.x + (p2.x - p1.x) * q2;
			pp2.y = p1.y + (p2.y - p1.y) * q2;
			ld aa1 = atan2(pp1.y - a[i].y, pp1.x - a[i].x);
			ld aa2 = atan2(pp2.y - a[i].y, pp2.x - a[i].x);
			ld a1 = fabs(ang[i] - aa1);
			a1 = min(a1, 2.0 * PI - a1);
			ld a2 = fabs(ang[i] - aa2);
			a2 = min(a2, 2.0 * PI - a2);
			ld t1 = a1 / w[i];
			ld t2 = a2 / w[i];
			ld d1 = dist(p1, pp1);
			ld d2 = dist(p1, pp2);
			t1 -= d1 / s;
			t2 -= d2 / s;
			if (t1 <= 0.0) return true;
			if (t2 <= 0.0) return true;
			if (t1 < t2) ma = q2;
			else mi = q1;
		}
	}
	return false;
}

bool check(ld s)
{
	int cnt = 0;
	tt = dist(p1, p2) / s;
	forn(i, n)
	{
		if (cnt + n - i <= k) return true;
		cnt += hit(s, i);
		if (cnt > k) return false;
	}
	return cnt <= k;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int x, y;
	scanf("%d%d", &x, &y);
	p1.x = x;
	p1.y = y;
	scanf("%d%d", &x, &y);
	p2.x = x;
	p2.y = y;
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &x, &y);
		a[i].x = x;
		a[i].y = y;
		double aa, ww;
		scanf("%lf%lf", &aa, &ww);
		if (aa > PI)
		{
			aa -= 2.0 * PI;
		}
		ang[i] = aa;
		w[i] = ww;
	}
	scanf("%d", &k);
	forn(i, n)
	{
		b0[i] = atan2(p2.y - a[i].y, p2.x - a[i].x);
	}

	ld mi = 3e-5;
	ld ma = 4e+6;

	while (ma - mi > 3e-5 && (ma - mi) / (ma + mi) > 3e-5)
	{
		ld q = (mi + ma) * 0.5;
		*(check(q) ? &ma : &mi) = q;
	}
	printf("%0.5lf\n", (double)mi);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}