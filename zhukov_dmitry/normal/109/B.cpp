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

int k;
int a[10240];
int l1, r1, l2, r2, n;

inline i64 add(int x1, int y1, int x2, int y2, int t)
{
	if (t != n) return 0;
	if (x1 < l1) x1 = l1;
	if (y1 > r1) y1 = r1;
	if (x2 < l2) x2 = l2;
	if (y2 > r2) y2 = r2;
	if (x1 > y1 || x2 > y2) return 0;
	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}
	i64 ans = (i64)(y1 - x1 + 1) * (y2 - x2 + 1);
	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	k = 0;
	a[k++] = 0;
	For(l, 1, 9)
	{
		forn(i, 1 << l)
		{
			int x = 0;
			forn(j, l)
			{
				x = x * 10 + ((i & (1 << j)) ? 7 : 4);
			}
			a[k++] = x;
		}
	}
	a[k++] = 1000000001;
	sort(a, a+k);
//	forn(i, k)
//	{
//		cerr << a[i] << " ";
//	}
	scanf("%d%d%d%d%d", &l1, &r1, &l2, &r2, &n);
	
	i64 z = (i64)(r1 - l1 + 1) * (r2 - l2 + 1);
	i64 ans = 0;
	forn(i, k - 1)
	{
		forn(j, i)
		{
			ans += add(a[j], a[j], a[i], a[i], i - j + 1);
			ans += add(a[j] + 1, a[j + 1] - 1, a[i], a[i], i - j);
			ans += add(a[j], a[j], a[i] + 1, a[i + 1] - 1, i - j + 1);
			ans += add(a[j] + 1, a[j + 1] - 1, a[i] + 1, a[i + 1] - 1, i - j);

			ans += add(a[i], a[i], a[j], a[j], i - j + 1);
			ans += add(a[i] + 1, a[i + 1] - 1, a[j], a[j], i - j + 1);
			ans += add(a[i], a[i], a[j] + 1, a[j + 1] - 1, i - j);
			ans += add(a[i] + 1, a[i + 1] - 1, a[j] + 1, a[j + 1] - 1, i - j);
		}
		ans += add(a[i], a[i], a[i], a[i], 1);
		ans += add(a[i], a[i], a[i] + 1, a[i + 1] - 1, 1);
		ans += add(a[i] + 1, a[i + 1] - 1, a[i], a[i], 1);
	}
/*	forn(i, k - 1)
	{
		For(j, i + 1, k - 2)
		{
		}
	}
*/
	printf("%0.10lf\n", ans * 1.0 / z);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}