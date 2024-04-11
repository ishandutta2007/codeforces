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

int n;
int a[1024];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", a+i);
	}

	if (n < 3)
	{
		puts("-1");
		return 0;
	}

	reverse(a, a+n);

	const int INF = 2100000000;

	int ans = INF;
	For(i, 2, n-1)
	{
		For(j, 1, i-1)
		{
			int t = a[i] - 1;
			int cnt = 0;
			Ford(k, n-1, j)
			{
				cnt += t / a[k];
				t %= a[k];
			}
			int x = a[i] + a[j] - t - 1;
			if (x > ans) continue;
			int y = x;
			ford(k, n)
			{
				cnt -= y / a[k];
				y %= a[k];
			}
			cnt++;
			if (cnt < 0)
			{
				ans = x;
			}
		}
	}

	if (ans == INF) puts("-1");
	else cout << ans << endl;

	return 0;
}