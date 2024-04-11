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



int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		y *= 4;
		
		if (!x)
		{
			if (!y)
			{
				puts("1.000000");
			}
			else
			{
				puts("0.500000");
			}
			continue;
		}
		if (!y)
		{
			puts("1.000000");
			continue;
		}
		
		if (x >= y)
		{
			printf("%0.7lf\n", ((x * 2.0 * y) - y * 0.5 * y) * 1.0 / (x * 2.0 * y));
		}
		else
		{
			printf("%0.7lf\n", ((x * 2.0 * y) - (x * 0.5 * x + (y - x) * 1.0 * x)) * 1.0 / (x * 2.0 * y));
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}