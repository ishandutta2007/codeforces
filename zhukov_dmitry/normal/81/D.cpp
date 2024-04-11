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

int n, k;
int a[10240];
int ans[10240];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &k);
	forn(i, k)
	{
		scanf("%d", &a[i]);
	}

	int prev = -1;
	forn(i, n)
	{
		int ma = 0;
		int mj = -1;
		forn(j, k)
		{
			if (j == prev) continue;
			if (i == n-1 && j == ans[0]) continue;
			if (a[j] > ma)
			{
				ma = a[j];
				mj = j;
			}
		}
		if (mj == -1 && i == n-1)
		{
			forn(j, k)
			{
				if (j == prev) continue;
				if (a[j] > ma)
				{
					ma = a[j];
					mj = j;
				}
			}
		}
		if (mj == -1)
		{
			puts("-1");
			return 0;
		}
		a[mj]--;
		prev = ans[i] = mj;
	}

/*	forn(i, n)
	{
		if (i) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");
*/
	int r = n-1;
	while (r > 0 && ans[r] == ans[(r+1) % n])
	{
		swap(ans[r], ans[r-1]);
		r--;
	}
	forn(i, n)
	{
		if (ans[i] == ans[(i-1+n) % n] || ans[i] == ans[(i+1) % n])
		{
			puts("-1");
			return 0;
		}
	}

	forn(i, n)
	{
		if (i) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}