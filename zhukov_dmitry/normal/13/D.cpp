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

struct tp{int x,y; bool red;};

int n, m;
tp a[2024];
tp b[2024];

/*inline i64 vp(const tp &p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return (i64)p1.x * p2.y - (i64)p1.y * p2.x;
}
*/
inline i64 vp(const tp &p, const tp &p1, const tp &p2)
{
	return (i64)(p1.x-p.x) * (p2.y-p.y) - (i64)(p1.y-p.y) * (p2.x-p.x);
}

inline i64 vp(const tp &p1, const tp &p2)
{
	return (i64)p1.x * p2.y - (i64)p1.y * p2.x;
}

inline bool cmp(tp p1, tp p2)
{
	if ((p1.y > 0 || (p1.y == 0 && p1.x > 0)) != (p2.y > 0 || (p2.y == 0 && p2.x > 0))) return (p1.y > 0 || (p1.y == 0 && p1.x > 0));
	return vp(p1, p2) > 0;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, n+m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].x = x;
		a[i].y = y;
		a[i].red = i < n;
	}

	int ans = 0;

	forn(i, n)
	{
		int k = 0;
		forn(j, n+m)
		{
			if (j < n && j >= i) continue;
			b[k] = a[j];
			b[k].x -= a[i].x;
			b[k].y -= a[i].y;
			k++;
		}
		sort(b, b+k, cmp);
		forn(j, k+2)
		{
			b[k+j] = b[j];
		}
		int last = 0;
		forn(j, k)
		{
			if (!b[j].red)
			{
				last--;
				continue;
			}
			tp z = b[j];
			bool ff = true;
			int bx = b[j].x;
			int by = b[j].y;
			int x0 = -1, y0 = -1;
			tp *bb = b+j;
			if (last < 0) last = 0;
//			last = 0;
			while (vp(b[j], b[j+last+1]) > 0) last++;
			For(l, 1, last)
			{
				bb++;
//				if (vp(b[j], *bb) <= 0) break;
				bool r = ff || ((i64)(x0) * (bb->y-by) - (i64)(y0) * (bb->x-bx)) > 0;
//				if (b[j+l].red)
				if (!bb->red)
				{
//					if (ff || (vp(b[j], z, b[j+l]) > 0)) z = b[j+l], ff = false, x0 = z.x - bx, y0 = z.y - by;
					if (r) z = *bb, ff = false, x0 = z.x - bx, y0 = z.y - by;
				}
				else
				{
//					ans += ff || ((vp(b[j], z, b[j+l])) > 0);
					ans += r;
				}
			}
			last--;
		}
	}

	printf("%d\n", ans);

	return 0;
}