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

const int MOD = 1000000007;

struct tp{int x, y;};

int n;
tp a[256];
int d[256][256];
bool g[256][256];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

i64 vp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * (i64)p2.y - p1.y * (i64)p2.x;
}

i64 sp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * (i64)p2.x + p1.y * (i64)p2.y;
}

bool segseg(tp p1, tp p2, tp p3, tp p4)
{
	if (max(min(p1.x, p2.x), min(p3.x, p4.x)) > min(max(p1.x, p2.x), max(p3.x, p4.x))) return false;
	if (max(min(p1.y, p2.y), min(p3.y, p4.y)) > min(max(p1.y, p2.y), max(p3.y, p4.y))) return false;
	i64 d1 = vp(p1, p2, p3);
	i64 d2 = vp(p1, p2, p4);
	if ((d1 < 0 && d2 < 0) || (d1 > 0 && d2 > 0)) return false;
	d1 = vp(p3, p4, p1);
	d2 = vp(p3, p4, p2);
	if ((d1 < 0 && d2 < 0) || (d1 > 0 && d2 > 0)) return false;
	return true;
}

bool inside(tp *a, int n, tp p)
{
	int cnt = 0;

	forn(i, n)
	{
		if (a[i].y <= p.y && a[i + 1].y > p.y)
		{
			if (vp(a[i], a[i + 1], p) > 0) cnt++;
		}
		else if (a[i].y > p.y && a[i + 1].y <= p.y)
		{
			if (vp(a[i], a[i + 1], p) < 0) cnt++;
		}
	}

	return cnt % 2 == 1;
}


int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].x *= 2;
		a[i].y *= 2;
	}
	a[n] = a[0];
	i64 s = 0;
	tp p0 = { x : 0, y : 0 };
	forn(i, n)
	{
		s += vp(p0, a[i], a[i + 1]);
	}
	if (s < 0)
	{
		reverse(a, a + n);
		a[n] = a[0];
	}
	int ans = 0;

	clr(g);
//	cerr << a[2].x << " " << a[2].y << endl;
//	cerr << a[4].x << " " << a[4].y << endl;
//	cerr << a[3].x << " " << a[3].y << endl;
	forn(i, n)
	{
		For(j, i + 2, n)
		{
			if (j - i >= n - 1) continue;
			g[i][j] = true;
			forn(l, n)
			{
				if (l != i && l != j)
				{
					if (segseg(a[i], a[j], a[l], a[l]))
					{
						g[i][j] = false;
						break;
					}
				}
				tp pp = { x : (a[i].x + a[j].x) / 2, y : (a[i].y + a[j].y) / 2 };
				if (!inside(a, n, pp))
				{
					g[i][j] = false;
					break;
				}
				if (l == i || (l + 1) % n == i || l == j || (l + 1) % n == j % n) continue;
				if (segseg(a[i], a[j], a[l], a[l + 1]))
				{
					g[i][j] = false;
					break;
				}
			}
		}
		g[i][i + 1] = true;
		d[i][i + 1] = 1;
	}
/*	forn(i, n)
	{
		forn(j, n)
		{
			cerr << g[i][j] << " ";
		}
		cerr << endl;
	}
*/
	ford(i, n)
	{
		For(j, i + 1, n - 1)
		{
			int cnt = j - i + 1;
			if (cnt < 2) continue;
			if (cnt == 3) d[i][j] = 1;
			else
			{
//				int ii = i ?: n;
				For(l, i + 1, j - 1)
				{
					if (g[i][l] && g[l][j])
					{
						add(d[i][j], d[i][l] * (i64)d[l][j] % MOD);
					}
				}
			}
//			cerr << i << " " << j << " " << d[i][j] << endl;
		}
	}
	ans = d[0][n - 1];

	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}