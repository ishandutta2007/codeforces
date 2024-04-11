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
typedef unsigned int u32;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

char s[256][256];
u32 a[156][6];
u32 b[156][6];
u32 e[156][6];
u32 w[156][6];
char ss[256000];
int n, m, k, mm;

bool check()
{
	forn(i, n)
	{
		forn(j, mm)
		{
			if (a[i][j] != e[i][j]) return false;
		}
	}
	return true;
}

void up()
{
	clr(b);
	For(i, 1, n-2)
	{
		forn(j, mm)
		{
			b[i][j] = ~w[i][j] & (a[i+1][j] | (a[i][j] & w[i-1][j]));
		}
	}
	memcpy(a, b, sizeof(a));
}

void down()
{
	clr(b);
	For(i, 1, n-2)
	{
		forn(j, mm)
		{
			b[i][j] = ~w[i][j] & (a[i-1][j] | (a[i][j] & w[i+1][j]));
		}
	}
	memcpy(a, b, sizeof(a));
}

void left()
{
	clr(b);
	forn(i, n)
	{
		forn(j, mm)
		{
			u32 aa = (a[i][j] >> 1) | ((a[i][j+1] & 1) << 31);
			u32 ww = (w[i][j] << 1) | (j ? ((w[i][j-1] >> 31) & 1) : 0);
			b[i][j] = ~w[i][j] & (aa | (a[i][j] & ww));
		}
	}
	memcpy(a, b, sizeof(a));
}

void right()
{
	clr(b);
	forn(i, n)
	{
		forn(j, mm)
		{
			u32 aa = (a[i][j] << 1) | (j ? ((a[i][j-1] >> 31) & 1) : 0);
			u32 ww = (w[i][j] >> 1) | ((w[i][j+1] & 1) << 31);
			b[i][j] = ~w[i][j] & (aa | (a[i][j] & ww));
		}
	}
	memcpy(a, b, sizeof(a));
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &n, &m, &k);
	clr(a);
	clr(w);
	clr(e);
	forn(i, n)
	{
		scanf("%s", s[i]);
		forn(j, m)
		{
			if (s[i][j] == '#') w[i][j >> 5] |= 1 << j;
			if (s[i][j] == 'E') e[i][j >> 5] |= 1 << j;
		}
	}
	mm = ((m - 1) / 32 + 1) * 32;
	forn(i, n)
	{
		For(j, m, mm-1)
		{
			w[i][j >> 5] |= 1 << j;
		}
	}
	m = mm;
	mm = m / 32;
	forn(i, n)
	{
		forn(j, mm)
		{
			a[i][j] = ~w[i][j];
		}
	}
	scanf("%s", ss);
	if (check())
	{
		puts("0");
		return 0;
	}
	forn(i, k)
	{
		char cc = ss[i];
		if (cc == 'U')
		{
			up();
		}
		else if (cc == 'D')
		{
			down();
		}
		else if (cc == 'L')
		{
			left();
		}
		else if (cc == 'R')
		{
			right();
		}
/*		
		forn(x, n)
		{
			forn(y, m)
			{
				cerr << ((a[x][y >> 5] & (1 << y)) ? 1 : 0);
			}
			cerr << endl;
		}
		cerr << endl;*/
		if (check())
		{
			printf("%d\n", i+1);
			return 0;
		}
	}
	puts("-1");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}