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

struct tp{int x,y;};

int l;
int a[6][6];
tp p[6];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t t0 = clock();
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d%d%d", &l, &p[4].x, &p[4].y, &p[5].x, &p[5].y);
	p[0].x = 0;
	p[0].y = 0;
	p[1].x = 0;
	p[1].y = l;
	p[2].x = l;
	p[2].y = l;
	p[3].x = l;
	p[3].y = 0;

	const int INF = 0x3f3f3f3f;
	memset(a, 0x3f, sizeof(a));
	int n = 6;
	forn(i, n)
	{
		forn(j, n)
		{
			if ((p[i].x == p[j].x && (!p[i].x || p[i].x == l)) || (p[i].y == p[j].y && (!p[i].y || p[i].y == l)))
			{
				a[i][j] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
			}
		}
	}
	
	forn(k, n)
	{
		forn(i, n)
		{
			forn(j, n)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	
	printf("%d\n", a[4][5]);

#ifdef ROOM_311
	time_t t1 = clock();
	fprintf(stderr, "execution time = %ld ms\n", (t1 - t0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}