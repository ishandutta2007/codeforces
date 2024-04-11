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

#ifdef ROOM_311
time_t et_0;

__attribute__((constructor)) void init_main()
{
	et_0 = clock();
}

__attribute__((destructor)) void fini_main()
{
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
}
#endif

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
int a[102400];
char s[102400];
int f[102400];
int rf[102400];

int mypow(int a, int k)
{
	if (!k) return 1;
	int ans = mypow(a, k / 2);
	ans = ans * (i64)ans % MOD;
	if (k & 1) ans = ans * (i64)a % MOD;
	return ans;
}

int cnk(int n, int k)
{
	if (n < k || k < 0) return 0;
	return f[n] * (i64)rf[n - k] % MOD * rf[k] % MOD;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	f[0] = rf[0] = 1;
	For(i, 1, 100000)
	{
		f[i] = f[i - 1] * (i64)i % MOD;
		rf[i] = rf[i - 1] * (i64)mypow(i, MOD - 2) % MOD;
	}

	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int sum = 0;
	forn(i, n)
	{
		a[i] = s[i] - '0';
		sum += a[i];
	}
	int ans = 0;
	int p10 = 1;
	ford(i, n)
	{
		ans = (ans + a[i] * (i64)cnk(i, k) % MOD * p10) % MOD;
		sum -= a[i];
		if (i > 0 && k >= 0) ans = (ans + sum * (i64)cnk(i - 1, k - 1) % MOD * p10) % MOD;
		p10 = p10 * 10LL % MOD;
	}

	printf("%d\n", ans);

	return 0;
}