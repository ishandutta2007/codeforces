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

ld a, v, l, d, w;

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >> a >> v >> l >> d >> w;
	if (w > v) w = v;
	ld t1 = sqrt(2.0 * d / a);
	ld v1 = t1 * a;
	ld ans;
//	cerr << v1 << " " << w << endl;
	if (v1 <= w)
	{
		ld t2 = sqrt(2.0 * l / a);
		ld v2 = t2 * a;
		if (v2 > v)
		{
			ld tt = v / a;
			ans = tt + (l - a * tt * tt / 2.0) / v;
		}
		else
		{
			ans = t2;
		}
	}
	else
	{
		ld ttt = w / a;
		ld sss = a * ttt * ttt / 2.0;
		l = l - d + sss;
//		cerr << sss << endl;
//		cerr << l << endl;
		ld t2 = sqrt(2.0 * l / a);
		ld v2 = t2 * a;
		if (v2 > v)
		{
			ld tt = v / a;
			ans = tt + (l - a * tt * tt / 2.0) / v;
		}
		else
		{
			ans = t2;
		}
//		cerr << t2 << endl;
//		cerr << sqrt(2.0 * sss / a) << endl;
		ans -= sqrt(2.0 * sss / a);

		ld mi = w;
		ld ma = 1e+8;

		forn(ttt, 220)
		{
			ld q = (mi + ma) * 0.5;

			ld t1 = q / a;
			ld t2 = (q - w) / a;
			ld s1 = a * t1 * t1 / 2.0;
			ld s2 = q * t2 - a * t2 * t2 / 2.0;
			*(s1 + s2 < d ? &mi : &ma) = q;
		}
		ld vvv = mi;
//		cerr << vvv << endl;

		if (vvv > v)
		{
			ld t1 = v / a;
			ld t3 = (v - w) / a;
			ld t2 = (d - a * t1 * t1 * 0.5 - (v * t3 - a * t3 * t3 / 2.0)) / v;
			ans += t1 + t2 + t3;//vvv / a + (vvv - w) / a;
		}
		else
		{
			ans += vvv / a + (vvv - w) / a;
		}
	}

	cout << ans << endl;

	return 0;
}