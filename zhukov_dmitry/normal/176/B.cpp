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

const int MOD = 1000000007;

int n, k;
char s1[2024];
char s2[2024];
int d[2][1024];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s%s", s1, s2);
	scanf("%d", &k);
	n = strlen(s1);
	forn(i, n)
	{
		s2[i + n] = s2[i];
	}
	clr(d);
	d[0][0] = 1;
	int sum = 1;
	forn(i, k)
	{
		int i0 = i % 2;
		int i1 = i0 ^ 1;
		clr(d[i1]);
		int ns = 0;
		forn(j, n)
		{
			d[i1][j] = sum - d[i0][j];
			ns += (d[i1][j] += (d[i1][j] < 0) * MOD);
			ns -= (ns >= MOD) * MOD;
		}
		sum = ns;
	}
	int ans = 0;

	forn(i, n)
	{
		if (!strncmp(s1, s2 + i, n))
		{
			ans += d[k % 2][i];
			ans -= (ans >= MOD) * MOD;
		}
	}

	printf("%d\n", ans % MOD);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}