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

int n;
char a[10240][1024];
int b[10240];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	n = 0;
	while (gets(a[n])) n++;
	int ma = 0;
	forn(i, n)
	{
		b[i] = strlen(a[i]);
		ma = max(ma, b[i]);
	}

	forn(i, ma+2)
	{
		putchar('*');
	}
	puts("");

	bool ll = false;
	forn(i, n)
	{
		putchar('*');

		int x = (ma - b[i]) / 2;
		int l = x;
		int r = x;
		if (l + r + b[i] != ma) (ll?l++:r++), ll=!ll;
		forn(j, l)
		{
			putchar(' ');
		}
		forn(j, b[i])
		{
			putchar(a[i][j]);
		}
		forn(j, r)
		{
			putchar(' ');
		}

		putchar('*');
		puts("");
	}

	forn(i, ma+2)
	{
		putchar('*');
	}
	puts("");

	return 0;
}