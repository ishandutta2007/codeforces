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

int n, m, k;
char s[102400];
int a[10240];
int b[1024];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	clr(b);
	k = 0;
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%s", s);
		if (*s == 'a')
		{
			int x;
			scanf("%d", &x);
			bool ok = false;
			forn(i, m-x+1)
			{
				bool bb = true;
				forn(j, x)
				{
					if (a[i+j]) bb = false;
				}
				if (bb)
				{
					ok = true;
					k++;
					forn(j, x)
					{
						a[i+j] = k;
					}
					printf("%d\n", k);
					break;
				}
			}
			if (!ok)
			{
				puts("NULL");
			}
		}
		else if (*s == 'e')
		{
			int x;
			scanf("%d", &x);
			bool ok = false;
			forn(i, m)
			{
				if (!a[i]) continue;
				if (a[i] == x)
				{
					ok = true;
					a[i] = 0;
				}
			}
			if (!ok)
			{
				puts("ILLEGAL_ERASE_ARGUMENT");
			}
		}
		else
		{
			int mm = 0;
			forn(i, m)
			{
				if (a[i]) a[mm++] = a[i];
			}
			For(i, mm, m-1)
			{
				a[i] = 0;
			}
		}
	}

	return 0;
}