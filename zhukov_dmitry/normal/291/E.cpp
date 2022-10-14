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
#	define _lld "%lld"
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

#define x first
#define y second

PII MOD = mp(1000364213, 1017666707);

int n, k;
int p[19][502400];
PII h[19][502400];
char s[502400];
PII pows[502400];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	int gh = 0;
	scanf("%d", &n);
	gh += n;
	k = n;
	For(i, 1, n - 1)
	{
		int x;
		scanf("%d%s", &x, s);
		x--;
		gh = (gh * 311 + x);
		int l = strlen(s);
		forn(j, l)
		{
			gh = (gh * 2013 % 1000000009) + s[j];
		}
		int v = i;
		Ford(j, l - 1, 1)
		{
			p[0][v] = k;
			h[0][v] = mp(s[j], s[j]);
			v = k;
			k++;
		}
		p[0][v] = x;
		h[0][v] = mp(s[0], s[0]);
	}
	p[0][0] = -1;
	gh &= 0x3fffffff;
	MOD.y += gh;
	while (MOD.y < 1000000000) MOD.y += 1000000000;
	if (!(MOD.y & 1)) MOD.y++;
	pows[0] = mp(1, 1);
	For(i, 1, k + 1)
	{
		pows[i].x = pows[i - 1].x * 311LL % MOD.x;
		pows[i].y = pows[i - 1].y * 239LL % MOD.y;
	}
	forn(i, 18)
	{
		forn(j, k)
		{
			p[i + 1][j] = p[i][j] >= 0 ? p[i][p[i][j]] : -1;
			if (p[i + 1][j] >= 0)
			{
				h[i + 1][j].x = (h[i][j].x + h[i][p[i][j]].x * (i64)pows[1 << i].x) % MOD.x;
				h[i + 1][j].y = (h[i][j].y + h[i][p[i][j]].y * (i64)pows[1 << i].y) % MOD.y;
			}
		}
	}
	scanf("%s", s);
	int l = strlen(s);
	PII h0 = mp(0, 0);
	forn(i, l)
	{
		h0.x = (h0.x * (i64)pows[1].x + s[i]) % MOD.x;
		h0.y = (h0.y * (i64)pows[1].y + s[i]) % MOD.y;
	}
	int ans = 0;

	forn(i, k)
	{
		PII hh = mp(0, 0);
		int v = i;
		int x = l;
		int z = 0;

		ford(j, 19)
		{
			if ((1 << j) <= x)
			{
				if (p[j][v] < 0)
				{
					hh = mp(0, 0);
					break;
				}
				x -= 1 << j;
				hh.x = (hh.x + h[j][v].x * (i64)pows[z].x) % MOD.x;
				hh.y = (hh.y + h[j][v].y * (i64)pows[z].y) % MOD.y;
				z += 1 << j;
				v = p[j][v];
			}
		}

		if (hh == h0)
		{
			ans++;
		}
	}

	printf("%d\n", ans);
	
	return 0;
}