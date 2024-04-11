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

int n, m, h, v, d, k;
int a[128][128][2];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d%d%d", &n, &m, &h, &v, &d);
	int nn = n;
	int mm = m;
	if (n * m % 2 == 1 || n * m > h * 2 + v * 2 + d * 4)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	k = 0;
	if (n % 2 == 1)
	{
		if (h * 2 < m)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		forn(i, m/2)
		{
			a[n-1][i * 2][0] = 0;
			a[n-1][i * 2][1] = k;
			a[n-1][i * 2 + 1][0] = 0;
			a[n-1][i * 2 + 1][1] = k;
			k++;
			h--;
		}
		n--;
	}
	if (m % 2 == 1)
	{
		if (v * 2 < n)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		forn(i, n/2)
		{
			a[i * 2][m-1][0] = 1;
			a[i * 2][m-1][1] = k;
			a[i * 2 + 1][m-1][0] = 1;
			a[i * 2 + 1][m-1][1] = k;
			k++;
			v--;
		}
		m--;
	}
	h -= h & 1;
	v -= v & 1;

	if (n * m > h * 2 + v * 2 + d * 4)
	{
		puts("IMPOSSIBLE");
		return 0;
	}

	forn(i, n/2)
	{
		forn(j, m/2)
		{
			if (d > 0)
			{
				a[i * 2][j * 2][0] = 2;
				a[i * 2][j * 2][1] = k;
				a[i * 2][j * 2 + 1][0] = 2;
				a[i * 2][j * 2 + 1][1] = k;
				a[i * 2 + 1][j * 2][0] = 2;
				a[i * 2 + 1][j * 2][1] = k;
				a[i * 2 + 1][j * 2 + 1][0] = 2;
				a[i * 2 + 1][j * 2 + 1][1] = k;
				k++;
				d--;
			}
			else if (h > 1)
			{
				a[i * 2][j * 2][0] = 0;
				a[i * 2][j * 2][1] = k;
				a[i * 2][j * 2 + 1][0] = 0;
				a[i * 2][j * 2 + 1][1] = k;
				k++;
				h--;
				a[i * 2 + 1][j * 2][0] = 0;
				a[i * 2 + 1][j * 2][1] = k;
				a[i * 2 + 1][j * 2 + 1][0] = 0;
				a[i * 2 + 1][j * 2 + 1][1] = k;
				k++;
				h--;
			}
			else // if (v > 1)
			{
				a[i * 2][j * 2][0] = 1;
				a[i * 2][j * 2][1] = k;
				a[i * 2 + 1][j * 2][0] = 1;
				a[i * 2 + 1][j * 2][1] = k;
				k++;
				v--;
				a[i * 2][j * 2 + 1][0] = 1;
				a[i * 2][j * 2 + 1][1] = k;
				a[i * 2 + 1][j * 2 + 1][0] = 1;
				a[i * 2 + 1][j * 2 + 1][1] = k;
				k++;
				v--;
			}
		}
	}

	forn(i, nn)
	{
		forn(j, mm)
		{
			int x = i;
			int y = j;
			if (x > 0 && a[x-1][y][1] == a[x][y][1]) x--;
			if (y > 0 && a[x][y-1][1] == a[x][y][1]) y--;
			putchar('a' + ((x % 4) * 4 + (y % 4)));
		}
		puts("");
	}

	return 0;
}