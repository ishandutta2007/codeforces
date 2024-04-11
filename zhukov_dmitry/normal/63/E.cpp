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

const int dx[6] = {1, 1, 0, -1, -1, 0};
const int dy[6] = {1, 0, -1, -1, 0, 1};

int a[20];
int w[1 << 19];
int z[20][2];
int g[7][7];

int f(int mask)
{
	int &ans = w[mask];
	if (ans != -1) return ans;
	ans = 0;
	
	int b[7][7];
	clr(b);
	forn(i, 19)
	{
		if (mask & (1 << i)) b[z[i][0]][z[i][1]] = 1;
	}

	forn(i, 19)
	{
		int x = z[i][0];
		int y = z[i][1];
		if (!b[x][y]) continue;
		forn(l, 3)
		{
			int xn = x;
			int yn = y;
			forn(t, 9)
			{
				if (xn < 0 || xn >= 7 || yn < 0 || yn >= 7 || !b[xn][yn]) break;
				int c[7][7];
				memcpy(c, b, sizeof(b));
				forn(j, t+1)
				{
					c[x + dx[l] * j][y + dy[l] * j] = 0;
				}
				int newmask = 0;
				forn(j, 19)
				{
					newmask |= c[z[j][0]][z[j][1]] << j;
				}
				if (!f(newmask))
				{
					ans = 1;
					break;
				}
				xn += dx[l];
				yn += dy[l];
			}
		}
	}
	
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	z[0][0] = 0; z[0][1] = 4;
	z[1][0] = 1; z[1][1] = 5;
	z[2][0] = 2; z[2][1] = 6;
	z[3][0] = 0; z[3][1] = 3;
	z[4][0] = 1; z[4][1] = 4;
	z[5][0] = 2; z[5][1] = 5;
	z[6][0] = 3; z[6][1] = 6;
	z[7][0] = 0; z[7][1] = 2;
	z[8][0] = 1; z[8][1] = 3;
	z[9][0] = 2; z[9][1] = 4;
	z[10][0] = 3; z[10][1] = 5;
	z[11][0] = 4; z[11][1] = 6;
	z[12][0] = 1; z[12][1] = 2;
	z[13][0] = 2; z[13][1] = 3;
	z[14][0] = 3; z[14][1] = 4;
	z[15][0] = 4; z[15][1] = 5;
	z[16][0] = 2; z[16][1] = 2;
	z[17][0] = 3; z[17][1] = 3;
	z[18][0] = 4; z[18][1] = 4;
	memset(g, 0xff, sizeof(g));
	forn(i, 19)
	{
		g[z[i][0]][z[i][1]] = i;
	}

	char cc;
	int t = 0;
	forn(i, 19)
	{
		cin >> cc;
		a[i] = cc == 'O';
		t |= a[i] << i;
	}
	memset(w, 0xff, sizeof(w));
	puts(f(t) ? "Karlsson" : "Lillebror");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}