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

int n, l1, l2;
char s[102400];
int p1[102400];
int p2[102400];
char s1[102400];
char s2[102400];

bool check()
{
	int mm = -1;
	forn(i, n - l1 + 1)
	{
		bool bb = true;
		forn(j, l1)
		{
			if (s[i+j] != s1[j])
			{
				bb = false;
				break;
			}
		}
		if (bb)
		{
			mm = i + l1;
			break;
		}
	}
	if (mm == -1) return false;
	For(i, mm, n - l2)
	{
		bool bb = true;
		forn(j, l2)
		{
			if (s[i+j] != s2[j])
			{
				bb = false;
				break;
			}
		}
		if (bb)
		{
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s%s%s", s, s1, s2);
	n = strlen(s);
	l1 = strlen(s1);
	l2 = strlen(s2);

	bool b1 = check();
	reverse(s, s+n);
	bool b2 = check();

	if (b1 && b2)
	{
		puts("both");
	}
	else if (b1)
	{
		puts("forward");
	}
	else if (b2)
	{
		puts("backward");
	}
	else
	{
		puts("fantasy");
	}

	return 0;
}