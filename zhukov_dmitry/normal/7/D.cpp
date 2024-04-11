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

int n;
char s[5024000];
char a[5024000];
int p[5024000];
bool b[5024000];
int c[5024000];

void calc_pref(char *a, int n, int *p)
{
	int q = -1;
	p[0] = -1;
	For(i, 1, n-1)
	{
		while (q != -1 && a[i] != a[q+1]) q = p[q];
		if (a[i] == a[q+1]) q++;
		p[i] = q;
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	gets(s);
	n = strlen(s);
	calc_pref(s, n, p);
	forn(i, n)
	{
		a[i] = s[n-i-1];
	}

	int q = -1;
	forn(i, n)
	{
		while (q != -1 && a[i] != s[q+1]) q = p[q];
		if (a[i] == s[q+1]) q++;
	}

	clr(b);
	while (q != -1)
	{
		b[q] = true;
		q = p[q];
	}

	int ans = 0;

	clr(c);
	forn(i, n)
	{
		if (b[i])
		{
			c[i] = c[(i-1)/2] + 1;
			ans += c[i];
		}
	}

	printf("%d\n", ans);

	return 0;
}