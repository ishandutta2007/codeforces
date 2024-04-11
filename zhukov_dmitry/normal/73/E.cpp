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

int n, k;
int a[102400];
int p[202400];

bool b[2024000];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(b);
	For(i, 2, 10000)
	{
		if (b[i]) continue;
		int j = i * i;
		while (j <= 2000000)
		{
			b[j] = true;
			j += i;
		}
	}
	int cnt = 0;
	For(i, 2, 2000000)
	{
		if (!b[i])
		{
			p[cnt++] = i;
		}
	}
//	cerr << cnt << endl;

	scanf("%d%d", &n, &k);
	if (k == 2)
	{
		puts("0");
		return 0;
	}
	int ans = 0;
	forn(i, n)
	{
		int x;
		scanf("%d", &x);
		if (x > 2000000) continue;
		if (x == 1)
		{
			puts("1");
			return 0;
		}
		if (!b[x] && x <= k-1)
		{
			b[x] = true;
			ans++;
		}
	}
	For(i, 2, k-1)
	{
		if (!b[i])
		{
			puts("-1");
			return 0;
		}
	}
	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}