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

int n;
int a[102400];
char b[128][128];

void solve(int aa, int bb, int cc, int dd)
{
	// bb > dd;
	int x = 0, y = 0;
	int dx = 1;
	if (aa % 2 == 1)
	{
		x = bb - 1;
		dx = -1;
	}
	
	forn(i, bb)
	{
		forn(j, aa + cc)
		{
			b[i][j] = '.';
		}
	}
	
	forn(i, n)
	{
		char c = 'a' + i;
		forn(j, a[i])
		{
			b[x][y] = c;
			x += dx;
			if (x < 0)
			{
				x = 0;
				y++;
				dx = 1;
			}
			if ((y < aa && x >= bb) || (y >= aa && x >= dd))
			{
				x -= dx;
				y++;
				dx = -1;
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(b);
	int aa, bb, cc, dd;
	cin >> aa >> bb >> cc >> dd >> n;
	forn(i, n)
	{
		cin >> a[i];
	}
	
	if (bb > dd)
	{
		solve(aa, bb, cc, dd);
	}
	else
	{
		solve(cc, dd, aa, bb);
		forn(i, dd)
		{
			reverse(b[i], b[i] + aa + cc);
		}
	}

	puts("YES");	
	forn(i, max(bb, dd))
	{
		puts(b[i]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}