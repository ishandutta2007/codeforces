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

#define clr(x) memset((x), 0, sizeof(x))
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
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, k;
char s[1024];
int m;
int b[1024];
int a[26][26];
int d[112][112][26];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	scanf("%s%d", s, &k);
	n = strlen(s);
	forn(i, n)
	{
		b[i] = s[i] - 'a';
	}
	scanf("%d", &m);
	forn(i, m)
	{
		char xx, yy;
		int x, y, z;
		scanf(" %c %c%d", &xx, &yy, &z);
		x = xx - 'a';
		y = yy - 'a';
		a[x][y] = z;
	}
	memset(d, 0x80, sizeof(d));
	forn(i, 26)
	{
		d[1][i != b[0]][i] = 0;
	}
	For(i, 1, n - 1)
	{
		forn(j, k+1)
		{
			forn(l, 26)
			{
				if (d[i][j][l] <= -100000000) continue;
				forn(p, 26)
				{
					int jn = j + (b[i] != p);
					if (d[i+1][jn][p] < d[i][j][l] + a[l][p])
					{
						d[i+1][jn][p] = d[i][j][l] + a[l][p];
					}
				}
			}
		}
	}
	int ans = 0x80808080;
	forn(j, k+1)
	{
		forn(l, 26)
		{
			ans = max(ans, d[n][j][l]);
		}
	}
	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}