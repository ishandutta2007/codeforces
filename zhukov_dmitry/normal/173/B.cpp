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
char s[1024][1024];
bool a[2024][2024];
int q[102400];
int qb, qe;
int d[102400];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%s", s[i]);
	}
	clr(a);
	forn(i, n)
	{
		forn(j, m)
		{
			if (s[i][j] == '#')
			{
				a[i][j + n] = true;
				a[j + n][i] = true;
			}
		}
	}
	qb = qe = 0;
	memset(d, 0x3f, sizeof(d));
	d[n - 1] = 0;
	q[qe++] = n - 1;
	while (qb != qe)
	{
		int v = q[qb++];
		forn(i, n + m)
		{
			if (a[v][i] && d[i] > d[v] + 1)
			{
				d[i] = d[v] + 1;
				q[qe++] = i;
			}
		}
	}


	if (d[0] > 100000)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", d[0]);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}