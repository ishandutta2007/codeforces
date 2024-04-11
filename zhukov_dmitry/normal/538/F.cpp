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

int n, m, xx;
int a[202400];
int xs[202400];
int ans[202400];
int f[202400];
int b[6024000][4];
int ind[6024000];

void fadd(int x, int k)
{
	for (x++; x <= n + 1; x += x & -x)
		f[x] += k;
}

int fsum(int x)
{
	int ans = 0;
	for (x++; x; x -= x & -x)
		ans += f[x];
	return ans;
}

void calc(int k)
{
	For(v, 1, n)
	{
		int l = k * (v - 1) + 2;
		int r = k * v + 1;
		if (l > n) break;
		if (r > n) r = n;
		b[m][0] = l - 1;
		b[m][1] = k;
		b[m][2] = -1;
		b[m][3] = a[v];
		m++;
		b[m][0] = r;
		b[m][1] = k;
		b[m][2] = 1;
		b[m][3] = a[v];
		m++;
	}
//	if (k % 1000 == 0)
//		cerr << k << " " << m << endl;
}

void solve()
{
	forn(i, n)
	{
		b[m][0] = i + 1;
		b[m][1] = 0;
		b[m][2] = 100;
		b[m][3] = a[i + 1];
		m++;
	}
	forn(i, m)
	{
		ind[i] = i;
	}
	sort(ind, ind + m, [&] (const int &l, const int &r) {
		return b[l][3] < b[r][3] || (b[l][3] == b[r][3] && b[l][2] < b[r][2]);
	});
	clr(f);
	forn(i1, m)
	{
		int i = ind[i1];
		if (b[i][2] == 100)
		{
			fadd(b[i][0], 1);
		}
		else
		{
			ans[b[i][1]] += fsum(b[i][0]) * b[i][2];
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	n = 200000;
	scanf("%d", &n);
	xx = 0;
	forn(i, n)
	{
		a[i + 1] = n - i;
		scanf("%d", &a[i + 1]);
		xs[i] = a[i + 1];
	}
	sort(xs, xs + n);
	xx = unique(xs, xs + n) - xs;
	For(i, 1, n)
	{
		a[i] = lower_bound(xs, xs + xx, a[i]) - xs;
	}
	m = 0;
	clr(ans);
	For(i, 1, n - 1)
	{
		calc(i);
	}
	solve();
	For(i, 1, n - 1)
	{
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}

	return 0;
}