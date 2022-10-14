#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int x, n;
i64 p10[22];
int a0[22];
int a[22];
int b[22];
int c1[22];
int c2[22];

int f(int x)
{
	int ans = 0;
	while (x)
	{
		ans += x % 10 == 4 || x % 10 == 7;
		x /= 10;
	}
	return ans;
}

bool check(i64 xn)
{
	i64 z = xn;
//	if (xn == 747) cerr << "!";
//	cerr << xn << endl;
	clr(a);
	int l = 0;
	while (z)
	{
		a[l++] = z % 10;
		z /= 10;
	}
	int xx = n;
	forn(i, 10)
	{
		if (a[i] == a0[i]) continue;
		if (n >= p10[i + 1]) return false;
		memcpy(c1, a, sizeof(a));
		memcpy(c2, a0, sizeof(a0));
		i64 k1 = xn;
		i64 k2 = x;
		Ford(j, 9, 0)
		{
			while (xx >= p10[j])
			{
				if (f(k1) != f(k2)) return false;
				xx -= p10[j] - 1;
				k1 += p10[j] - 1;
				k2 += p10[j] - 1;
				if (f(k1) != f(k2)) return false;
				xx -= 1;
				k1 += 1;
				k2 += 1;
			}
		}
		break;
	}
//      cerr << "xx = " << x << " " << xn << endl;
	return true;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	p10[0] = 1;
	For(i, 1, 19)
	{
		p10[i] = p10[i-1] * 10;
	}
	scanf("%d%d", &x, &n);
	int z = x;
	clr(a0);
	int l = 0;
	while (z)
	{
		a0[l++] = z % 10;
		z /= 10;
	}
	i64 xx = x + 1000000000;
	forn(zz, 10)
	{
		Ford(l, 9, 1)
		{
			xx -= (i64)p10[l] * 1000;
			forn(i, 10000)
			{
				xx += p10[l - 1];
				if (xx <= x) continue;
				if (check(xx)) break;
			}
//			cerr << xx << endl;
		}
	}
//	int xx = x + 1;
//	while (!check(xx)) xx++;
	cout << xx << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}