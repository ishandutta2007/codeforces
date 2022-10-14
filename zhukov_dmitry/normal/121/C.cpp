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

int m, k, n;
i64 f[20];
i64 a[200000];
bool u[20];

void go(int s, int n, int k, int *y)
{
	clr(u);
	k--;
	forn(i, n)
	{
		int t = k / f[n-i-1];
		k %= f[n-i-1];
		forn(j, n)
		{
			if (!u[j])
			{
				if (!t)
				{
					u[j] = true;
					y[i] = s + j + 1;
					break;
				}
				t--;
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	m = 0;
	For(i, 1, 10)
	{
		forn(j, 1 << i)
		{
			i64 t = 0;
			forn(k, i)
			{
				t = t * 10 + ((j & (1 << k)) ? 4 : 7);
			}
			a[m++] = t;
		}
	}
	sort(a, a+m);
	
	f[0] = 1;
	For(i, 1, 17)
	{
		i[f] = f[i-1] * i;
	}
	scanf("%d%d", &n, &k);
	int ans = 0;
	int s = 0;
	if (n > 13)
	{
		s = n - 13;
		n = 13;
		ans += upper_bound(a, a+m, s) - a;
	}
	else
	{
		if (k > f[n])
		{
			puts("-1");
			return 0;
		}
	}
	int y[20];
	go(s, n, k, y);
//	cerr << ans << endl;
//	cerr << s << endl;
	forn(i, n)
	{
//		cerr << y[i] << " " << s + i + 1 << endl;
		ans += (binary_search(a, a+m, y[i]) && binary_search(a, a+m, s + i + 1));
	}
	
	cout << ans << endl;
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}