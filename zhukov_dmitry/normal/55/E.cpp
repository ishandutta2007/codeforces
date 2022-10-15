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
const ld EPS = 1e-11;

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

struct tp{int x,y;};

int n;
tp a[202400];
tp p0;

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

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	p0.x = p0.y = 0;
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	forn(i, n)
	{
		a[i+n] = a[i];
	}
	i64 s = 0;
	forn(i, n)
	{
		s += (i64)a[i].x * a[i+1].y - (i64)a[i].y * a[i+1].x;
	}
	if (s < 0)
	{
		reverse(a, a+n);
		reverse(a+n, a+n+n);
	}

	int k;
	scanf("%d", &k);
	forn(tt, k)
	{
		tp p;
		scanf("%d%d", &p.x, &p.y);
		bool bb = false;
		forn(i, n)
		{
			if (vp(a[i], a[i+1], p) <= 0)
			{
				bb = true;
				break;
			}
		}
		if (bb)
		{
			puts("0");
			continue;
		}
		i64 ans = (i64)n * (n-1) * (n-2) / 6;

		int r = 0;
		forn(i, n)
		{
			while (vp(a[i], a[r+1], p) > 0) r++;
			int c = r - i;
			ans -= (i64)c * (c-1) / 2;
		}

		printf("%I64d\n", ans);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %ld ms\n", (et_1 - et_0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}