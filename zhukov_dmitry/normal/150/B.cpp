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
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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

int n, m, k;
bool u[10200];
int pa[10240];

int mypow(int a, int k)
{
	if (!k) return 0;
	if (k == 1) return a;
	int ans = mypow(a, k/2);
	ans = ans * (i64)ans % MOD;
	if (k & 1) ans = ans * (i64)a % MOD;
	return ans;
}

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);
	pa[x] = y;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	srand(456245);
	scanf("%d%d%d", &n, &m, &k);
	int ans = 0;
	if (k > n || k == 1)
	{
		ans = mypow(m, n);
	}
	else
	{
		clr(u);
		forn(i, n)
		{
			pa[i] = i;
		}
		forn(i, n - k + 1)
		{
			forn(j, k)
			{
				int x = i + j;
				int y = i + (k - j - 1);
				if (find(x) != find(y)) unite(pa[x], pa[y]);
			}
		}
		int t = 0;
		forn(i, n)
		{
			if (i == pa[i]) t++;
		}
		ans = mypow(m, t);
	}
	
	printf("%d\n", ans);
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}