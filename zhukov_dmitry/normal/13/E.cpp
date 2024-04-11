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

const int SH = 640;

int n, m;
int a[102400];
int next[102400];
int cnt[102400];
int last[102400];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%d", &a[i]);
	}
	int z = ((n-1) / SH + 1) * SH;
	ford(i, n)
	{
		int x = i + a[i];
		if (x >= n) x = z;
		int t = (i / SH + 1) * SH;
		if (x < t) next[i] = next[x], cnt[i] = cnt[x] + 1, last[i] = last[x];
		else next[i] = x, cnt[i] = 1, last[i] = i;
	}
	forn(i, m)
	{
		int r;
		scanf("%d", &r);
		if (r == 1)
		{
			int x;
			scanf("%d", &x);
			x--;
			int l = x, ans = 0;
			while (x < n)
			{
				ans += cnt[x];
				l = last[x];
				x = next[x];
			}
			printf("%d %d\n", l+1, ans);
		}
		else
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			a[x] = y;
			int t = (x / SH + 1) * SH;
			int tt = t - SH;
			Ford(i, x, tt)
			{
				int q = a[i] + i;
				if (q >= n) q = z;
				if (q < t) next[i] = next[q], cnt[i] = cnt[q] + 1, last[i] = last[q];
				else next[i] = q, cnt[i] = 1, last[i] = i;
			}
		}
	}

	return 0;
}