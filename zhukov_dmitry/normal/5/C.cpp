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

char a[1024000];
int n;
int t[1024000];
int pa[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(pa, 0xff, sizeof(pa));
	scanf("%s", a);
	n = strlen(a);
	int tt = 0;
	forn(i, n)
	{
		if (a[i] == '(')
		{
			t[tt++] = i;
		}
		else
		{
			if (tt > 0 && a[t[tt-1]] == '(')
			{
				tt--;
				pa[i] = t[tt];
			}
			else
			{
				tt = 0;
			}
		}
	}

	int ma = 0;
	int cnt = 1;

	forn(i, n)
	{
		if (pa[i] != -1)
		{
			int x = pa[i] - 1;
			if (x != -1 && pa[x] != -1) pa[i] = pa[x];

			if (i - pa[i] + 1 > ma)
			{
				ma = i - pa[i] + 1;
				cnt = 1;
			}
			else if (i - pa[i] + 1 == ma)
			{
				cnt++;
			}
		}
	}

	printf("%d %d\n", ma, cnt);

	return 0;
}