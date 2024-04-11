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

FILE *g_f_;
char *g_str_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(x) (g_str_ = gets(x))
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

int n, m;
i64 a[102400];
int b[64][102400 >> 5];
int c[64][102400 >> 5];
int x[102400];
int y[64];

bool gauss(int a[][102400 >> 5], int n, int m, int *x, int *y)
{
	int nn = (n + 31) / 32;
	int i = 0, j = 0;
	while (i < m && j < n)
	{
		bool ff = false;
		For(k, i, m - 1)
		{
			if (a[k][j >> 5] & (1 << j))
			{
				if (k != i)
				{
					forn(l, nn)
					{
						swap(a[k][l], a[i][l]);
					}
					swap(y[k], y[i]);
				}
				ff = true;
				break;
			}
		}
		if (!ff)
		{
			j++;
			continue;
		}
		For(k, i + 1, m - 1)
		{
			if (a[k][j >> 5] & (1 << j))
			{
				forn(l, nn)
				{
					a[k][l] ^= a[i][l];
				}
				y[k] ^= y[i];
			}
		}
		i++;
		j++;
	}
	For(k, i, m - 1)
	{
		if (y[k] == 1)
		{
			bool ff = false;
			For(l, j, n - 1)
			{
				if (a[k][l >> 5] & (1 << l))
				{
					ff = true;
					break;
				}
			}
			if (!ff) return false;
		}
	}
	forn(i, n)
	{
		x[i] = 1;
	}
	ford(i, m)
	{
		forn(j, n)
		{
			if (a[i][j >> 5] & (1 << j))
			{
				x[j] = y[i];
				For(l, j + 1, n - 1)
				{
					if (a[i][l >> 5] & (1 << l))
					{
						x[j] ^= x[l];
					}
				}
				break;
			}
		}
	}
	return true;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	i64 z = 0;
	forn(i, n)
	{
#ifdef ROOM_311
		scanf("%lld", &a[i]);
#else
		scanf("%I64d", &a[i]);
#endif
		z ^= a[i];
	}
	m = 61;
	forn(i, m)
	{
		y[i] = 1;
	}
	clr(b);
	forn(j, m)
	{
		forn(i, n)
		{
			if (a[i] & (1LL << j)) b[j][i >> 5] |= 1 << i;
		}
	}

	int yy[64];
	i64 ans0 = 0;
	ford(i, m)
	{
		int cnt = 0;
		if (z & (1LL << i))
		{
			ans0 |= 1LL << i;
			continue;
		}
		Ford(j, m - 1, i)
		{
			if (z & (1LL << j)) continue;
			memmove(c[cnt++], b[j], sizeof(b[j]));
		}
		y[cnt - 1] = 1;
		memcpy(yy, y, sizeof(y));
		if (!gauss(c, n, cnt, x, yy))
		{
/*			cnt = 0;
			Ford(j, m - 1, i)
			{
				if (z & (1LL << j)) continue;
				memmove(c[cnt++], b[j], sizeof(b[j]));
			}*/
			y[cnt - 1] = 0;
//			memcpy(yy, y, sizeof(y));
//			if (!gauss(c, n, cnt, x, yy)) for(;;);
		}
		if (y[cnt - 1]) ans0 |= 1LL << i;
	}

	ford(i, m)
	{
		if (!(z & (1LL << i)))
		{
			continue;
		}
		int cnt = 0;
		Ford(j, m - 1, i)
		{
			memmove(c[cnt++], b[j], sizeof(b[j]));
		}
		if (z & (1LL << i))
		{
			y[cnt - 1] = 1;
		}
		else
		{
			if (ans0 & (1LL << i)) y[cnt - 1] = 1;
			else y[cnt - 1] = 0;
		}
		int tmp = cnt;
		ford(j, i)
		{
			if (!(z & (1LL << j)))
			{
				memmove(c[cnt++], b[j], sizeof(b[j]));
				if (ans0 & (1LL << j)) y[cnt - 1] = 1;
				else y[cnt - 1] = 0;
			}
		}

		memcpy(yy, y, sizeof(y));
		if (!gauss(c, n, cnt, x, yy)) y[tmp - 1] = 0;
	}

	{
		int cnt = 0;
		Ford(j, m - 1, 0)
		{
			memmove(c[cnt++], b[j], sizeof(b[j]));
		}
		memcpy(yy, y, sizeof(y));
//		if (!gauss(c, n, cnt, x, yy)) for(;;);
	}

//	if (n == 100000) cout << ans0 << endl;
	forn(i, n)
	{
		printf("%d%c", 1 + x[i], " \n"[i == n - 1]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}