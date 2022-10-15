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
string a[1024];
char s[10240];
int b[1024];
MSI z;
int c[1024];
int f[1024];
string names[1024];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	m = -1;
	k = 0;
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s%d", s, &b[i]);
		a[i] = s;
		if (z.find(a[i]) == z.end()) names[k] = a[i], z[a[i]] = k++;
	}

	clr(c);
	forn(i, n)
	{
		int t = z[a[i]];
		c[t] += b[i];
	}

	memset(f, 0x3f, sizeof(f));
	forn(i, k)
	{
		m = max(m, c[i]);
	}

	clr(c);
	forn(i, n)
	{
		int t = z[a[i]];
		c[t] += b[i];
		if (c[t] >= m)
		{
			f[t] = min(f[t], i);
		}
	}
    
	int ff = 10000;
	int mj = -1;
	forn(i, k)
	{
//		cerr << names[i] << " " << c[i] << " " << f[i] << endl;
		if (c[i] == m && f[i] < ff)
		{
			ff = f[i];
			mj = i;
		}
	}

	printf("%s\n", names[mj].c_str());

	return 0;
}