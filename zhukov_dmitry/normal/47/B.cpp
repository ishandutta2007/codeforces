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

char s[1024];
bool a[3][3];
int p[3];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	forn(i, 3)
	{
		gets(s);
		bool l = s[1] == '<';
		a[s[0] - 'A'][s[2] - 'A'] = l;
		a[s[2] - 'A'][s[0] - 'A'] = !l;
	}
	forn(i, 3)
	{
		p[i] = i;
	}
	do
	{
		bool bb = true;
		forn(i, 3)
		{
			forn(j, i)
			{
				if (!a[p[j]][p[i]]) bb = false;
			}
		}
		if (bb)
		{
			forn(i, 3)
			{
				putchar('A' + p[i]);
			}
			puts("");
			return 0;
		}
	}
	while (next_permutation(p, p+3));

	puts("Impossible");

	return 0;
}