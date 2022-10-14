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

int n;
char s[1024000];
int xx;
int next;

int tor[4][4] = {
{1,2,4,8},
{2,2,2,2},
{4,2,4,2},
{8,2,2,8}
};
int tand[4][4] = {
{1,1,1,1},
{1,2,4,8},
{1,4,4,1},
{1,8,1,8}
};
int txor[4][4] = {
{1,2,4,8},
{2,1,8,4},
{4,8,1,2},
{8,4,2,1}
};

void expr(int &x)
{
	if (s[next] == '(')
	{
		next++;
		expr(x);
		int y;
		char ch = s[next++];
		expr(y);
		int z = 0;
		if (ch == '|')
		{
			forn(i, 4)
			{
				if (!(x & (1 << i))) continue;
				forn(j, 4)
				{
					if (!(y & (1 << j))) continue;
					z |= tor[i][j];
				}
			}
		}
		else if (ch == '&')
		{
			forn(i, 4)
			{
				if (!(x & (1 << i))) continue;
				forn(j, 4)
				{
					if (!(y & (1 << j))) continue;
					z |= tand[i][j];
				}
			}
		}
		else if (ch == '^')
		{
			forn(i, 4)
			{
				if (!(x & (1 << i))) continue;
				forn(j, 4)
				{
					if (!(y & (1 << j))) continue;
					z |= txor[i][j];
				}
			}
		}
		next++;
		x = z;
		return;
	}
	else
	{
		if (s[next] == '0')
		{
			x = (1 << 0);
			next++;
			return;
		}
		if (s[next] == '1')
		{
			x = (1 << 1);
			next++;
			return;
		}
		if (s[next] == '?')
		{
			x = xx;
			next++;
			return;
		}
	}
}

int calc(int x)
{
	int res = 0;
	next = 0;
	xx = x;
	expr(res);
	return res;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	scanf("%s", s);
	int r0 = calc(4);
	int r1 = calc(8);
	if (r0 != r1)
	{
		puts("YES");
	}
	else
	{
		int r2 = calc(12);
//		cerr << r0 << " " << r1 << " " << r2 << endl;
		if (r2 != r0 && ((r2 & 4) | (r2 & 8)))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}