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

int n, k;
int a[1024];
int ind[1024];
int s;

bool cmp(int p1, int p2)
{
	return a[p1] < a[p2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &k);
	s = 0;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		s += a[i];
		ind[i] = i;
	}
	sort(ind, ind+n, cmp);

	if (s < k || k < 1)
	{
		puts("No");
		return 0;
	}

	if (n == 1)
	{
		if (s != k)
		{
			puts("No");
			return 0;
		}
		else
		{
			puts("Yes");
			forn(i, a[0] * 2)
			{
				if (i) putchar(' ');
				printf("1");
			}
			puts("");
			return 0;
		}
	}

	int mi = a[ind[0]];
	if (k >= mi)
	{
		puts("Yes");
		printf("%d", ind[0] + 1);
		int t = s - k;
		forn(i, n)
		{
			if (ind[0] == i) continue;
			if (!t) break;
			while (a[i] > 0)
			{
				printf(" %d", i+1);
				printf(" %d", i+1);
				a[i]--;
				t--;
				if (!t) break;
			}
		}
		printf(" %d", ind[0] + 1);
		a[ind[0]]--;
		forn(i, n)
		{
			while (a[i] > 0)
			{
				printf(" %d", i+1);
				printf(" %d", i+1);
				a[i]--;
			}
		}
		puts("");
	}
	else
	{
		if (k == 1)
		{
			puts("No");
			return 0;
		}
		puts("Yes");
		int t = 0;
		while (t == ind[0]) t++;
		printf("%d", t + 1);
		int r = a[ind[0]] - (k-1);
		forn(i, r)
		{
			printf(" %d", ind[0]+1);
			printf(" %d", ind[0]+1);
			a[ind[0]]--;
		}
		printf(" %d", t + 1);
		a[t]--;
		k--;
		s = 0;
		forn(i, n)
		{
			s += a[i];
		}

		printf(" %d", ind[0] + 1);
		t = s - k;
		forn(i, n)
		{
			if (ind[0] == i) continue;
			if (!t) break;
			while (a[i] > 0)
			{
				printf(" %d", i+1);
				printf(" %d", i+1);
				a[i]--;
				t--;
				if (!t) break;
			}
		}
		printf(" %d", ind[0] + 1);
		a[ind[0]]--;
		forn(i, n)
		{
			while (a[i] > 0)
			{
				printf(" %d", i+1);
				printf(" %d", i+1);
				a[i]--;
			}
		}
		puts("");
	}

	return 0;
}