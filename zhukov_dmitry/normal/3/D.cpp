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

#define MAXN 50240

int n, k;
char s[MAXN];
int a[MAXN][2];
int c[MAXN];
int rs[MAXN];
int ind[MAXN];
int pa[MAXN];
int r[MAXN];

inline bool cmp(int p1, int p2)
{
	return a[p1][0] - a[p1][1] < a[p2][0] - a[p2][1];
}

inline int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

inline void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);
	pa[x] = y;
	r[y] = max(r[x], r[y]);
}

bool check(int p)
{
	int mi = r[find(p)] + 1;
	if (find(mi) == find(n+1) || find(mi) == find(n+2)) return false;

	int mi2 = r[find(mi)] + 1;
	if (find(mi2) == find(n+1) || find(mi2) == find(n+2)) return false;

	unite(find(p), find(mi));
	unite(find(p), find(mi2));

	return true;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(45361);
	scanf("%s", s);
	n = strlen(s);
	k = 0;
	forn(i, n)
	{
		if (s[i] == '?')
		{
			forn(j, 2)
			{
				scanf("%d", &a[k][j]);
			}
			c[k] = i;
			ind[k] = k;
			k++;
		}
	}
	sort(ind, ind+k, cmp);
	
	int sum = 0;
	rs[n] = 0;
	rs[n+1] = -1;
	rs[n+2] = -2;
	ford(i, n)
	{
		if (s[i] == '(') sum--;
		else sum++;
		rs[i] = sum;
	}
	forn(i, n)
	{
		rs[i+1] = min(rs[i+1], rs[i]);
	}
	forn(i, n+3)
	{
		pa[i] = i;
		r[i] = i;
	}
	forn(i, n)
	{
		if (rs[i] == rs[i+1]) unite(pa[i], pa[i+1]);
	}

	forn(i1, k)
	{
		int i = ind[i1];
		int j = c[i];
		s[j] = check(j) ? '(' : ')';
	}

	sum = 0;
	forn(i, n)
	{
		if (s[i] == '(') sum++;
		else sum--;
		if (sum < 0)
		{
			puts("-1");
			return 0;
		}
	}
	if (sum)
	{
		puts("-1");
		return 0;
	}

	i64 ans = 0;
	forn(i, k)
	{
		if (s[c[i]] == '(') ans += a[i][0];
		else ans += a[i][1];
	}
	printf("%I64d\n", ans);
	puts(s);

	return 0;
}