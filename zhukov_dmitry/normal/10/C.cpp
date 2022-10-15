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

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);

	i64 ans = 0;
	For(i, 1, 9)
	{
		For(j, 1, 9)
		{
			int k = (i * j) % 9;
			if (!k) k = 9;
			ans += ((i64)(n + 9 - i) / 9) * ((i64)(n + 9 - j) / 9) * ((i64)(n + 9 - k) / 9);
		}
	}
//	cout << ans << endl;
	For(a, 1, n)
	{
		int i = a % 9;
		if (!i) i = 9;
		For(j, 1, 9)
		{
			int tt = a * j;
			For(t, 0, 1000000)
			{
				if (tt > n) break;
				ans--;
				tt += a * 9;
			}
//			int k = (i * j) % 9;
//			if (!k) k = 9;
//			ans += (i64)(n + 9 - i) / 9 * (i64)(n + 9 - j) / 9 * (i64)(n + 9 - k) / 9;
		}
	}
	
	cout << ans << endl;

	return 0;
}