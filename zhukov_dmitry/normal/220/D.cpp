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

FILE *g_f_;
char *g_str_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(x) (g_str_ = gets(x))
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

int n, m;

int solve(int n, int m)
{
	n++;
	m++;
	int ans = 0;

	int z = n * m;
	z = z * (i64)(z - 1) % MOD * (z - 2) % MOD;
	ans = (ans + z) % MOD;
	int n2 = n / 2, n1 = n - n2;
	int m2 = m / 2, m1 = m - m2;
	z = (n2 * m2 * (i64)n1 % MOD * m1 % MOD * (n1 * m2 + n2 * m1) % MOD) * 6 % MOD;
	ans = (ans - (i64)z) % MOD;
	if (ans < 0) ans += MOD;
	z = (n1 * m2 * (i64)n2 % MOD * m1 % MOD * (n1 * m1 + n2 * m2) % MOD) * 6 % MOD;
	ans = (ans - (i64)z) % MOD;
	if (ans < 0) ans += MOD;

	For(i, 1, n - 1)
	{
		ans = (ans - m * (n - i) * (i64)(i - 1) * 6) % MOD;
	}
	For(i, 1, m - 1)
	{
		ans = (ans - n * (m - i) * (i64)(i - 1) * 6) % MOD;
	}
	For(i, 1, n - 1)
	{
		For(j, 1, m - 1)
		{
			int z = __gcd(i, j);
			ans -= (n - i) * (m - j) * 2 * (i64)(z - 1) * 6 % MOD;
			if (ans < 0) ans += MOD;
		}
	}

	ans %= MOD;
	if (ans < 0) ans += MOD;
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

	scanf("%d%d", &n, &m);
	cout << solve(n, m) << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}