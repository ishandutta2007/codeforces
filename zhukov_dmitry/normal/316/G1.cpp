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

#define x first
#define y second

const int p1 = 37;
const int p2 = 43;
const int MOD1 = 1000000007;
const int MOD2 = 1001645671;

int n, m;
char s[10240];
char a[12][10240];
int b[12];
int l[12];
int r[12];
PII h[12][10240];
PII pows[10240];
map < PII, int > y[12];

PII calc_h(int z, int l, int r)
{
	PII ans;
	ans.x = (h[z][r + 1].x - h[z][l].x) * (i64)pows[2013 - r].x % MOD1;
	if (ans.x < 0) ans.x += MOD1;
	ans.y = (h[z][r + 1].y - h[z][l].y) * (i64)pows[2013 - r].y % MOD2;
	if (ans.y < 0) ans.y += MOD2;
	return ans;
}

void precalc()
{
	pows[0] = mp(1, 1);
	For(i, 1, 2200)
	{
		pows[i].x = pows[i - 1].x * (i64)p1 % MOD1;
		pows[i].y = pows[i - 1].y * (i64)p2 % MOD2;
	}
	strcpy(a[m], s);
	forn(i, m + 1)
	{
		b[i] = strlen(a[i]);
		PII z = mp(0, 0);
		h[i][0] = z;
		forn(j, b[i])
		{
			z.x = (z.x + a[i][j] * (i64)pows[j].x) % MOD1;
			z.y = (z.y + a[i][j] * (i64)pows[j].y) % MOD2;
			h[i][j + 1] = z;
		}
	}
}

int calc(int k, int l, int len, PII hh)
{
	return y[k][hh];
/*	int ans = 0;
	forn(i, b[k] - len + 1)
	{
		if (calc_h(k, i, i + len - 1) == hh) ans++;
	}
	return ans;*/
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s", s);
	scanf("%d", &m);
	forn(i, m)
	{
		scanf("%s%d%d", a[i], &l[i], &r[i]);
	}
	precalc();
	int ans = 0;

	For(len, 1, b[m])
	{
		set < PII > w;
		forn(i, m)
		{
			y[i].clear();
		}
		forn(i, m)
		{
			forn(j, b[i] - len + 1)
			{
				y[i][calc_h(i, j, j + len - 1)]++;
			}
		}
		forn(i, b[m] - len + 1)
		{
			bool ok = true;
			PII th = calc_h(m, i, i + len - 1);
//			cerr << "th: " << i << " " << i + len - 1 << " " << th.x << " " << th.y << endl;
			forn(j, m)
			{
				int tmp = calc(j, i, len, th);
//				cerr << len << " " << i << " " << j << " " << tmp << endl;
				if (!(tmp >= l[j] && tmp <= r[j]))
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				w.insert(th);
			}
		}
//		cerr << len << " " << w.sz << endl;
		ans += w.sz;
	}

	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}