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

int n, m;
int a[1024];
int b[1024];
int c[1024][1024];
int e[1024 * 1024][4];
int ind[1024 * 1024];
int t[1024][1024];
int pa[1024][1024][2];
int tpa[1024][1024][2];
int r[1024];

bool cmp(int p1, int p2)
{
	if (e[p1][2] != e[p2][2]) return e[p1][2] < e[p2][2];
	if (e[p1][0] != e[p2][0]) return e[p1][0] > e[p2][0];
	if (e[p1][1] != e[p2][1]) return e[p1][1] > e[p2][1];
	return false;
}

void tadd(int x, int y, int k, int xx, int yy)
{
	x++;
	y++;
	for(int i = x; i <= n; i += i & -i)
	{
		for(int j = y; j <= m; j += j & -j)
		{
			if (t[i][j] < k)
			{
				t[i][j] = k;
				tpa[i][j][0] = xx;
				tpa[i][j][1] = yy;
			}
		}
	}
}

void tsum(int x, int y, int &ans, int &pax, int &pay)
{
	x++;
	y++;
	ans = 0;
	pax = -1, pay = -1;
	for(int i = x; i; i -= i & -i)
	{
		for(int j = y; j; j -= j & -j)
		{
			if (t[i][j] > ans)
			{
				ans = t[i][j];
				pax = tpa[i][j][0];
				pay = tpa[i][j][1];
			}
		}
	}
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
	}
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%d", &b[i]);
	}

	int k = 0;
	memset(c, 0xff, sizeof(c));
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i] == b[j])
			{
				c[i][j] = a[i];
				e[k][0] = i;
				e[k][1] = j;
				e[k][2] = a[i];
				k++;
			}
		}
	}
	forn(i, k)
	{
		ind[i] = i;
	}

	sort(ind, ind+k, cmp);
	clr(t);
	memset(pa, 0xff, sizeof(pa));

	int ans = 0, xma = -1, yma = -1;
	forn(i1, k)
	{
		int i = ind[i1];
		int x = e[i][0];
		int y = e[i][1];
		int pax, pay, t;
		tsum(x-1, y-1, t, pax, pay);
		pa[x][y][0] = pax;
		pa[x][y][1] = pay;
		tadd(x, y, t + 1, x, y);
		if (t+1 > ans)
		{
			ans = t+1;
			xma = x;
			yma = y;
		}
	}

	int x = xma, y = yma;
	printf("%d\n", ans);

	forn(i, ans)
	{
		r[i] = a[x];
		int xn = pa[x][y][0], yn = pa[x][y][1];
		x = xn;
		y = yn;
	}

	reverse(r, r+ans);
	forn(i, ans)
	{
		if (i) putchar(' ');
		printf("%d", r[i]);
	}
	puts("");

	return 0;
}