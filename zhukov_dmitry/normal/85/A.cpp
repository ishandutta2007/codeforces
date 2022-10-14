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
int a[4][128];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	if (n == 1)
	{
		puts("a");
		puts("a");
		puts("b");
		puts("b");
		return 0;
	}
	int m = 0;
	if (n % 2 == 1)
	{
		a[2][0] = a[3][0] = m++;
		forn(i, n/2)
		{
			a[0][i*2] = a[0][i*2+1] = m++;
			a[1][i*2] = a[1][i*2+1] = m++;
			a[2][i*2+1] = a[2][i*2+2] = m++;
			a[3][i*2+1] = a[3][i*2+2] = m++;
		}
		a[0][n-1] = a[1][n-1] = m++;
	}
	else
	{
		a[2][0] = a[3][0] = m++;
		forn(i, n/2)
		{
			a[0][i*2] = a[0][i*2+1] = m++;
			a[1][i*2] = a[1][i*2+1] = m++;
			if (i < n/2-1)
			{
				a[2][i*2+1] = a[2][i*2+2] = m++;
				a[3][i*2+1] = a[3][i*2+2] = m++;
			}
		}
		a[2][n-1] = a[3][n-1] = m++;
	}

	forn(i, 4)
	{
		forn(j, n)
		{
			putchar('a' + a[i][j] % 26);
		}
		puts("");
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}