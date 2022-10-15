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

struct tp{int x,y;};

tp a[10][2];
tp b[10][2];
SI xs, ys;
tp p[4];
bool u[10];

bool operator < (tp p1, tp p2)
{
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

bool operator == (tp p1, tp p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	forn(i, 4)
	{
		forn(j, 2)
		{
			scanf("%d%d", &a[i][j].x, &a[i][j].y);
			xs.insert(a[i][j].x);
			ys.insert(a[i][j].y);
		}
		sort(a[i], a[i]+2);
	}

	if (xs.sz != 2 || ys.sz != 2)
	{
		puts("NO");
		return 0;
	}

	int k = 0;
	fori(itx, xs)
	{
		fori(ity, ys)
		{
			p[k].x = *itx;
			p[k].y = *ity;
			k++;
		}
	}

	b[0][0] = p[0];
	b[0][1] = p[1];
	b[1][0] = p[0];
	b[1][1] = p[2];
	b[2][0] = p[1];
	b[2][1] = p[3];
	b[3][0] = p[2];
	b[3][1] = p[3];

	clr(u);
	forn(i, 4)
	{
		sort(b[i], b[i]+2);
		forn(j, 4)
		{
			if (a[j][0] == b[i][0] && a[j][1] == b[i][1])
			{
				u[j] = true;
				break;
			}
		}
	}

	forn(i, 4)
	{
		if (!u[i])
		{
			puts("NO");
			return 0;
		}
	}

	puts("YES");

	return 0;
}