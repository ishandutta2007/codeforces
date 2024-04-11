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

const int MID = 10001;

int m;
int l1, l2, p;
int a1[20240];
int a2[20240];
int d[2][20240];
unsigned int pa[10020][20240 >> 5];
char ans[40240];

inline int f(int x, int y)
{
	int r = a1[x] + a2[y];
	if (r >= p) r -= p;
	return r;
}

void solve()
{
	d[0][0] = f(0, 0);
	clr(pa);
	forn(j, l2-1)
	{
		d[0][j+1] = d[0][j] + f(0, j+1);
	}
	forn(i, l1 - 1)
	{
		int i1 = i & 1;
		int in = i1 ^ 1;
		memset(d[in], 0, sizeof(d[in]));
		d[in][0] = d[i1][0] + f(i + 1, 0);
		if (i+1 <= MID) pa[i+1][0 >> 5] |= 1 << 0;
		forn(j, l2 - 1)
		{
			int t = f(i+1, j+1);
//			if (d[in][j+1] < d[in][j] + t)
//			{
				d[in][j+1] = d[in][j] + t;
//			}
			if (d[in][j+1] < d[i1][j+1] + t)
			{
				d[in][j+1] = d[i1][j+1] + t;
				if (i+1 <= MID) pa[i+1][(j+1) >> 5] |= (1 << (j+1));
			}
		}
	}
}

void solve2()
{
	d[0][0] = f(0, 0);
	clr(pa);
	forn(j, l2-1)
	{
		d[0][j+1] = d[0][j] + f(0, j+1);
	}
	forn(i, l1 - 1)
	{
		int i1 = i & 1;
		int in = i1 ^ 1;
		memset(d[in], 0, sizeof(d[in]));
		d[in][0] = d[i1][0] + f(i + 1, 0);
		if (i+1 >= MID) pa[i+1-MID][0 >> 5] |= 1 << 0;
		forn(j, l2 - 1)
		{
			int t = f(i+1, j+1);
//			if (d[in][j+1] < d[in][j] + t)
//			{
				d[in][j+1] = d[in][j] + t;
//			}
			if (d[in][j+1] < d[i1][j+1] + t)
			{
				d[in][j+1] = d[i1][j+1] + t;
				if (i+1 >= MID) pa[i+1-MID][(j+1) >> 5] |= (1 << (j+1));
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d%d", &l1, &l2, &p);
	forn(i, l1)
	{
		scanf("%d", &a1[i]);
		if (a1[i] > 20000) for(;;);
		a1[i] %= p;
	}
	forn(i, l2)
	{
		scanf("%d", &a2[i]);
		if (a2[i] > 20000) for(;;);
		a2[i] %= p;
	}
/*	forn(i, l1)
	{
		forn(j, l2)
		{
			cerr << f(i, j) << " ";
		}
		cerr << endl;
	}*/
	clr(d);
	solve2();
	int xx = d[(l1 & 1) ^ 1][l2 - 1];
	printf("%d\n", d[(l1 & 1) ^ 1][l2 - 1]);

	m = 0;
	int x = l1 - 1;
	int y = l2 - 1;
	bool ff = false;
	while (x || y)
	{
		if (x <= MID && !ff)
		{
			solve();
			ff = true;
		}
		int r = x <= MID ? ((pa[x][y >> 5] >> y) & 1) : ((pa[x - MID][y >> 5] >> y) & 1);
		ans[m++] = r["SC"];
		if (r) x--;
		else y--;
		if (x < 0 || y < 0) for(;;);
	}
	reverse(ans, ans+m);

	if (m != l2 + l1 - 2) for(;;);
	int ss = 0;
	x = y = 0;
	forn(i, l1+l2-2)
	{
		ss += f(x, y);
		if (ans[i] == 'C') x++;
		else y++;
	}
	ss += f(x, y);
	if (ss != xx) for(;;);
	ans[m] = '\0';
	puts(ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}