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

int n, m;
bool a[20][20];
i64 d[20][1 << 19];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	clr(a);
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x][y] = a[y][x] = 1;
	}

	i64 s[20];
	clr(s);
	forn(i, n)
	{
		clr(d);
		d[i][1 << i] = 1;
		int m = i+1;
		forn(mask, 1 << m)
		{
			int z = __builtin_popcount(mask);
			forn(j, m)
			{
				i64 &dd = d[j][mask];
				if (!dd) continue;
				forn(l, m)
				{
					if (!a[j][l]) continue;
					if (l == i) s[z] += dd;
					if (mask & (1 << l)) continue;
					d[l][mask | (1 << l)] += dd;
				}
			}
		}
	}

	i64 ans = 0;
	For(i, 3, n)
	{
		ans += s[i];
	}
	cout << ans / 2 << endl;

	return 0;
}