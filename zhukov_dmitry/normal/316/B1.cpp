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

int n, k, m;
int a[1024];
bool d[2024];
int c[1024];
int e[1024];
bool u[1024];
int pa[1024];

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);
	pa[x] = y;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(5467247);
	scanf("%d%d", &n, &k);
	k--;
	m = 0;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		pa[i] = i;
	}
	forn(i, n)
	{
		if (a[i] != 0)
		{
			int x = i;
			int y = a[i] - 1;
			if (find(x) != find(y)) unite(pa[x], pa[y]);
		}
	}
	forn(i, n)
	{
		find(i);
		if (pa[i] == i)
		{
			e[i] = m;
			m++;
		}
	}
	clr(c);
	int z = e[pa[k]];
	forn(i, n)
	{
		c[e[pa[i]]]++;
	}
	clr(d);
	d[0] = true;
	forn(i, m)
	{
		if (i == z) continue;
		ford(j, 1001)
		{
			if (d[j]) d[j + c[i]] = true;
		}
	}
	int add = 1;
	int x = k;
	while (a[x]) x = a[x] - 1, add++;
	forn(i, 1001)
	{
		if (d[i])
		{
			printf("%d\n", i + add);
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}