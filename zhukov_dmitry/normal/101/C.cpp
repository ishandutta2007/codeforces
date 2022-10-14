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

bool check(tp p1, tp p2, tp p3)
{
	i64 k1, k2;
	k1 = (i64)p1.x * p2.x + (i64)p1.y * p2.y;
	k2 = (i64)p2.x * p2.x + (i64)p2.y * p2.y;
	if (k1 % k2)
	{
		return false;
	}
	k1 = (i64)p1.x * p3.x + (i64)p1.y * p3.y;
	k2 = (i64)p3.x * p3.x + (i64)p3.y * p3.y;
	if (k1 % k2)
	{
		return false;
	}
	return true;
}

bool solve(tp p1, tp p2, tp p3)
{
	p2.x -= p1.x;
	p2.y -= p1.y;
	p1.x = p3.y;
	p1.y = -p3.x;
	swap(p1, p2);
	if (!p1.x && !p1.y)
	{
		return true;
	}
	if (!p2.x && !p2.y)
	{
		return false;
	}
	
	return check(p1, p2, p3);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	tp p1, p2, p3, p4, p5, p6;
	scanf("%d%d", &p1.x, &p1.y);
	scanf("%d%d", &p2.x, &p2.y);
	scanf("%d%d", &p3.x, &p3.y);
	p4.x = p1.y;
	p4.y = -p1.x;
	p5.x = p4.y;
	p5.y = -p4.x;
	p6.x = p5.y;
	p6.y = -p5.x;
	puts(solve(p1, p2, p3) || solve(p4, p2, p3) || solve(p5, p2, p3) || solve(p6, p2, p3) ? "YES" : "NO");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}