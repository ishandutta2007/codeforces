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

int n, m;
int a[64][64];
int c[64];
int pa[64];

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() % 2) swap(x, y);
	pa[x] = y;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(437);
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x][y]++;
		a[y][x]++;
	}

	if (n == 1)
	{
		a[0][0] /= 2;
		if (a[0][0] <= 1)
		{
			puts("YES");
			printf("%d\n", 1-a[0][0]);
			forn(i, 1-a[0][0])
			{
				printf("1 1\n");
			}
			return 0;
		}
		else
		{
			puts("NO");
			return 0;
		}
	}

	forn(i, n)
	{
		if (a[i][i])
		{
			puts("NO");
			return 0;
		}
	}

	if (n == 2)
	{
		if (a[0][1] <= 2)
		{
			puts("YES");
			printf("%d\n", 2-a[0][1]);
			forn(i, 2-a[0][1])
			{
				printf("1 2\n");
			}
			return 0;
		}
		else
		{
			puts("NO");
			return 0;
		}
	}

	forn(i, n)
	{
		forn(j, i)
		{
			if (a[i][j] > 1)
			{
				puts("NO");
				return 0;
			}
		}
	}

	clr(c);
	forn(i, n)
	{
		forn(j, n)
		{
			c[i] += a[i][j];
		}
	}


	int zz = 0;
	forn(i, n)
	{
		if (c[i] > 2)
		{
			puts("NO");
			return 0;
		}
		zz += c[i];
	}

	forn(i, n)
	{
		pa[i] = i;
	}
	bool ok = true;
	forn(i, n)
	{
		if (c[i] < 2) ok = false;
	}
	bool bbb = false;

	forn(i, n)
	{
		forn(j, i)
		{
			if (a[i][j])
			{
				if (find(i) != find(j))
				{
					unite(pa[i], pa[j]);
				}
				else
				{
					if (!ok)
					{
						puts("NO");
						return 0;
					}
					else
					{
						bbb = true;
					}
				}
			}
		}
	}

	forn(i, n)
	{
		if (find(i) != find(0)) ok = false;
	}
	if (ok)
	{
		puts("YES\n0");
		return 0;
	}
	if (bbb)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n", n - zz/2);
	
	forn(tt, n - zz/2)
	{
		forn(i, n)
		{
			if (c[i] == 2) continue;
			For(j, i+1, n-1)
			{
				if (c[j] == 2) continue;
				if (find(i) != find(j))
				{
					unite(pa[i], pa[j]);
					a[i][j]++;
					a[j][i]++;
					c[i]++;
					c[j]++;
					printf("%d %d\n", i+1, j+1);
					goto l1;
				}
			}
		}
l1:;
	}
	forn(i, n)
	{
		if (c[i] > 1) continue;
		For(j, i+1, n-1)
		{
			if (c[j] > 1) continue;
			printf("%d %d\n", i+1, j+1);
			break;
		}
	}

	return 0;
}