#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MOD = 1000000009;

int n;
int f[1024000];
int g[1024000];
int h[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	f[0] = 1;
	int ans = 0;
	For(i, 1, n)
	{
		f[i] = (f[i-1] * 2 + 3) % MOD;
	}
	h[0] = 1;
	For(i, 1, n)
	{
		h[i] = (i64)f[i] * h[i-1] % MOD;
	}

	g[0] = 0;
	g[1] = 1;
	For(i, 2, n-1)
	{
		if (i & 1) g[i] = 2 * h[i/2-1] % MOD;
		else g[i] = (h[max(i/2-2, 0)] + h[i/2-1]) % MOD;
	}
	g[n] = h[max(n / 2 - 2, 0)];

	For(i, 1, n)
	{
//		cerr << h[i] << endl;
		ans = (ans + g[i]) % MOD;
	}

	ans = ((i64)ans * ans + 1) % MOD;
	ans *= 2;
	ans %= MOD;
	cout << ans << endl;

	return 0;
}