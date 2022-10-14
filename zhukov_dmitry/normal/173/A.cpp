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

int n;
int l[2];
char s[2][2024000];

int win(char c1, char c2)
{
	if (c1 == c2) return -1;
	if (c1 == 'R' && c2 == 'S') return 0;
	if (c1 == 'S' && c2 == 'P') return 0;
	if (c1 == 'P' && c2 == 'R') return 0;
	return 1;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, 2)
	{
		scanf("%s", s[i]);
		l[i] = strlen(s[i]);
	}
	int k = l[0] * l[1];

	forn(i, k)
	{
		forn(j, 2)
		{
			s[j][i + l[j]] = s[j][i];
		}
	}

	int ans0 = 0, ans1 = 0;
	int t = n / k;
	int z[2] = {0};
	forn(i, k)
	{
		int r = win(s[0][i], s[1][i]);
		if (r >= 0)
		{
			z[r]++;
		}
	}
	ans0 += z[0] * t;
	ans1 += z[1] * t;
	clr(z);
	forn(i, n % k)
	{
		int r = win(s[0][i], s[1][i]);
		if (r >= 0)
		{
			z[r]++;
		}
	}
	ans0 += z[0];
	ans1 += z[1];

	printf("%d %d\n", ans1, ans0);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}