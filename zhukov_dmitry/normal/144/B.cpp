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

FILE *g_f_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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

struct tp{int x,y;};

int n;
tp p[10240];
int r[10240];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	tp p1, p2;
	scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d%d", &p[i].x, &p[i].y, &r[i]);
	}
	if (p1.x > p2.x) swap(p1.x, p2.x);
	if (p1.y > p2.y) swap(p1.y, p2.y);
	int ans = 0;
	For(i, p1.x, p2.x)
	{
		bool bb;
		tp pp;
		
		bb = true;
		pp.x = i;
		pp.y = p1.y;
		forn(j, n)
		{
			bb = bb && sqr(p[j].x - pp.x) + sqr(p[j].y - pp.y) > r[j] * r[j];
		}
		ans += bb;
		
		bb = true;
		pp.x = i;
		pp.y = p2.y;
		forn(j, n)
		{
			bb = bb && sqr(p[j].x - pp.x) + sqr(p[j].y - pp.y) > r[j] * r[j];
		}
		ans += bb;
	}
	For(i, p1.y + 1, p2.y - 1)
	{
		bool bb;
		tp pp;
		
		bb = true;
		pp.x = p1.x;
		pp.y = i;
		forn(j, n)
		{
			bb = bb && sqr(p[j].x - pp.x) + sqr(p[j].y - pp.y) > r[j] * r[j];
		}
		ans += bb;
		
		bb = true;
		pp.x = p2.x;
		pp.y = i;
		forn(j, n)
		{
			bb = bb && sqr(p[j].x - pp.x) + sqr(p[j].y - pp.y) > r[j] * r[j];
		}
		ans += bb;
	}
	printf("%d\n", ans);
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}