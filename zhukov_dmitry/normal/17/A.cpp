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
int a[102400];

bool prost(int k)
{
	if (k < 2) return false;
	For(i, 1, a[0])
	{
		if (a[i] * a[i] > k) return true;
		if (k % a[i] == 0) return false;
	}
	return true;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	a[0] = 2;
	a[1] = 2;
	a[2] = 3;

	for(int j = 5; j <= 10000; j += 2)
	{
		if (prost(j))
		{
			a[++a[0]] = j;
		}
	}

	scanf("%d%d", &n, &k);
	int cnt = 0;
	For(i, 2, n)
	{
		if (!prost(i)) continue;
		For(j, 1, a[0])
		{
			if (a[j] + a[j+1] + 1 == i)
			{
				cnt++;
				break;
			}
			if (a[j] + a[j+1] + 1 > i)
			{
				break;
			}
		}
	}

	puts(cnt >= k ? "YES" : "NO");

	return 0;
}