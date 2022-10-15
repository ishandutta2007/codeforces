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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
char a[128][128];
char cc;
bool u[256];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(u);
	scanf("%d%d %c", &n, &m, &cc);
	forn(i, n)
	{
		scanf("%s", a[i]);
	}

	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] == cc)
			{
				forn(l, 4)
				{
					int xn = i + dx[l];
					int yn = j + dy[l];
					if (xn < 0 || yn < 0 || xn >= n || yn >= m || a[xn][yn] == '.' || a[xn][yn] == cc) continue;
					u[(int)a[xn][yn]] = true;
				}
			}
		}
	}

	int ans = 0;

	forn(i, 256)
	{
		ans += u[i];
	}

	printf("%d\n", ans);

	return 0;
}