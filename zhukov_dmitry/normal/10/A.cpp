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

int n, p1, p2, p3, t1, t2;
bool a[10240];
int b[10240][2];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
	int last = -1;

	forn(i, n)
	{
		scanf("%d%d", &b[i][0], &b[i][1]);
		b[i][1]--;
		For(j, b[i][0], b[i][1])
		{
			a[j] = true;
		}
	}

	int ans = 0;

	For(i, b[0][0], b[n-1][1])
	{
		if (a[i])
		{
			last = i;
			ans += p1;
		}
		else
		{
			if (i > last + t1 + t2) ans += p3;
			else if (i > last + t1) ans += p2;
			else ans += p1;
		}
	}

	cout << ans << endl;

	return 0;
}