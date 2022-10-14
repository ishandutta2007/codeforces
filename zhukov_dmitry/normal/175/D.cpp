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

typedef double ld;

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

int hp[2];
int dt[2];
int c[2];
int l[2];
int r[2];
int pp[2];
ld p[2];
ld d[64][302][302];
ld sd[64][302][302];
int next[64];
ld v[64];
ld tmp[64];

inline bool win()
{
	int t0 = 0;
	int t1 = 0;
	int h0 = hp[0];
	int h1 = hp[1];
	while (h0 > 0 && h1 > 0)
	{
		if (!t0)
		{
			if (rand() % 100 >= pp[0])
			{
				h1 -= rand() % c[0] + l[0];
			}
			t0 += dt[0];
		}
		if (!t1)
		{
			if (rand() % 100 >= pp[1])
			{
				h0 -= rand() % c[1] + l[1];
			}
			t1 += dt[1];
		}
		int t = t0;
		if (t1 < t0) t = t1;
		t0 -= t;
		t1 -= t;
	}
	return h1 <= 0;
}

inline ld sum(ld sd[][302], int x1, int y1, int x2, int y2)
{
	x1 += 101;
	y1 += 101;
	x2 += 101;
	y2 += 101;
	return sd[x2][y2] - sd[x2][y1 - 1] - sd[x1 - 1][y2] + sd[x1 - 1][y1 - 1];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	srand(7274562);
	forn(i, 2)
	{
		scanf("%d%d%d%d%d", &hp[i], &dt[i], &l[i], &r[i], &pp[i]);
		p[i] = pp[i] * 0.01;
		c[i] = r[i] - l[i] + 1;
	}
	int g = __gcd(dt[0], dt[1]);
	dt[0] /= g;
	dt[1] /= g;
	if (pp[0] == 100)
	{
		puts("0.0000");
		return 0;
	}
	if (pp[1] == 100)
	{
		puts("1.0000");
		return 0;
	}
	clr(d);
	clr(sd);
/*	ld ans = 0.0;
	
	int m = 3000000;
	forn(i, m)
	{
		ans += win();
	}
	ans /= m;
	
	cerr << ans << endl;
*/	
	For(h0, -100, hp[0])
	{
		For(h1, -100, hp[1])
		{
			For(t, -dt[0] + 1, dt[1] - 1)
			{
				if (h1 <= 0) d[t + 32][h0 + 101][h1 + 101] = 1.0;
				else if (h0 <= 0) d[t + 32][h0 + 101][h1 + 101] = 0.0;
				else
				{
					int t0 = 0;
					int t1 = t0 + t;
					if (t1 < 0)
					{
						t0 -= t1;
						t1 -= t1;
					}
					if (!t0 && !t1)
					{
						int nt0 = t0 + dt[0];
						int nt1 = t1 + dt[1];
						int nt = nt1 - nt0;
						nt += 32;
						d[t + 32][h0 + 101][h1 + 101] += sum(sd[nt], h0 - r[1], h1 - r[0], h0 - l[1], h1 - l[0]) / c[0] / c[1] * (1.0 - p[0]) * (1.0 - p[1]);
						d[t + 32][h0 + 101][h1 + 101] += sum(sd[nt], h0, h1 - r[0], h0, h1 - l[0]) / c[0] * p[1] * (1.0 - p[0]);
						d[t + 32][h0 + 101][h1 + 101] += sum(sd[nt], h0 - r[1], h1, h0 - l[1], h1) / c[1] * (1.0 - p[1]) * p[0];
						next[t + 32] = nt;
						v[t + 32] = p[0] * p[1];
					}
					else if (!t0)
					{
						int nt0 = t0 + dt[0];
						int nt1 = t1;
						int nt = nt1 - nt0;
						nt += 32;
						d[t + 32][h0 + 101][h1 + 101] += sum(sd[nt], h0, h1 - r[0], h0, h1 - l[0]) / c[0] * (1.0 - p[0]);
						next[t + 32] = nt;
						v[t + 32] = p[0];
					}
					else if (!t1)
					{
						int nt0 = t0;
						int nt1 = t1 + dt[1];
						int nt = nt1 - nt0;
						nt += 32;
						d[t + 32][h0 + 101][h1 + 101] += sum(sd[nt], h0 - r[1], h1, h0 - l[1], h1) / c[1] * (1.0 - p[1]);
						next[t + 32] = nt;
						v[t + 32] = p[1];
					}
				}
			}
			if (h1 > 0 && h0 > 0)
			{
				ld pr = 1.0;
				int x = 32;
				do
				{
					pr *= v[x];
					x = next[x];
//					cerr << x << " " << next[x] << " " << v[x] << endl;
				}
				while (x != 32);
				For(t, -dt[0] + 1, dt[1] - 1)
				{
					tmp[t + 32] = d[t + 32][h0 + 101][h1 + 101];
				}
				For(t, -dt[0] + 1, dt[1] - 1)
				{
					ld z = 1.0;
					int x = 32 + t;
					d[t + 32][h0 + 101][h1 + 101] = 0.0;
					do
					{
						d[t + 32][h0 + 101][h1 + 101] += tmp[x] * z;
						z *= v[x];
						x = next[x];
					}
					while (x != 32 + t);
//					cerr << "pr = " << pr << endl;
					d[t + 32][h0 + 101][h1 + 101] /= (1.0 - pr);
				}
			}
			For(t, -dt[0] + 1, dt[1] - 1)
			{
				sd[t + 32][h0 + 101][h1 + 101] = d[t + 32][h0 + 101][h1 + 101] + sd[t + 32][h0 + 100][h1 + 101] + sd[t + 32][h0 + 101][h1 + 100] - sd[t + 32][h0 + 100][h1 + 100];
			}
		}
	}
	
	cout << d[32][hp[0] + 101][hp[1] + 101] << endl;
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}