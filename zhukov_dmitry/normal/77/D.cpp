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
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const int MOD = 1000000007;

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int n, m;
char s[1024][1024];
bool h[256][256];
bool v[256][256];
bool c[256];
int dc[256][256];
int d[256];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(h);
	clr(v);
	scanf("%d%d", &n, &m);
	forn(i, n * 4 + 1)
	{
		scanf("%s", s[i]);
	}
	forn(i, n)
	{
		forn(j, m)
		{
			int cnt = 0;
			forn(i1, 3)
			{
				forn(j1, 3)
				{
					cnt += s[i * 4 + i1 + 1][j * 4 + j1 + 1] == 'O';
				}
			}
			if (cnt == 0 || cnt == 1 || cnt == 4 || cnt == 5) h[i][j] = v[i][j] = true;
			else if (cnt == 2 || cnt == 3)
			{
				if (s[i * 4 + 1][j * 4 + 1] == 'O') h[i][j] = true;
				else v[i][j] = true;
			}
			else // if (cnt == 6)
			{
				if (s[i * 4 + 2][j * 4 + 1] == 'O') v[i][j] = true;
				else h[i][j] = true;
			}
//			cerr << h[i][j];
		}
//		cerr << endl;
	}
	forn(j, m)
	{
		c[j] = (n % 2 == 0);
		forn(i, n)
		{
			c[j] = c[j] && v[i][j];
		}
//		cerr << c[j] << endl;
	}
	
	clr(dc);
	clr(d);
	forn(j, m - 1)
	{
		dc[j][0] = 1;
		forn(i, n)
		{
			if (h[i][j] && h[i][j+1]) add(dc[j][i+1], dc[j][i]);
			if (i < n-1 && v[i][j] && v[i][j+1] && v[i+1][j] && v[i+1][j+1]) add(dc[j][i+2], dc[j][i]);
//			cerr << dc[j][i] << " ";
		}
		if (c[j] && c[j+1]) add(dc[j][n], MOD-1);
//		cerr << dc[j][n] << endl;
	}
//	cerr << endl;
	d[0] = 1;
	forn(j, m)
	{
		if (c[j]) add(d[j+1], d[j]);
		if (j < m-1) add(d[j+2], (i64)d[j] * dc[j][n] % MOD);
	}
	
	cout << d[m] << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}