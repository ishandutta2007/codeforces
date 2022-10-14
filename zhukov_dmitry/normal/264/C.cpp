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
typedef pair < i64, int > PII;

const i64 INF = 0x8080808080808080LL;

#define x first
#define y second

int n, k;
int a[102400];
int c[102400];
i64 d[102400];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &k);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	forn(i, n)
	{
		scanf("%d", &c[i]);
	}
	forn(t, k)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		i64 ans = 0;
		PII m1 = mp(INF, -1);
		PII m2 = mp(INF, -1);
		memset(d, 0x80, sizeof(d));

		forn(i, n)
		{
			i64 z = y * (i64)a[i];
			int cur = c[i];
			if (m1.y != -1 && m1.y != cur)
			{
				z = max(z, m1.x + y * (i64)a[i]);
			}
			else if (m1.y != -1 && m1.y == cur)
			{
				z = max(z, m1.x + x * (i64)a[i]);
			}
			if (m2.y != -1 && m2.y != cur)
			{
				z = max(z, m2.x + y * (i64)a[i]);
			}
			else if (m2.y != -1 && m2.y == cur)
			{
				z = max(z, m2.x + x * (i64)a[i]);
			}
			z = max(z, d[cur] + a[i] * (i64)x);

			if (ans < z) ans = z;

			if (z > m1.x)
			{
				if (m1.y != cur) m2 = m1;
				m1.x = z;
				m1.y = cur;
			}
			else if (z > m2.x)
			{
				if (m1.y != cur)
				{
					m2.x = z;
					m2.y = cur;
				}
			}

			d[cur] = max(d[cur], z);
		}

		cout << ans << endl;
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}