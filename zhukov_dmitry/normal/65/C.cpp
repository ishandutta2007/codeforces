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
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{ld x,y,z;};

int n;
tp a[10240];
tp p;
ld t[10240];

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y) + sqr(p1.z-p2.z));
}

tp shift(tp p1, tp p2, ld s)
{
	tp p;
	p.x = p1.x + (p2.x - p1.x) * s;
	p.y = p1.y + (p2.y - p1.y) * s;
	p.z = p1.z + (p2.z - p1.z) * s;
	return p;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n+1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i].x = x;
		a[i].y = y;
		a[i].z = z;
	}
	ld vp, vs;
	int vvp, vvs;
	scanf("%d%d", &vvp, &vvs);
	vp = vvp;
	vs = vvs;
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	p.x = x;
	p.y = y;
	p.z = z;
	t[0] = 0;
	forn(i, n)
	{
		t[i+1] = t[i] + dist(a[i], a[i+1]) / vs;
	}

	forn(i, n)
	{
		ld dd = dist(p, a[i]);
		ld tt = dd / vp;
		if (tt <= t[i] + EPS)
		{
			puts("YES");
			printf("%0.9lf\n", (double)tt);
			printf("%0.9lf %0.9lf %0.9lf\n", (double)a[i].x, (double)a[i].y, (double)a[i].z);
			return 0;
		}

		ld d2 = dist(p, a[i+1]);
		ld t2 = d2 / vp;
//		cerr << tt << " " << t2 << " " << t[i] << " " << t[i+1] << endl;
		if (t2 <= t[i+1] + EPS)
		{
			ld mi = 0.0;
			ld ma = 1.0;

			forn(j, 222)
			{
				ld q = (mi + ma) / 2.0;

				tp pp = shift(a[i], a[i+1], q);

				ld p1 = dist(p, pp) / vp;
				ld s1 = t[i] + dist(a[i], pp) / vs;

				if (p1 <= s1) ma = q;
				else mi = q;
			}
//			cerr << mi << endl;

			ld q = (mi + ma) / 2.0;

			tp pp = shift(a[i], a[i+1], q);

			ld p1 = dist(p, pp) / vp;

			puts("YES");
			printf("%0.9lf\n", (double)p1);
			printf("%0.9lf %0.9lf %0.9lf\n", (double)pp.x, (double)pp.y, (double)pp.z);
			return 0;
		}
	}

	puts("NO");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}