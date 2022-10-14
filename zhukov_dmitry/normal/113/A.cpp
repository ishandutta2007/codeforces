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

char s[102400];
int n;
int a[102400];
int b[102400];

bool check(const char *s, int l, const char *t)
{
	int ll = strlen(t);
	if (ll > l) return false;
	const char *r = s + l - ll;
//      cerr << r << " " << t << " " << !strcmp(r, t) << endl;
	return !strcmp(r, t);
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	n = 0;
	while (scanf("%s", s) == 1)
	{
		int l = strlen(s);
		a[n] = -1;
		if (check(s, l, "lios"))
		{
			a[n] = 0;
			b[n] = 0;
		}
		if (check(s, l, "liala"))
		{
			a[n] = 0;
			b[n] = 1;
		}
		if (check(s, l, "etr"))
		{
			a[n] = 1;
			b[n] = 0;
		}
		if (check(s, l, "etra"))
		{
			a[n] = 1;
			b[n] = 1;
		}
		if (check(s, l, "initis"))
		{
			a[n] = 2;
			b[n] = 0;
		}
		if (check(s, l, "inites"))
		{
			a[n] = 2;
			b[n] = 1;
		}
		if (a[n] == -1)
		{
			puts("NO");
			return 0;
		}
//	      cerr << a[n] << " " << b[n] << endl;
		n++;
	}
//      cerr << n << endl;
	
	if (n == 1)
	{
		puts("YES");
	}
	else
	{
		bool ok = true;
		forn(i, n)
		{
			if (b[i] != b[0]) ok = false;
		}
		int z = 0;
		forn(i, n)
		{
			if (z == 0)
			{
				if (a[i] == 0) z = 0;
				else if (a[i] == 1) z = 1;
				else ok = false;
			}
			else if (z == 1)
			{
				if (a[i] != 2) ok = false;
			}
		}
		ok = ok && z == 1;
		puts(ok ? "YES" : "NO");
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}