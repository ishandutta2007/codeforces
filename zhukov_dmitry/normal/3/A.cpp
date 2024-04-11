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

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int d[8][8];
int pa[8][8];
int q[1024][2];
int qb, qe;

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int x1,y1,x2,y2;
	char s[12];
	scanf("%s", s);
	x1 = s[0] - 'a';
	y1 = s[1] - '1';
	scanf("%s", s);
	x2 = s[0] - 'a';
	y2 = s[1] - '1';

	qe = qb = 0;
	memset(d, 0x3f, sizeof(d));
	d[x1][y1] = 0;
	q[qe][0] = x1;
	q[qe][1] = y1;
	qe++;

	while (qb != qe)
	{
		int x = q[qb][0];
		int y = q[qb][1];
		qb++;
		forn(l, 8)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= 8 || yn < 0 || yn >= 8) continue;
			if (d[xn][yn] > d[x][y] + 1)
			{
				d[xn][yn] = d[x][y] + 1;
				pa[xn][yn] = l;
				q[qe][0] = xn;
				q[qe][1] = yn;
				qe++;
			}
		}
	}

	string z[8] = {"R", "RD", "D", "LD", "L", "LU", "U", "RU"};

	int ans[16];
	int kk = 0;

	int x = x2;
	int y = y2;
	printf("%d\n", d[x][y]);
	while (x != x1 || y != y1)
	{
		int xn = x - dx[pa[x][y]];
		int yn = y - dy[pa[x][y]];
		ans[kk++] = pa[x][y];
		x = xn;
		y = yn;
	}

	ford(i, kk)
	{
		printf("%s\n", z[ans[i]].c_str());
	}

	return 0;
}