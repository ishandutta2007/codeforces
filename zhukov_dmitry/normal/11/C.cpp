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

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, qq;
char s[102400];
bool a[256][256];
bool u[256][256];
int q[65536][2];

void bfs(int x, int y, int &x1, int &y1, int &x2, int &y2, int &cnt)
{
	int qb, qe;
	qb = qe = 0;
	q[qe][0] = x;
	q[qe][1] = y;
	qe++;
	u[x][y] = true;

	while (qb != qe)
	{
		x = q[qb][0];
		y = q[qb][1];
		cnt++;
		x1 = min(x1, x);
		y1 = min(y1, y);
		x2 = max(x2, x);
		y2 = max(y2, y);
		qb++;
		forn(l, 8)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= n || yn < 0 || yn >= m || !a[xn][yn] || u[xn][yn]) continue;
			u[xn][yn] = true;
			q[qe][0] = xn;
			q[qe][1] = yn;
			qe++;
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	while (qq--)
	{
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			scanf("%s", s);
			forn(j, m)
			{
				a[i][j] = s[j] == '1';
				u[i][j] = false;
			}
		}
		int ans = 0;
		forn(i, n)
		{
			forn(j, m)
			{
				if (!u[i][j] && a[i][j])
				{
					int x1 = 1000, y1 = 1000, x2 = -1000, y2 = -1000, cnt = 0;
					bfs(i, j, x1, y1, x2, y2, cnt);

					if (x2 - x1 != y2 - y1) continue;
					int l = x2 - x1 + 1;
					if (cnt == l * 4 - 4)
					{
						bool ok = true;
						For(x, x1, x2)
						{
							ok = ok && a[x][y1];
							ok = ok && a[x][y2];
						}
						For(y, y1, y2)
						{
							ok = ok && a[x1][y];
							ok = ok && a[x2][y];
						}
						ans += ok;
					}
					if (l % 2 == 1 && cnt == l * 2 - 2)
					{
						bool ok = true;
						int xx = (x1 + x2) / 2;
						int yy = (y1 + y2) / 2;
						int zz = 0;
						For(x, x1, xx)
						{
							ok = ok && a[x][yy - zz];
							zz++;
						}
						zz = 0;
						For(x, x1, xx)
						{
							ok = ok && a[x][yy + zz];
							zz++;
						}
						zz = 0;
						Ford(x, x2, xx)
						{
							ok = ok && a[x][yy - zz];
							zz++;
						}
						zz = 0;
						Ford(x, x2, xx)
						{
							ok = ok && a[x][yy + zz];
							zz++;
						}
						ans += ok;
					}
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}