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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m;
int a[2024][2024];
bool u[2024][2024];
int u2[2024][2024];
bool u3[2024][2024];
int d[2024][2024];
int q[2024 * 2024][2];
int e[1024000];

void bfs(int x, int y, i64 &sx, i64 &sy, int &s)
{
	int qb = 0, qe = 0;
	s = 1;
	sx = x;
	sy = y;
	u[x][y] = true;
	q[qe][0] = x;
	q[qe][1] = y;
	qe++;
	while (qb != qe)
	{
		x = q[qb][0];
		y = q[qb][1];
		qb++;
		forn(l, 4)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn] || u[xn][yn]) continue;
			u[xn][yn] = true;
			q[qe][0] = xn;
			q[qe][1] = yn;
			sx += xn;
			sy += yn;
			s++;
			qe++;
		}
	}
}

int bfs2(int x, int y, int col)
{
	if (!a[x][y]) for(;;);
	int qb = 0, qe = 0;
	u2[x][y] = col;
	d[x][y] = 0;
	q[qe][0] = x;
	q[qe][1] = y;
	qe++;
	while (qb != qe)
	{
		x = q[qb][0];
		y = q[qb][1];
		qb++;
		forn(l, 4)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn] || u2[xn][yn]) continue;
			d[xn][yn] = d[x][y] + 1;
			u2[xn][yn] = col;
			q[qe][0] = xn;
			q[qe][1] = yn;
			qe++;
		}
	}
	return qe;
}

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
		forn(j, m)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int cnt = 0;
	clr(u);
	clr(u2);
	clr(u3);
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] && !u[i][j])
			{
				i64 xs, ys;
				int s;
				bfs(i, j, xs, ys, s);
				int t = bfs2(xs / s, ys / s, cnt + 1);

				int z = 0;
				forn(k, t)
				{
					int x = q[k][0];
					int y = q[k][1];
					bool bb = false;
					forn(l, 4)
					{
						int xn = x + dx[l];
						int yn = y + dy[l];
						if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn]) continue;
						if (d[xn][yn] > d[x][y]) bb = true;
					}
					if (!u3[x][y] && bb)
					{
						int w = 0;
						For(di, -4, 4)
						{
							For(dj, -4, 4)
							{
								int xn = x + di;
								int yn = y + dj;
								if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn] || u2[xn][yn] != cnt + 1) continue;
								w++;
							}
						}
						if (w < 27)
						{
							z++;
							For(di, -4, 4)
							{
								For(dj, -4, 4)
								{
									int xn = x + di;
									int yn = y + dj;
									if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn] || u3[xn][yn]) continue;
									u3[xn][yn] = true;
								}
							}
						}
					}
				}
				e[cnt] = z;
				
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	sort(e, e + cnt);
	forn(i, cnt)
	{
		if (i) putchar(' ');
		printf("%d", e[i]);
	}
	puts("");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}