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

int n, m;
int a[1024000];
int b[1024000];
int c[1024000];
bool u[1024000];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(u);
	scanf("%d%d", &n, &m);
	clr(b);
	clr(c);
	int sc = 0;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
		{
			sc++;
			c[-a[i] - 1]++;
		}
		else
		{
			b[a[i] - 1]++;
		}
	}
	int cnt = 0;
	forn(i, n)
	{
		if (b[i] + sc - c[i] == m)
		{
			u[i] = true;
			cnt++;
		}
	}
	if (cnt == 1)
	{
		forn(i, n)
		{
			if (a[i] > 0)
			{
				if (u[a[i] - 1])
				{
					puts("Truth");
				}
				else
				{
					puts("Lie");
				}
			}
			else
			{
				if (!u[-a[i] - 1])
				{
					puts("Truth");
				}
				else
				{
					puts("Lie");
				}
			}
		}
	}
	else
	{
		forn(i, n)
		{
			if (a[i] > 0)
			{
				if (u[a[i] - 1])
				{
					puts("Not defined");
				}
				else
				{
					puts("Lie");
				}
			}
			else
			{
				if (!u[-a[i] - 1])
				{
					puts("Truth");
				}
				else
				{
					puts("Not defined");
				}
			}
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}