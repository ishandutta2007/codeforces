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

#define clr(x) memset((x), 0, sizeof(x))
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

typedef double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n;
ld p[1024];
ld d[2][220000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	time_t t_0 = clock();

	scanf("%d", &n);
	forn(i, n + 1)
	{
		double x;
		scanf("%lf", &x);
		p[i] = x;
	}
	clr(d);
	ld ans = 0.0;
	For(l, 1, 22000)
	{
		int ll = l & 1;
		int l1 = ll ^ 1;
		int m = (l + 1) / 2 * n;
		if (m > 200000) break;
		For(s, 0, m)
		{
			int ma = min(s, n);
			For(t, 0, ma)
			{
				ld tmp = d[l1][s-t] + p[t];
				if (d[ll][s] < tmp) d[ll][s] = tmp;
			}
			if (l % 2 == 0) ans = max(ans, d[ll][s] / l);
		}
		time_t t_1 = clock();
		int tt = (int)((t_1 - t_0) * 1000.0 / CLOCKS_PER_SEC);
		if (tt >= 1700) break;
	}
	
	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}