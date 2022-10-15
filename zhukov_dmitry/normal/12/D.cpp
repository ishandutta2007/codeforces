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

char s[8024000];
int n;
int a[502400];
int b[502400];
int c[502400];
int xx[502400];
int t[502400];
int ind[502400];

void hryuhryu(int *a, bool bb)
{
	gets(s);
	char *h = s;
	forn(i, n)
	{
		a[i] = 0;
		while (*h && *h != ' ') a[i] = a[i] * 10 + *h++ - '0';
		h++;
		a[i] *= -1;
		xx[i] = a[i];
	}
	if (bb)
	{
		sort(xx, xx+n);
		forn(i, n)
		{
			a[i] = lower_bound(xx, xx+n, a[i]) - xx;
		}
	}
}

bool cmp(int p1, int p2)
{
	if (c[p1] != c[p2]) return c[p1] < c[p2];
	return a[p1] > a[p2];
}

void tadd(int x, int k)
{
	x++;
	for(int i = x; i <= n; i += i & -i)
	{
		t[i] = min(t[i], k);
	}
}

int tmin(int x)
{
	x++;
	int ans = 2100000000;
	for(int i = x; i; i -= i & -i)
	{
		ans = min(ans, t[i]);
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	gets(s);
	sscanf(s, "%d", &n);
	hryuhryu(a, true);
	hryuhryu(b, false);
	hryuhryu(c, false);

	forn(i, n)
	{
		ind[i] = i;
		t[i] = 2100000000;
	}
	sort(ind, ind+n, cmp);

	int ans = 0;

	forn(i1, n)
	{
		int i = ind[i1];

		int x = a[i];
		int y = b[i];
		ans += tmin(x-1) < y;
		tadd(x, y);
	}

	printf("%d\n", ans);

	return 0;
}