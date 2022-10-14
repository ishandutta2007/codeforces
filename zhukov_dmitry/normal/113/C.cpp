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

#define MAXP 300000008
#define MAXP2 150000003
int a0[10240];
int a1[10240];
int c[((MAXP2+1) >> 5) + 10];
int b[((MAXP2+1) >> 5) + 10];
int cnt[1 << 16];

inline void gen_primes()
{
	memset(b, 0, sizeof(b));
	int sq = 17322;
	for(int i=3; i<=sq; i+=2)
	{
		if (b[i >> 6] & (1 << (i / 2))) continue;
		int j = i * i / 2;
		while (j <= MAXP2)
		{
			b[j >> 5] |= 1 << j;
			j += i;
		}
	}
	b[0 >> 5] |= 1 << 0;
}

inline bool check(int i)
{
	return (i & 1) && (!(b[i >> 6] & (1 << (i / 2)))) && (c[i >> 6] & (1 << (i / 2)));
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	gen_primes();
	int k0 = 0;
	int k1 = 0;
	For(i, 1, 100000)
	{
		int x = i * i;
		if (x > 300000000) break;
		if (x & 1) a1[k1++] = x / 2;
		else a0[k0++] = x / 2;
	}
	clr(c);
	int kk1 = (int)(k1 / 2.2);
//	cerr << a1[kk1] << endl;
	forn(i, k0)
	{
		int y = a0[i];
		forn(j, kk1)
		{
			int x = (y + a1[j]);
			if (x >= 150000000) break;
			c[x >> 5] |= 1 << x;
		}
	}
	For(j, kk1, k1 - 1)
	{
		forn(i, k0)
		{
			int x = (a0[i] + a1[j]);
			if (x >= 150000000) break;
			c[x >> 5] |= 1 << x;
		}
	}
	forn(i, 1 << 16)
	{
		cnt[i] = __builtin_popcount(i);
	}
	int l, r;
	scanf("%d%d", &l, &r);
	int ans = 0;
	ans += l <= 2 && 2 <= r;
	if (r - l < 1000)
	{
		For(i, l, r)
		{
			ans += check(i);
		}
	}
	else
	{
		while (l % 64 != 0)
		{
			ans += check(l);
			l++;
		}
		while (r % 64 != 63)
		{
			ans += check(r);
			r--;
		}
		int ll = l >> 6;
		int rr = r >> 6;
		For(i, ll, rr)
		{
			int x = (~b[i]) & c[i];
			ans += cnt[x & 65535];
			ans += cnt[((unsigned int)x >> 16)];
		}
	}

	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}