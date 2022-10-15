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

int n;
tp a[1024];
int d1[32];
int d2[32][32];
tp p0;
int d[1 << 24];
int pa[1 << 24];

int dist2(tp p1, tp p2)
{
	return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &p0.x, &p0.y);
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	forn(i, n)
	{
		d1[i] = dist2(p0, a[i]);
		forn(j, n)
		{
			d2[i][j] = dist2(a[i], a[j]);
		}
	}

	memset(d, 0x3f, sizeof(d));

	d[0] = 0;
	pa[0] = -1;
	int en = (1 << n) - 1;
	forn(mask, en)
	{
		int s = 0;
		forn(i, n)
		{
			if (mask & (1 << i)) continue;
			s = i;
			break;
		}
		int newmask = mask | (1 << s);
		if (d[newmask] > d[mask] + 2 * d1[s])
		{
			d[newmask] = d[mask] + 2 * d1[s];
			pa[newmask] = s;
		}

		For(i, s+1, n-1)
		{
			if (mask & (1 << i)) continue;
			int newmask = mask | (1 << s) | (1 << i);
			if (d[newmask] > d[mask] + d1[s] + d1[i] + d2[s][i])
			{
				d[newmask] = d[mask] + d1[s] + d1[i] + d2[s][i];
				pa[newmask] = 256 + (s * 256 + i);
			}
		}
	}

	printf("%d\n", d[(1 << n)-1]);
	int x = (1 << n) - 1;
	printf("0");
	while (x)
	{
		if (pa[x] > 100)
		{
			int v1 = (pa[x] - 256) / 256;
			int v2 = (pa[x] - 256) % 256;
			printf(" %d %d 0", v1+1, v2 + 1);
			x ^= 1 << v1;
			x ^= 1 << v2;
		}
		else
		{
			int v = pa[x];
			printf(" %d 0", v+1);
			x ^= 1 << v;
		}
	}

	return 0;
}