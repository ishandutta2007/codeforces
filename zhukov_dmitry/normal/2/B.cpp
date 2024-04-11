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

int n;
int a[1024][1024];
int b[1024][1024];
int ans;
string zz;
int d[1024][1024];
bool r[1024][1024];

void solve(int &ans, string &s)
{
	memset(d, 0x3f, sizeof(d));
	d[0][0] = b[0][0];
	For(i, 1, n-1)
	{
		d[0][i] = d[0][i-1] + b[0][i];
		r[0][i] = true;
		d[i][0] = d[i-1][0] + b[i][0];
		r[i][0] = false;
	}
	For(i, 1, n-1)
	{
		For(j, 1, n-1)
		{
			d[i][j] = d[i-1][j] + b[i][j];
			r[i][j] = false;
			if (d[i][j-1] < d[i-1][j])
			{
				d[i][j] = d[i][j-1] + b[i][j];
				r[i][j] = true;
			}
			if (d[i][j] > 1000000001) d[i][j] = 1000000001;
		}
	}
	s.resize(n + n - 2);
	int x = n-1;
	int y = n-1;
	ans = 0;
	ford(i, n + n - 2)
	{
		ans += b[x][y];
		if (r[x][y])
		{
			s[i] = 'R';
			y--;
		}
		else
		{
			s[i] = 'D';
			x--;
		}
	}
	ans += b[x][y];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		forn(j, n)
		{
			scanf("%d", &a[i][j]);
		}
	}
	ans = 1000000000;
	bool b0 = false;
	int x0 = -1, y0 = -1;
	for(int l = 2; l <= 5; l += 3)
	{
		forn(i, n)
		{
			forn(j, n)
			{
				int x = a[i][j];
				if (a[i][j] == 0)
				{
					b0 = true;
					b[i][j] = 1000000000;
					x0 = i;
					y0 = j;
				}
				else
				{
					b[i][j] = 0;
					while (x % l == 0)
					{
						x /= l;
						b[i][j]++;
					}
				}
			}
		}

		int t;
		string s;
		solve(t, s);
		if (t < ans)
		{
			ans = t;
			zz = s;
		}
	}

	if (ans > 0 && b0)
	{
		ans = 1;
		zz.resize(n + n - 2);
		int l = 0;
		forn(i, x0)
		{
			zz[l++] = 'D';
		}
		forn(i, n-1)
		{
			zz[l++] = 'R';
		}
		forn(i, n-1-x0)
		{
			zz[l++] = 'D';
		}
	}

	printf("%d\n%s\n", ans, zz.c_str());

	return 0;
}