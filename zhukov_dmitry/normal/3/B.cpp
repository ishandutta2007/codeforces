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

int n, k, m1, m2;
int a1[102400];
int a2[102400];
int ind1[102400];
int ind2[102400];
int b1[102400];
int b2[102400];

bool cmp1(int p1, int p2)
{
	return a1[p1] > a1[p2];
}

bool cmp2(int p1, int p2)
{
	return a2[p1] > a2[p2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d %d", &n, &k);
	m1 = m2 = 0;
	forn(i, n)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == 2)
		{
			b1[m1] = i + 1;
			a1[m1++] = y;
		}
		else
		{
			b2[m2] = i + 1;
			a2[m2++] = y;
		}
	}
	forn(i, m1)
	{
		ind1[i] = i;
	}
	forn(i, m2)
	{
		ind2[i] = i;
	}

	sort(ind1, ind1+m1, cmp1);
	sort(ind2, ind2+m2, cmp2);

	int l1 = 0;
	while (l1 < m1 && k >= 2)
	{
		k -= 2;
		l1++;
	}
	int l2 = 0;
	while (k >= 1 && l2 < m2)
	{
		k--;
		l2++;
	}

	while (l2 < m2 - 1 && l1 > 0 && a2[ind2[l2]] + a2[ind2[l2+1]] > a1[ind1[l1-1]])
	{
		l2 += 2;
		l1--;
	}

	if (l2 < m2 && l1 > 0 && a2[ind2[l2]] > a1[ind1[l1]])
	{
		l2++;
		l1--;
	}

	i64 ans = 0;
	forn(i, l1)
	{
		ans += a1[ind1[i]];
	}
	forn(i, l2)
	{
		ans += a2[ind2[i]];
	}

	printf("%I64d\n", ans);
	forn(i, l1)
	{
		printf("%d ", b1[ind1[i]]);
	}
	forn(i, l2)
	{
		printf("%d ", b2[ind2[i]]);
	}
	puts("");

	return 0;
}