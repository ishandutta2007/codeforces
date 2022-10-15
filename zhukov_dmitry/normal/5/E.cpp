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
int a[4024000];
int b[2024000];
int t[2024000];
int s[2024000];

i64 solve(int *a, int n, bool one)
{
	if (n <= 2) return 0;
//	forn(i, n)
//	{
//		cerr << a[i] << " ";
//	}
//	cerr << endl;

	i64 ans = 0;

	int tt = 0;
	forn(i, n)
	{
		while (tt > 0 && t[tt-1] < a[i])
		{
//			cerr << t[tt-1] << " " << a[i] << endl;
			tt--;
			if (i == n-1 && one && tt <= 1)
			{
			}
			else
			{
				ans += s[tt];
			}
		}

		if (tt == 0 || t[tt-1] > a[i])
		{
			if (tt > 0)
			{
				ans++;
//				cerr << t[tt-1] << " " << a[i] << endl;
			}
			s[tt] = 1;
			t[tt++] = a[i];
		}
		else
		{
			if (i == n-1)
			{
			}
			else
			{
				ans += s[tt-1];
				if (tt > 1) ans++;
			}
			s[tt-1]++;
//			cerr << "!" << t[tt-1] << " " << a[i] << endl;
		}
	}
//	cerr << ans << endl;
//	cerr << endl;

	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	int ma = -2100000000;
	int cnt = 1;
	forn(i, n)
	{
		scanf("%d", &a[i]);
		if (a[i] > ma)
		{
			ma = a[i];
			cnt = 1;
		}
		else if (a[i] == ma)
		{
			cnt++;
		}
	}
	forn(i, n)
	{
		a[i+n] = a[i];
	}
//	cerr << cnt << endl;
	i64 ans = (i64)cnt * (cnt-1) / 2;

	forn(i, n)
	{
		if (a[i] == ma)
		{
			int k = 0;
			forn(j, n+1)
			{
				if (a[i+j] == ma)
				{
					b[k++] = a[i+j];
					ans += solve(b, k, cnt == 1);
					k = 0;
					b[k++] = a[i+j];
				}
				else
				{
					b[k++] = a[i+j];
				}
			}
			break;
		}
	}

	cout << ans << endl;

	return 0;
}