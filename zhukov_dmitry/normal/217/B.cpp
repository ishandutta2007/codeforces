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

int n, r;
int k;
char ans[1024000];

void gcd(int a, int b, int &x, int &cnt)
{
	if (!b)
	{
		x = cnt = 0;
		return;
	}
	if (a < b)
	{
		gcd(b, a, x, cnt);
		return;
	}
	gcd(b, a % b, x, cnt);
	if (a % b == 0 && a / b > 1)
	{
		cnt += a / b;
		x += a / b - 2;
	}
	else
	{
		cnt += a / b;
		x += a / b - 1;
	}
}

void gcd2(int a, int b, int z)
{
	if (a == 1 && b == 1)
	{
		ans[k++] = "TB"[!z];
		return;
	}
	if (a < b)
	{
		gcd2(b, a, !z);
		return;
	}
	gcd2(a - b, b, z);
	ans[k++] = "TB"[z];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &r);
	if (r == 1)
	{
		if (n == 1)
		{
			puts("0\nT");
		}
		else
		{
			puts("IMPOSSIBLE");
		}
		return 0;
	}
	if (r == 2)
	{
		if (n == 2)
		{
			puts("0\nTB");
		}
		else
		{
			puts("IMPOSSIBLE");
		}
		return 0;
	}
	int mi = 10000000;
	int mj = -1;
	For(i, 1, r - 1)
	{
		if (__gcd(i, r) == 1)
		{
			int x, cnt = 0;
			gcd(r - i, i, x, cnt);
//			cerr << i << " " << x << " " << cnt << endl;
			if (cnt == n - 1)
			{
				if (x < mi)
				{
					mi = x;
					mj = i;
				}
			}
		}
	}
	if (mi >= 10000000)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	printf("%d\n", mi);
	k = 0;
	gcd2(r - mj, mj, 0);
	ans[k++] = 'B';
	if (ans[0] == 'B')
	{
		forn(i, n)
		{
			ans[i] = ans[i] == 'B' ? 'T' : 'B';
		}
	}
//	cerr << k << endl;
	ans[n] = '\0';
	puts(ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}