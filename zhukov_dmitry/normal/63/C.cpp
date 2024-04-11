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

int n;
int a[100][4];

int ok(int x)
{
	int q[10] = {0};
	int c[4];
	int d[4];
	forn(j, 4)
	{
		c[j] = x % 10;
		if (q[c[j]]) return false;
		q[c[j]] = true;
		x /= 10;
	}
	forn(i, n)
	{
		x = a[i][0];
		int k1 = 0;
		int k2 = 0;
		bool u[4] = {0};
		forn(j, 4)
		{
			d[j] = x % 10;
			x /= 10;
			if (d[j] == c[j])
			{
				k1++;
				u[j] = true;
			}
		}
		forn(j, 4)
		{
			if (d[j] != c[j])
			{
				forn(k, 4)
				{
					if (!u[k] && c[k] == d[j])
					{
						u[k] = true;
						k2++;
						break;
					}
				}
			}
		}
		if (k1 != a[i][1] || k2 != a[i][2]) return false;
	}
	return true;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		forn(j, 3)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int cnt = 0;
	int ans = -1;
	
	forn(i, 10000)
	{
		if (ok(i))
		{
			cnt++;
			ans = i;
		}
	}
	
	if (cnt == 1)
	{
		printf("%04d\n", ans);
	}
	else if (!cnt)
	{
		puts("Incorrect data");
	}
	else
	{
		puts("Need more data");
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}