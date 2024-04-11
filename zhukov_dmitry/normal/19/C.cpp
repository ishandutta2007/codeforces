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

#define x first
#define y second
#define MAXN 400002
const int SHAMANIC = 2;
#define hx 17305601
#define hy 74322301

int n;
int a[MAXN];
PII h[20][MAXN];
int xx[MAXN];
//int st[MAXN];
int b[MAXN][16];
VI c[MAXN];

void calc_h(int *s, int n, PII h[][MAXN])
{
	PII z = mp(1, 1);
	forn(j, SHAMANIC)
	{
		z.x = z.x * hx;
		z.y = z.y * hy;
	}
	
	h[0][0] = mp(0, 0);
	forn(j, SHAMANIC)
	{
		h[0][0].x = h[0][0].x * hx + s[j] * 2;
		h[0][0].y = h[0][0].y * hy + s[j];
	}
	For(j, SHAMANIC, n-1)
	{
		h[0][j+1-SHAMANIC].x = h[0][j-SHAMANIC].x * hx + s[j] * 2 - s[j - SHAMANIC] * 2 * z.x;
		h[0][j+1-SHAMANIC].y = h[0][j-SHAMANIC].y * hy + s[j] - s[j - SHAMANIC] * z.y;
	}
	int r = 1;
	For(i, 1, 16)
	{
		r *= SHAMANIC;
		PII t = z;
		z = mp(1, 1);

		forn(j, SHAMANIC)
		{
			z.x = z.x * t.x;
			z.y = z.y * t.y;
		}
	
		forn(l, r)
		{
			h[i][l] = mp(0, 0);
			forn(j, SHAMANIC)
			{
				h[i][l].x = h[i][l].x * t.x + h[i-1][j * r + l].x;
				h[i][l].y = h[i][l].y * t.y + h[i-1][j * r + l].y;
			}
			int j0 = SHAMANIC * r;
			for(int j = j0; j < n; j += r)
			{
				h[i][l + j - j0 + r].x = h[i][l + j - j0].x * t.x + h[i-1][j + l].x - h[i-1][j + l - j0].x * z.x;
				h[i][l + j - j0 + r].y = h[i][l + j - j0].y * t.y + h[i-1][j + l].y - h[i-1][j + l - j0].y * z.y;
			}
		}
	}
}

bool eq(int p1, int p2)
{
	int l = p2 - p1;
	if (p2 + l > n) return false;
	int r = 16;
	while (l > 1)
	{
		if (l >= (1 << (r+1)))
		{
			if (h[r][p1] == h[r][p2])
			{
				p1 += (1 << (r+1));
				p2 += (1 << (r+1));
				l -= (1 << (r+1));
			}
			else
			{
				return false;
			}
		}
		r--;
	}
	if (l == 1)
	{
		if (a[p1] != a[p2]) return false;
	}
	return true;
}

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
		scanf("%d", &a[i]);
		a[i]++;
		xx[i] = a[i];
	}
	sort(xx, xx+n);
	calc_h(a, n, h);
	clr(b);
	forn(i, n)
	{
		int j = lower_bound(xx, xx+n, a[i]) - xx;
		b[j][++b[j][0]] = i;
	}
//	memset(st, 0xff, sizeof(st));

	forn(i, n)
	{
		if (!i || xx[i] != xx[i-1])
		{
			For(j, 1, b[i][0])
			{
				For(l, 1, j-1)
				{
					int p1 = b[i][l];
					int p2 = b[i][j];
					if (eq(p1, p2))
					{
						c[p2 - p1].pb(p1);
//						cerr << p1 << " " << p2 << endl;
//						st[p2 - p1] = max(st[p2 - p1], p1);
					}
				}
			}
		}
	}

	int ans = 0;
	For(i, 1, n)
	{
		sort(c[i].begin(), c[i].end());
		forn(l, c[i].sz)
		{
			int j = c[i][l];
			if (j >= ans)
			{
				ans = j + i;
			}
		}
	}

	printf("%d\n", n - ans);
	forn(i, n - ans)
	{
		if (i) putchar(' ');
		printf("%d", a[i + ans] - 1);
	}
	puts("");

	return 0;
}