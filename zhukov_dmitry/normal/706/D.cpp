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
char *g_g_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(s) (g_g_ = gets(s))

#ifdef ROOM_311
#	define _lld "%ll""d"
#else
#	define _lld "%I64d"
#endif

#ifdef ROOM_311
time_t et_0;

__attribute__((constructor)) void init_main()
{
	et_0 = clock();
}

__attribute__((destructor)) void fini_main()
{
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
}
#endif

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

struct tnode
{
	int cnt;
	int next[2];
};

const int h = 31;

int n, k = 0;
tnode a[202400 * 32];

int new_node()
{
	a[k].cnt = 0;
	a[k].next[0] = -1;
	a[k].next[1] = -1;
	return k++;
}

void add(int r, int x, int y)
{
	a[r].cnt += y;
	ford(i, h)
	{
		int z = (x >> i) & 1;
		if (a[r].next[z] < 0) a[r].next[z] = new_node();
		r = a[r].next[z];
		a[r].cnt += y;
	}
}

int go(int r, int x, int hh = h)
{
	if (!hh) return 0;
	hh--;
	int z = (x >> hh) & 1;
	ford(i, 2)
	{
		if (a[r].next[z ^ i] >= 0 && a[a[r].next[z ^ i]].cnt) return go(a[r].next[z ^ i], x, hh) | (i << hh);
	}
	fprintf(stderr, "Botwa !!!");
	for(;;);
	return 0;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d", &n);
	int r = new_node();
	add(r, 0, 1);
	forn(i, n)
	{
		char cc;
		int x;
		scanf(" %c%d", &cc, &x);
		if (cc == '?')
		{
			int ans = go(r, x);
			printf("%d\n", ans);
		}
		else add(r, x, cc == '+' ? 1 : -1);
	}
	
	return 0;
}