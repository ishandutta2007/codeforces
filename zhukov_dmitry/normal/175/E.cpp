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
const ld EPS = 1e-7;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int s, l;
int a[3];
ld r[3];
int c[2];
int e[64];
ld x[128];
int y[128];
int ind[128];

bool cmp(int p1, int p2)
{
	return x[p1] < x[p2];
}

ld calc()
{
	ld ans = 0.0;
	
	forn(i, s)
	{
		x[i * 2] = i / 2 - r[e[i]];
		y[i * 2] = e[i] + 1;
		x[i * 2 + 1] = i / 2 + r[e[i]];
		y[i * 2 + 1] = -(e[i] + 1);
	}
	int k = s * 2;
	forn(i, k)
	{
		ind[i] = i;
	}
	sort(ind, ind + k, cmp);
	int z[3] = {0, 0, 1};
	forn(i1, k - 1)
	{
		int i = ind[i1];
		ld ll = x[ind[i1 + 1]] - x[i];
		if (y[i] > 0)
		{
			z[y[i] - 1]++;
		}
		else
		{
			z[(-y[i]) - 1]--;
		}
		ans += ll * (z[0] * c[0] + z[1] * c[1]) * z[2];
	}

	return ans;
}

ld solve()
{
	ld ans = 0.0;
	
	int k = 0;
	forn(j, 3)
	{
		forn(i, a[j])
		{
			e[k++] = j;
		}
	}
	forn(i, k)
	{
		swap(e[i], e[rand() % k]);
	}
	ans = calc();
	
	for(;;)
	{
		bool bb = true;
		
		forn(i, s)
		{
			forn(j, i)
			{
				if (e[i] != e[j])
				{
					swap(e[i], e[j]);
					ld tmp = calc();
					if (tmp > ans + EPS)
					{
						ans = tmp;
						bb = false;
					}
					else
					{
						swap(e[i], e[j]);
					}
				}
			}
		}
		
		if (bb) break;
	}
	
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	time_t et_0 = clock();
	
	s = 0;
	forn(i, 3)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	l = (s + 1) / 2;
	forn(i, 3)
	{
		int x;
		scanf("%d", &x);
		r[i] = sqrt(x * x - 1.0);
	}
	forn(i, 2)
	{
		scanf("%d", &c[i]);
	}
	ld ans = 0.0;
//	int cnt = 0;
	forn(ii, 1000000)
	{
//		cnt++;
//		if ((ii & 7) == 0)
//		{
			time_t et_1 = clock();
			if ((et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC > 2200) break;
//		}
		ans = max(ans, solve());
	}
//	cerr << cnt << endl;
	printf("%0.9lf\n", (double)ans);
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}