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
int d[512][512];
int c[512][512];
int f[512];
int d1[512];
int c2[512][512];

inline void add(int &a, int b)
{
	a += b;
	a -= (a >= MOD) * MOD;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(c);
	clr(d1);
	d1[0] = 1;
	f[0] = 1;
	forn(i, 501)
	{
		f[i + 1] = f[i] * (i64)(i + 1) % MOD;
		c[i][0] = c[i][i] = 1;
		For(j, 1, i - 1)
		{
			c[i][j] = c[i - 1][j - 1];
			add(c[i][j], c[i - 1][j]);
		}
		forn(j, i + 1)
		{
			c2[i][j] = c[i][j] * (i64)f[j] % MOD;
		}
		if (i >= 1) add(d1[i], d1[i - 1]);
		if (i >= 2) add(d1[i], d1[i - 2] * (i64)(i - 1) % MOD);
	}

	scanf("%d", &n);
	k = 0;
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		k += (x == 1);
	}
	int k1 = k;
	int k2 = n - k1;
	clr(d);
	d[0][0] = 1;
	forn(i1, k1 + 1)
	{
		forn(i2, k2 + 1)
		{
			int ma = min(2, k1);
			For(j, 1, i2)
			{
				add(d[i1][i2], d[i1][i2 - j] * (i64)c2[i2 - 1][j - 1] % MOD);
			}
			For(i, 1, ma)
			{
				For(j, 1, i2)
				{
					add(d[i1][i2], d[i1 - i][i2 - j] * (i64)c[i1][i] % MOD * (i64)c[i2 - 1][j - 1] % MOD * f[i + j - 1] % MOD);
				}
			}
		}
	}
/*	forn(i, 10)
	{
		cerr << d1[i] << endl;
	}
	cerr << d[1][1] << endl;*/
	int ans = 0;
	forn(i, k1 + 1)
	{
		add(ans, d[i][k2] * (i64)d1[k1 - i] % MOD * (i64)c[k1][i] % MOD);
	}
	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}