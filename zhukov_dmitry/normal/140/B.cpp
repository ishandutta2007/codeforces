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
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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

int n;
int a[1024][1024];
int b[1024];
int c[1024][2];
int r[1024];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d", &n);
	forn(i, n)
	{
		forn(j, n)
		{
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	forn(i, n)
	{
		scanf("%d", &b[i]);
		b[i]--;
		r[b[i]] = i;
	}
	int m1 = -1, m2 = -1;
	forn(i, n)
	{
		if (m1 == -1) m1 = i;
		else if (m2 == -1)
		{
			m2 = i;
			if (r[m1] > r[m2]) swap(m1, m2);
		}
		else
		{
			if (r[m1] > r[i])
			{
				m2 = m1;
				m1 = i;
			}
			else if (r[m2] > r[i])
			{
				m2 = i;
			}
		}
		c[i][0] = m1;
		c[i][1] = m2;
	}
	forn(i, n)
	{
		int ans = -1;
		bool bb = false;
		forn(k, n)
		{
			forn(j, n)
			{
				if ((c[j][0] == a[i][k] && c[j][0] != i) || (c[j][1] == a[i][k] && c[j][0] == i))
				{
					ans = j;
					bb = true;
					break;
				}
			}
			if (bb) break;
		}
		printf("%d%c", ans + 1, " \n"[i == n-1]);
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}