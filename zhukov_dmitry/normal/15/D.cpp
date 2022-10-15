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

int x, y, n, m;
int a[1024][1024];
int b[1024][1024];
int c[1024][1024];
i64 s[1024][1024];
i64 e[1024 * 1024];
int p[1024 * 1024][2];
int ind[1024 * 1024];
bool u[1 << 10][1 << 10];
int ans;
i64 ansp[1024000][4];
char anss[20400800];
int q[1024];
int qb, qe;

bool cmp(int p1, int p2)
{
	return e[p1] < e[p2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d%d", &n, &m, &x, &y);
	clr(a);
	forn(i, n)
	{
		forn(j, m)
		{
			scanf("%d", &a[i+1][j+1]);
		}
	}
	For(i, 1, n)
	{
		qb = qe = 0;
		For(j, 1, m)
		{
			while (qb < qe && a[i][q[qe-1]] >= a[i][j]) qe--;
			q[qe++] = j;
			if (qb < qe && q[qb] <= j - y) qb++;
			if (j >= y)
			{
				b[i][j - y + 1] = a[i][q[qb]];
			}
		}
	}
	For(j, 1, m - y + 1)
	{
		qb = qe = 0;
		For(i, 1, n)
		{
			while (qb < qe && b[q[qe-1]][j] >= b[i][j]) qe--;
			q[qe++] = i;
			if (qb < qe && q[qb] <= i - x) qb++;
			if (i >= x)
			{
				c[i - x + 1][j] = b[q[qb]][j];
			}
		}
	}

	clr(s);
	For(i, 1, n)
	{
		For(j, 1, m)
		{
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
		}
	}

	i64 xy = (i64)x * y;
	int k = 0;
	For(i, 1, n - x + 1)
	{
		For(j, 1, m - y + 1)
		{
			p[k][0] = i;
			p[k][1] = j;
			ind[k] = k;
			e[k] = s[i+x-1][j+y-1] - s[i+x-1][j-1] - s[i-1][j+y-1] + s[i-1][j-1] - xy * c[i][j];
			k++;
		}
	}
	clr(u);

	stable_sort(ind, ind+k, cmp);

	forn(l1, k)
	{
		int l = ind[l1];
		int i = p[l][0];
		int j = p[l][1];
		if (!u[i][j] && !u[i][j+y-1] && !u[i+x-1][j] && !u[i+x-1][j+y-1])
		{
			forn(i1, x)
			{
				forn(j1, y)
				{
					u[i+i1][j+j1] = true;
				}
			}
			ansp[ans][0] = i;
			ansp[ans][1] = j;
			ansp[ans][2] = e[l];
			ans++;
		}
	}

	int l = 0;
	printf("%d\n", ans);
	char t[20];
	forn(i, ans)
	{
		int ll = 0;
		int x = ansp[i][0];
		do
		{
			t[ll++] = x % 10 + '0';
			x /= 10;
		}
		while (x);
		ford(j, ll)
		{
			anss[l++] = t[j];
		}
		anss[l++] = ' ';
		ll = 0;
		x = ansp[i][1];
		do
		{
			t[ll++] = x % 10 + '0';
			x /= 10;
		}
		while (x);
		ford(j, ll)
		{
			anss[l++] = t[j];
		}
		anss[l++] = ' ';
		ll = 0;
		i64 y = ansp[i][2];
		do
		{
			t[ll++] = y % 10 + '0';
			y /= 10;
		}
		while (y);
		ford(j, ll)
		{
			anss[l++] = t[j];
		}
		anss[l++] = '\n';
//		printf("%I64d %I64d %I64d\n", ansp[i][0], ansp[i][1], ansp[i][2]);
	}
	anss[l-1] = '\0';
	puts(anss);

	return 0;
}