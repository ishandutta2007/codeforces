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
int a[1024][4];
MSI z;
string names[1024];
char s[10240];
int ind[1024];

bool cmp1(int p1, int p2)
{
	if (a[p1][0] != a[p2][0]) return a[p1][0] > a[p2][0];
	if (a[p1][1] - a[p1][2] != a[p2][1] - a[p2][2]) return a[p1][1] - a[p1][2] > a[p2][1] - a[p2][2];
	return a[p1][1] > a[p2][1];
}

bool cmp2(int p1, int p2)
{
	return names[p1] < names[p2];
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	k = 0;
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s", s);
		names[i] = s;
		z[s] = i;
	}

	clr(a);
	forn(i, n * (n-1)/2)
	{
		int x, y;
		scanf("%s %d:%d", s, &x, &y);
		string t1, t2;
		int l = strlen(s);
		bool f = true;
		forn(j, l)
		{
			if (s[j] != '-')
			{
				if (f) t1 += s[j];
				else t2 += s[j];
			}
			else
			{
				f = false;
			}
		}
		if (x > y)
		{
			a[z[t1]][0] += 3;
			a[z[t1]][1] += x;
			a[z[t1]][2] += y;
			a[z[t2]][0] += 0;
			a[z[t2]][1] += y;
			a[z[t2]][2] += x;
		}
		else if (x == y)
		{
			a[z[t1]][0] += 1;
			a[z[t1]][1] += x;
			a[z[t1]][2] += y;
			a[z[t2]][0] += 1;
			a[z[t2]][1] += y;
			a[z[t2]][2] += x;
		}
		else// if (x < y)
		{
			a[z[t1]][0] += 0;
			a[z[t1]][1] += x;
			a[z[t1]][2] += y;
			a[z[t2]][0] += 3;
			a[z[t2]][1] += y;
			a[z[t2]][2] += x;
		}
	}

	forn(i, n)
	{
		ind[i] = i;
	}
	sort(ind, ind+n, cmp1);

	sort(ind, ind+n/2, cmp2);
	forn(i, n/2)
	{
		puts(names[ind[i]].c_str());
	}

	return 0;
}