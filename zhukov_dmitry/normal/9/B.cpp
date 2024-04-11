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

struct tp{int x,y;};

int n, vb, vs;
int a[102400];
tp p;

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &n, &vb, &vs);
	forn(i, n)
	{
		scanf("%d", a+i);
	}
	scanf("%d%d", &p.x, &p.y);

	ld ans = 1e+18;
	ld d2 = 1e+18;
	int mj = -1;

	For(i, 1, n-1)
	{
		ld dd = sqrt(sqr(0.0+p.x-a[i]) + sqr(0.0+p.y));
		ld t = dd / vs + a[i] * 1.0 / vb;
		if (t < ans - EPS || (t <= ans + EPS && dd < d2))
		{
			ans = t;
			d2 = dd;
			mj = i;
		}
	}

	cout << mj+1 << endl;

	return 0;
}