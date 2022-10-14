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

int n, k;
int a[128];
int c[128];
i64 p[128];
int ind[128];

bool cmp(int p1, int p2)
{
	return c[p1] < c[p2];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	cin >> n;
	forn(i, n)
	{
		cin >> a[i] >> c[i];
	}
	cin >> k;
	p[0] = 1;
	forn(i, k)
	{
		cin >> p[i + 1];
	}
	k++;
	p[k] = 1000000000000000000LL;
	i64 cnt = 0;
	forn(i, n)
	{
		ind[i] = i;
	}
	sort(ind, ind + n, cmp);
	i64 ans = 0;
	int cur = 0;
	
	forn(i1, n)
	{
		int i = ind[i1];
		i64 z = a[i];
		while (z)
		{
			i64 up = min(z, p[cur + 1] - cnt);
			z -= up;
			cnt += up;
			ans += up * c[i] * (cur + 1);
			if (cnt == p[cur + 1]) cur++;
		}
	}
	
	cout << ans << endl;
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}