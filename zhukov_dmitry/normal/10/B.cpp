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

int n, k;
bool a[128][128];
bool b[128][128];
int d[128][128][128];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	scanf("%d%d", &n, &k);
	int xc = k / 2;
	int yc = k / 2;

	For(l, 1, k)
	{
		forn(i, k)
		{
			d[l][i][0] = 0;
			forn(t, l)
			{
				d[l][i][0] += abs(i-xc) + abs(t-yc);
			}
			For(j, 1, k - l)
			{
				d[l][i][j] = d[l][i][j-1] - abs(j-1 - yc) + abs(j+l-1 - yc);
			}
		}
	}

	forn(tt, n)
	{
		int x;
		scanf("%d", &x);
		clr(b);
		int mi = 1000000000;
		int xx = -1;
		int yy = -1;
		forn(i, k)
		{
			int last = -1;
			forn(j, k)
			{
				if (a[i][j]) last = j;
				if (j - last >= x)
				{
					b[i][j - x + 1] = true;
				}
			}
			forn(j, k-x+1)
			{
				if (!b[i][j]) continue;
				if (d[x][i][j] < mi)
				{
					mi = d[x][i][j];
					xx = i;
					yy = j;
				}
			}
		}

		if (xx == -1)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d %d\n", xx + 1, yy + 1, yy+x-1 + 1);
			forn(i, x)
			{
				a[xx][yy+i] = true;
			}
		}
	}

	return 0;
}