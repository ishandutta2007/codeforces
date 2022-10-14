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

const int MOD = 95542721;
const int PER = 48;

inline void add(int &a, int b, int m)
{
	a += b;
	a -= (a >= m) * m;
}

int n, m;
int a[102400];
int t[1 << 18][PER];
int s[1 << 18];
int z = 1 << 17;

void tadd(int v, int l, int r, int ll, int rr)
{
	if (r < ll || rr < l) return;
	if (l <= ll && rr <= r)
	{
		add(s[v], 1, PER);
		return;
	}
	add(s[v * 2], s[v], PER);
	add(s[v * 2 + 1], s[v], PER);
	s[v] = 0;
	tadd(v * 2, l, r, ll, (ll + rr) / 2);
	tadd(v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr);
	int w1 = s[v * 2];
	int w2 = s[v * 2 + 1];
	forn(i, PER)
	{
		t[v][i] = t[v * 2][w1];
		add(t[v][i], t[v * 2 + 1][w2], MOD);
		add(w1, 1, PER);
		add(w2, 1, PER);
	}
}

int tsum(int sh, int v, int l, int r, int ll, int rr)
{
	if (r < ll || rr < l) return 0;
	add(sh, s[v], PER);
	if (l <= ll && rr <= r)
	{
		return t[v][sh];
	}
	int ans = tsum(sh, v * 2, l, r, ll, (ll + rr) / 2);
	add(ans, tsum(sh, v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr), MOD);
	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	clr(t);
	clr(s);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		int x = a[i] % MOD;
		forn(j, PER)
		{
			t[z + i][j] = x;
			x = x * (i64)x % MOD * x % MOD;
		}
	}
	Ford(j, z - 1, 1)
	{
		forn(i, PER)
		{
			t[j][i] = t[j * 2][i] + t[j * 2 + 1][i];
			t[j][i] -= (t[j][i] >= MOD) * MOD;
		}
	}
	scanf("%d", &m);
	forn(i, m)
	{
		int k, l, r;
		scanf("%d%d%d", &k, &l, &r);
		l--;
		r--;
		if (k == 1)
		{
			printf("%d\n", tsum(0, 1, l, r, 0, z - 1));
		}
		else
		{
			tadd(1, l, r, 0, z - 1);
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}