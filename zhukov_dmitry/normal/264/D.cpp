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

const char *w = "RGB";

int n, m;
i64 ans;
char s[1024000];
int a[1024000];
int b[1024000];
int l[1024000];
int r[1024000];
i64 c[3][3][1024000];
i64 c0[3][1024000];

#ifdef ROOM_311
bool d[1024][1024];

int dull()
{
	clr(d);
	d[0][0] = true;
	forn(i, n)
	{
		forn(j, m)
		{
			if (d[i][j])
			{
				if (a[i] == b[j])
				{
					d[i + 1][j + 1] = true;
				}
				else
				{
					d[i + 1][j] = d[i][j + 1] = true;
				}
			}
		}
	}
	int ans = 0;
	forn(i, n)
	{
		forn(j, m)
		{
			ans += d[i][j];
		}
	}
	return ans;
}
#endif

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s", s);
	n = strlen(s);
	forn(i, n)
	{
		a[i] = strchr(w, s[i]) - w;
	}
	scanf("%s", s);
	m = strlen(s);
	forn(i, m)
	{
		b[i] = strchr(w, s[i]) - w;
	}

#ifdef ROOM_311
	cerr << dull() << endl;
#endif

	ans = 0;

	clr(c);
	forn(col, 3)
	{
		forn(prev_col, 3)
		{
			forn(j, m)
			{
				c[prev_col][col][j] = (!j || prev_col != b[j - 1]) && (!j || col == b[j - 1]) && (prev_col == b[j]);
			}
			i64 sum = 0;
			forn(j, m + 1)
			{
				i64 tmp = c[prev_col][col][j];
				c[prev_col][col][j] = sum;
				sum += tmp;
			}
		}
		forn(j, m)
		{
			c0[col][j] = (!j || col == b[j - 1]);
		}
		i64 sum = 0;
		forn(j, m + 1)
		{
			i64 tmp = c0[col][j];
			c0[col][j] = sum;
			sum += tmp;
		}
	}

	int z = 0;
	forn(i, n)
	{
		l[i] = z;
		if (a[i] == b[z]) z++;
		if (z >= m)
		{
			n = i + 1;
			break;
		}
	}
	z = 0;
	forn(j, m)
	{
		if (a[z] == b[j])
		{
			r[z] = j;
			z++;
			if (z >= n)
			{
				m = j + 1;
				break;
			}
		}
	}
	while (z < n)
	{
		r[z++] = m - 1;
	}
	forn(i, n)
	{
		ans += r[i] - l[i] + 1;
	}
	For(i, 1, n - 1)
	{
		ans -= c[a[i - 1]][a[i]][r[i] + 1] - c[a[i - 1]][a[i]][l[i]];
	}
	ans -= c0[a[0]][r[0] + 1] - c0[a[0]][l[0]];
	ans++;

	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}