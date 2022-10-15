#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MOD = 51123987;

int n;
char s[1024];
int a[1024];
int d[2][64][64][64][8];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%s", &n, s);
	int m = 0;
	forn(i, n)
	{
		if (!i || s[i] != s[i-1])
		{
			a[m++] = s[i] - 'a';
		}
	}

	int kmi = n / 3;
	int kma = (n + 2) / 3;

	int ans = 0;

	clr(d);
	d[0][0][0][0][0] = 1;
	forn(i, m)
	{
		clr(d[(i+1) & 1]);
		For(x, 0, kma+1)
		{
			For(y, 0, kma+1)
			{
				For(z, 0, kma+1)
				{
					if (x + y + z > n) break;
					forn(l, 8)
					{
						if (!d[i&1][x][y][z][l]) continue;
						add(d[(i+1)&1][x][y][z][l | (1 << a[i])], d[i&1][x][y][z][l]);
						if (l & (1 << a[i])) continue;
						int xn = x;
						int yn = y;
						int zn = z;
						if (a[i] == 0) xn++;
						else if (a[i] == 1) yn++;
						else /*if (a[i] == 2) */zn++;
						add(d[i&1][xn][yn][zn][0], d[i&1][x][y][z][l]);
					}
				}
			}
		}
//		cerr << i << endl;
	}

	For(x, kmi, kma)
	{
		For(y, kmi, kma)
		{
			For(z, kmi, kma)
			{
				forn(l, 8)
				{
					if (x + y + z == n) add(ans, d[m & 1][x][y][z][l]);
				}
			}
		}
	}
	
	printf("%d\n", ans % MOD);

	return 0;
}