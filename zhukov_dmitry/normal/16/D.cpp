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
int a[10240];
char s[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d\n", &n);
	forn(i, n)
	{
		int hh, mm;
		char cc;
		scanf("[%d:%d %c.m.]: ", &hh, &mm, &cc);
		if (hh == 12)
		{
			hh = 0;
//			cc = (cc == 'a') ? 'p' : 'a';
		}
		if (cc == 'p')
		{
			hh += 12;
		}
		a[i] = hh * 60 + mm;
		gets(s);
	}

	int ans = 1;
	int x = a[0];
	int cnt = 1;
	For(i, 1, n-1)
	{
		if (a[i] > x)
		{
			x = a[i];
			cnt = 1;
		}
		else if (a[i] == x)
		{
			cnt++;
			if (cnt > 10)
			{
				cnt -= 10;
				ans++;
			}
		}
		else
		{
			x = a[i];
			cnt = 1;
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}