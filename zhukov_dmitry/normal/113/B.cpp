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
typedef pair < i64, i64 > PLL;

char s[10240];
char s1[10240];
char s2[10240];
bool b[10240];
bool e[10240];

i64 h1[10240];
i64 h2[10240];
PLL h[10240];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	gets(s);
	gets(s1);
	gets(s2);
	clr(b);
	clr(e);
	int n = strlen(s);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	forn(i, n - l1 + 1)
	{
		b[i] = !strncmp(s + i, s1, l1);
	}
	forn(i, n - l2 + 1)
	{
		e[i + l2 - 1] = !strncmp(s + i, s2, l2);
	}
	int ans = 0;
	For(len, 1, n)
	{
		if (len < l1 || len < l2) continue;
		i64 hh1 = 0;
		i64 hh2 = 0;
		i64 p1 = 1;
		i64 p2 = 1;
		forn(i, len)
		{
			hh1 = hh1 * 17239 + s[i];
			hh2 = hh2 * 1723917 + s[i] + 3;
			p1 *= 17239;
			p2 *= 1723917;
		}
		int k = 0;
		For(i, len, n)
		{
			if (b[i - len] && e[i - 1])
			{
				h1[k] = hh1;
				h2[k] = hh2;
				k++;
			}
			hh1 = hh1 * 17239 + s[i] - s[i - len] * p1;
			hh2 = hh2 * 1723917 + s[i] + 3 - (s[i - len] + 3) * p2;
		}
		forn(i, k)
		{
			h[i] = mp(h1[i], h2[i]);
		}
		sort(h, h+k);
		k = unique(h, h+k) - h;
		ans += k;
	}
	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}