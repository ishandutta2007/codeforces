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

int n, k;
tp a[1024000];

bool operator < (tp p1, tp p2)
{
	if (p1.y != p2.y) return p1.y < p2.y;
	return p1.x < p2.x;
}

bool operator == (tp p1, tp p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

void go(int l, int r)
{
	if (l >= r) return;
	int q = (l + r) / 2;
	go(l, q);
	go(q+1, r);
	int y = a[q].y;
	For(i, l, r)
	{
		a[k].x = a[i].x;
		a[k].y = y;
		k++;
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

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a+n);
	
	k = n;
	go(0, n-1);
	sort(a, a+k);
	k = unique(a, a+k) - a;
	
	printf("%d\n", k);
	forn(i, k)
	{
		printf("%d %d\n", a[i].x, a[i].y);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}