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
const ld EPS = 1e-6;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{ld x,y;};

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
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
	cout << setiosflags(ios::fixed) << setprecision(10);

	tp a[4];

	forn(i, 3)
	{
		cin >> a[i];
	}

	ld c0 = fabs(atan2(vp(a[0], a[1], a[2]), sp(a[0], a[1], a[2]))) * 2.0;
	ld c1 = fabs(atan2(vp(a[1], a[0], a[2]), sp(a[1], a[0], a[2]))) * 2.0;

	For(ans, 3, 100)
	{
		bool b0 = false;
		bool b1 = false;
		forn(j, ans+1)
		{
			if (fabs(2.0 * PI / ans * j - c0) < EPS) b0 = true;
			if (fabs(2.0 * PI / ans * j - c1) < EPS) b1 = true;
		}

		if (!b0 || !b1) continue;
		printf("%0.10lf\n", (double)(sqr(dist(a[0], a[1]) * dist(a[1], a[2]) * dist(a[2], a[0]) / 2.0 / fabs(vp(a[0], a[1], a[2]))) * sin(2.0 * PI / ans) * 0.5 * ans));
		return 0;
	}

	return 0;
}