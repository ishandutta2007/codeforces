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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

struct tp{int x,y;};

tp p[10];
int a[10];

int dist2(tp p1, tp p2)
{
	return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}

bool right(tp *p)
{
	forn(i, 3)
	{
		a[i] = dist2(p[i], p[(i+1)%3]);
	}
	sort(a, a+3);
	return a[0] > 0 && a[0] + a[1] == a[2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	forn(i, 3)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	if (right(p))
	{
		puts("RIGHT");
		return 0;
	}
	forn(i, 3)
	{
		forn(l, 4)
		{
			p[i].x += dx[l];
			p[i].y += dy[l];

			if (right(p))
			{
				puts("ALMOST");
				return 0;
			}

			p[i].x -= dx[l];
			p[i].y -= dy[l];
		}
	}

	puts("NEITHER");

	return 0;
}