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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef double ld;

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

struct tp{ld x,y;};
struct tl{ld a,b,c, last; int ind;};

int n, k;
ld y[320][320];
ld ans[320];
ld x[320 * 320];
tp p[620];
tp np[620];
tl l[620];
tl nl[620];

tl findline(tp p1, tp p2)
{
	tl l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -l.a * p1.x - l.b * p1.y;
	return l;
}

bool findpoint(tl l1, tl l2, tp& p)
{
	ld d = l1.a * l2.b - l1.b * l2.a;
	if (fabs(d) < EPS) return false;
	p.x = (l1.b * l2.c - l1.c * l2.b) / d;
	p.y = (l1.c * l2.a - l1.a * l2.c) / d;
	return true;
}

inline ld gety(int i, int x, ld dx)
{
	return y[i][x] + (y[i][x + 1] - y[i][x]) * dx;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &k);
	forn(i, n)
	{
		forn(j, k + 1)
		{
			int yy;
			scanf("%d", &yy);
			y[i][j] = yy;
		}
		ans[i] = 0.0;
	}

	forn(i, k)
	{
		int m = 2, nm = 0;
		tp p1 = {x:0, y:y[0][i]}, p2 = {x:1, y:y[0][i + 1]};
		p[0] = p1;
		p[1] = p2;
		l[0] = findline(p1, p2);
		l[0].ind = 0;
		l[0].last = gety(0, i, 0.5);
		ans[0] += l[0].last;

		For(j, 1, n - 1)
		{
			tp p1 = {x:0, y:y[j][i]}, p2 = {x:1, y:y[j][i + 1]};
			tl l2 = findline(p1, p2);
			l2.ind = j;
			nm = 0;
//			l2.last = 0.0;
			forn(k, m - 1)
			{
				np[nm] = p[k];
				nl[nm] = l[k];
				nm++;
				tp pn;
				if (findpoint(l[k], l2, pn) && pn.x > p[k].x && pn.x < p[k + 1].x)
//				if (findpoint(l[k], l2, pn))
				{
//					cerr << "add point " << pn.x << " " << pn.y << "    " << l[k].ind << " " << l[k].a << " " << l[k].b << " " << l[k].c << endl;
//					if (pn.x > p[k].x && pn.x < p[k + 1].x)
//					{
						np[nm] = pn;
						nl[nm] = nl[nm - 1];
						nl[nm - 1].last = gety(nl[nm - 1].ind, i, (np[nm - 1].x + np[nm].x) * 0.5);
						nl[nm].last = gety(nl[nm].ind, i, (np[nm].x + p[k + 1].x) * 0.5);
						nm++;
//					}
//					cerr << "!" << endl;
				}
			}
			np[nm++] = p[m - 1];
			m = nm;
			memmove(p, np, sizeof(np));
			memmove(l, nl, sizeof(nl));
//			cerr << i << " " << m << endl;
//			cerr << "ps: ";
//			forn(k, m)
//			{
//				cerr << p[k].x << ":" << p[k].y << "  ";
//			}
//			cerr << endl;
			forn(k, m - 1)
			{
//				cerr << "xx: " << (p[k].x + p[k + 1].x) * 0.5 << " " << l[k].last << endl;
				ld yy = gety(j, i, (p[k].x + p[k + 1].x) * 0.5);
//				ld y2 = gety(l[k].ind, i, (p[k].x + p[k + 1].x) * 0.5);
				if (yy > l[k].last)
				{
//					cerr << p[k].x << " " << p[k + 1].x << " " << (p[k + 1].x - p[k].x) * (yy - l[k].last) << endl;
					ans[j] += (p[k + 1].x - p[k].x) * (yy - l[k].last);
					l[k] = l2;
					l[k].last = yy;
				}
			}
		}
	}

	forn(i, n)
	{
		printf("%0.6lf\n", (double)ans[i]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}