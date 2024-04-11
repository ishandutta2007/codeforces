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

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int MOD = 1000000007;

int n;

int mypow(int a, int k, int p)
{
	int ans = 1;
	int j = 1;
	while (j <= k) j <<= 1;
	j >>= 1;
	while (j)
	{
		ans = (i64)ans * ans % p;
		if (j & k) ans = (i64)ans * a % p;
		j >>= 1;
	}
	return ans;
}

/*int c(int n, int k)
{
	if (k > n) return 0;
	int ans = 1;
	For(i, n-k+1, n)
	{
		ans = (i64)ans * i % MOD;
	}
	For(i, 1, k)
	{
		ans = (i64)ans * mypow(i, MOD-2, MOD) % MOD;
	}
	return ans;
}

int f(int n, int k)
{
	return c(n+k-1, k);
}
*/
int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t t0 = clock();
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	if (n == 1)
	{
		puts("1");
		return 0;
	}
	i64 ans = 0;
	int cc = 1;
	forn(i, n)
	{
		ans += (i64)cc * (n-i) % MOD;
		cc = (i64)cc * (n+i-1) % MOD * mypow(i+1, MOD-2, MOD) % MOD;
	}
	ans *= 2;
	ans -= n;
	
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;

#ifdef ROOM_311
	time_t t1 = clock();
	fprintf(stderr, "execution time = %ld ms\n", (t1 - t0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}