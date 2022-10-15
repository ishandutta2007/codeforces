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

int n;
PII a[10240];
int d[10240];
int pa[10240];
int ind[10240];
int ans[10240];

bool cmp(int p1, int p2)
{
	return a[p1] < a[p2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	int w, h;
	scanf("%d%d", &w, &h);
	forn(i, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		ind[i] = i;
	}
	sort(ind, ind+n, cmp);

	forn(i, n)
	{
		d[i] = a[ind[i]].x > w && a[ind[i]].y > h;
		pa[ind[i]] = -1;
		forn(j, i)
		{
			if (!d[j]) continue;
			if (a[ind[j]].x < a[ind[i]].x && a[ind[j]].y < a[ind[i]].y && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
				pa[ind[i]] = j;
			}
		}
	}

	int ma = 0;
	int x = -1;
	forn(i, n)
	{
		if (d[i] > ma) ma = d[i], x = i;
	}

	printf("%d\n", ma);
	int k = 0;
	while (x != -1)
	{
		ans[k++] = ind[x];
		x = pa[ind[x]];
	}

	ford(i, k)
	{
		if (i != k - 1) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	puts("");

	return 0;
}