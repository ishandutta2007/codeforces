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
const ld EPS = 1e-8;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

struct tp{i64 x,y;};
struct tl{i64 a,b,c;};

tp p[16][2];

inline i64 dist2(tp p1, tp p2)
{
	return (sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

tl findline(tp p1, tp p2)
{
	tl l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -l.a * p1.x - l.b * p1.y;
	return l;
}

i64 distline(tl l, tp p)
{
	return (l.a * p.x + l.b * p.y + l.c);
}

bool onseg(tp p, tp p1, tp p2)
{
	tl l = findline(p1, p2);
	if (distline(l, p)) return false;
	return fabs(dist(p1, p2) - dist(p, p1) - dist(p, p2)) < EPS;
}

ld vp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.y - p1.y * p2.x;
}

ld sp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.x + p1.y * p2.y;
}

/*ld distseg(tp p, tp p1, tp p2)
{
	if (sp(p1, p2, p) < 0.0) return dist(p, p1);
	if (sp(p2, p1, p) < 0.0) return dist(p, p2);
	return fabs(vp(p, p1, p2)) / dist(p1, p2);
}
*/
int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		forn(i, 3)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			p[i][0].x = x;
			p[i][0].y = y;
			scanf("%d%d", &x, &y);
			p[i][1].x = x;
			p[i][1].y = y;
		}

		int t1 = -1;
		int t2 = -1;
		forn(i, 3)
		{
			forn(j, i)
			{
				forn(i1, 2)
				{
					forn(j1, 2)
					{
						if (dist2(p[i][i1], p[j][j1]) == 0)
						{
							t1 = i;
							t2 = j;
							if (i1 == 1) swap(p[i][0], p[i][1]);
							if (j1 == 1) swap(p[j][0], p[j][1]);
							goto l1;
						}
					}
				}
			}
		}
l1:;
		#define no() {puts("NO"); continue;}
//		cerr << qq << endl;
//		cerr << t1 << " " << t2 << endl;
//		cerr << "!" << endl;
		if (t1 == -1) no();
//		cerr << "!" << endl;
		tp *a[4];
		a[0] = p[t1];
		a[1] = p[t2];
		if (dist2(a[0][1], a[1][1]) == 0) no();
		if (sp(a[0][0], a[0][1], a[1][1]) < 0 || vp(a[0][0], a[0][1], a[1][1]) == 0) no();
		a[2] = p[3 - t1 - t2];
//		cerr << "!" << endl;

		if (!onseg(a[2][0], a[0][0], a[0][1])) swap(a[2][0], a[2][1]);
		if (!onseg(a[2][0], a[0][0], a[0][1])) no();
		if (!onseg(a[2][1], a[1][0], a[1][1])) no();

		i64 d1 = dist2(a[2][0], a[0][0]);
		i64 d2 = dist2(a[2][0], a[0][1]);
		if (d1 > d2) swap(d1, d2);
		if (d1 * 16 < d2) no();
		d1 = dist2(a[2][1], a[1][0]);
		d2 = dist2(a[2][1], a[1][1]);
		if (d1 > d2) swap(d1, d2);
		if (d1 * 16 < d2) no();
		
		puts("YES");
	}

	return 0;
}