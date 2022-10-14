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

const int MOD = 1000000007;

struct tp{int x, y;};

int n;
tp a[10240];
bool u[10240];
bool u2[10240];
bool u3[10240];

bool check(int w, int xmi, int ymi, int yma)
{
	clr(u);

	forn(i, n)
	{
		if (a[i].x <= xmi + w && a[i].y <= ymi + w) u[i] = true;
	}
	int xmi1 = 10000000;
	int xma1 = -10000000;
	int ymi1 = 10000000;
	int yma1 = -10000000;
	forn(i, n)
	{
		if (u[i]) continue;
		xmi1 = min(xmi1, a[i].x);
		xma1 = max(xma1, a[i].x);
		ymi1 = min(ymi1, a[i].y);
		yma1 = max(yma1, a[i].y);
	}
	if (xma1 - xmi1 <= w && yma1 - ymi1 <= w) return true;

	clr(u);

	forn(i, n)
	{
		if (a[i].x <= xmi + w && a[i].y >= yma - w) u[i] = true;
	}
	xmi1 = 10000000;
	xma1 = -10000000;
	ymi1 = 10000000;
	yma1 = -10000000;
	forn(i, n)
	{
		if (u[i]) continue;
		xmi1 = min(xmi1, a[i].x);
		xma1 = max(xma1, a[i].x);
		ymi1 = min(ymi1, a[i].y);
		yma1 = max(yma1, a[i].y);
	}
	if (xma1 - xmi1 <= w && yma1 - ymi1 <= w) return true;

	return false;
}

int mypow(int a, int k, int p)
{
	int ans = 1;
	int j = 1;
	while (j <= k) j <<= 1;
	j >>= 1;
	while (j)
	{
		ans = (i64)ans * ans % p;
		if (j & k) ans = (i64)ans * a % p;
		j >>= 1;
	}
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
	forn(i, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[i].x = x+y;
		a[i].y = x-y;
	}
	int xmi = a[0].x;
	int xma = a[0].x;
	int ymi = a[0].y;
	int yma = a[0].y;
	forn(i, n)
	{
		xmi = min(xmi, a[i].x);
		xma = max(xma, a[i].x);
		ymi = min(ymi, a[i].y);
		yma = max(yma, a[i].y);
	}
	if (xma - xmi > yma - ymi)
	{
		forn(i, n)
		{
			swap(a[i].x, a[i].y);
		}
		swap(xma, yma);
		swap(xmi, ymi);
	}

	int mi = 0;
	int ma = 100000;
	while (mi < ma)
	{
		int q = (mi + ma) / 2;
		if (check(q, xmi, ymi, yma))
		{
			ma = q;
		}
		else
		{
			mi = q + 1;
		}
	}
	int w = mi;
	cout << w << endl;

	int ans = 0;

	if (xma - xmi <= w && yma - ymi <= w)
	{
		ans = mypow(2, n, MOD);
	}
	else
	{
		clr(u);
		clr(u2);
		clr(u3);

		bool b2 = false;
		forn(i, n)
		{
			if (a[i].x <= xmi + w && a[i].y <= ymi + w) u[i] = true;
		}

		int xmi1 = 10000000;
		int xma1 = -10000000;
		int ymi1 = 10000000;
		int yma1 = -10000000;
		forn(i, n)
		{
			if (u[i]) continue;
			xmi1 = min(xmi1, a[i].x);
			xma1 = max(xma1, a[i].x);
			ymi1 = min(ymi1, a[i].y);
			yma1 = max(yma1, a[i].y);
		}
		if (xma1 < xmi + w) xma1 = xmi + w;
		int cnt = 0;
		forn(i, n)
		{
			if (u[i] && a[i].y >= yma1 - w && a[i].x >= xma1 - w) cnt++;
			else if (u[i]) u2[i] = true;
		}
		if (xma1 - xmi1 <= w && yma1 - ymi1 <= w)
		{
			ans = (ans + mypow(2, cnt, MOD)) % MOD;
		}
		else b2 = true;

		clr(u);

		forn(i, n)
		{
			if (a[i].x <= xmi + w && a[i].y >= yma - w) u[i] = true;
		}
		xmi1 = 10000000;
		xma1 = -10000000;
		ymi1 = 10000000;
		yma1 = -10000000;
		forn(i, n)
		{
			if (u[i]) continue;
			xmi1 = min(xmi1, a[i].x);
			xma1 = max(xma1, a[i].x);
			ymi1 = min(ymi1, a[i].y);
			yma1 = max(yma1, a[i].y);
		}
		if (xma1 < xmi + w) xma1 = xmi + w;
		cnt = 0;
		forn(i, n)
		{
			if (u[i] && a[i].y <= ymi1 + w && a[i].x >= xma1 - w) cnt++;
			else if (u[i]) u3[i] = true;
		}
		if (xma1 - xmi1 <= w && yma1 - ymi1 <= w)
		{
			ans = (ans + mypow(2, cnt, MOD)) % MOD;
		}
		else b2 = true;

		forn(i, n)
		{
			if (u2[i] && u3[i]) b2 = true;
		}
		if (b2) ans = (i64)ans * 2 % MOD;
	}

	cout << ans << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}