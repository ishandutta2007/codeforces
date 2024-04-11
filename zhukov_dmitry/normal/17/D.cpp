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

#define BASE 10000

int bb[1024000];
int nn[1024000];
int c;
char sb[1024000];
char sn[1024000];
int ps[128];
int cs[128];
int as[128];
int ind[128];
int fc;

int modak(int *a, int k)
{
	int j = 0;
	Ford(i, a[0], 1)
	{
		j = ((i64)j * BASE + a[i]) % k;
	}
	return j;
}

int mypow(int a, int k, int p)
{
	int ans = 1;
	int j = 1 << 30;
	while (j)
	{
		ans = (i64)ans * ans % p;
		if (j & k) ans = (i64)ans * a % p;
		j >>= 1;
	}
	return ans;
}

int toint(int *a)
{
	if (a[0] > 3 || (a[0] == 3 && a[a[0]] > 10)) return 1000000001;
	int x = 0;
	Ford(i, a[0], 1)
	{
		x = x * BASE + a[i];
	}
	return min(x, 1000000001);
}

int calc(int p, int k)
{
	int ans = 1;
	int r = 1;
	forn(i, k)
	{
		r *= p;
	}

	int fc = p-1;
	forn(i, k-1)
	{
		fc *= p;
	}
	int nnn = toint(nn);
//	cerr << "r = " << r << endl;
//	cerr << "fc = " << fc << endl;
	int b1 = modak(bb, r);
//	cerr << bb[0] << " " << bb[1] << endl;
//	cerr << "b1 = " << b1 << endl;
	ans = (i64)ans * (b1-1+r) % r;
	if (b1 % p == 0)
	{
		if (nnn > k)
		{
			return 0;
		}
		else
		{
//			cerr << "ans = " << ans << endl;
			ans = (i64)ans * mypow(b1, nnn-1, r) % r;
//			cerr << "ans = " << ans << endl;
		}
	}
	else
	{
		int t = (modak(nn, fc) - 1 + fc) % fc;
//		cerr << "t = " << t << endl;
		ans = (i64)ans * mypow(b1, t, r) % r;
	}

	return ans;
}

bool cmp(int p1, int p2)
{
	return pow(ps[p1], cs[p1]) > pow(ps[p2], cs[p2]);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(bb);
	clr(nn);
	scanf("%s%s%d", sb, sn, &c);
	if (c == 1)
	{
		puts("1");
		return 0;
	}
	int lb = strlen(sb);
	int ln = strlen(sn);
	bb[0] = (lb + 3) / 4;
	nn[0] = (ln + 3) / 4;
	For(i, 1, bb[0])
	{
		forn(j, 4)
		{
			bb[i] = bb[i] * 10 + ((lb - i * 4 + j >= 0) ? (sb[lb - i * 4 + j] - '0') : 0);
		}
	}
	For(i, 1, nn[0])
	{
		forn(j, 4)
		{
			nn[i] = nn[i] * 10 + ((ln - i * 4 + j >= 0) ? (sn[ln - i * 4 + j] - '0') : 0);
		}
	}
	fc = 1;
	int x = c;
	int m = 0;
	for(int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			x /= i;
			fc *= i-1;
			ps[m] = i;
			cs[m] = 1;
			while (x % i == 0)
			{
				x /= i;
				fc *= i;
				cs[m]++;
			}
			m++;
		}
	}
	if (x > 1)
	{
		ps[m] = x;
		cs[m] = 1;
		m++;
		fc *= x-1;
		x /= x;
	}

	forn(i, m)
	{
		as[i] = calc(ps[i], cs[i]);
		ind[i] = i;
	}
	sort(ind, ind+m, cmp);
	int ans = as[ind[0]];
	int r = 1;
	forn(j, cs[ind[0]])
	{
		r *= ps[ind[0]];
	}
	For(i1, 1, m-1)
	{
		int i = ind[i1];
		int z = 1;
		forn(j, cs[i])
		{
			z *= ps[i];
		}
		while (ans % z != as[i]) ans += r;
		r *= z;
	}
//	forn(i, m)
//	{
//		cerr << ps[i] << " " << cs[i] << " " << as[i] << endl;
//	}

	if (ans <= 0) ans += c;

	printf("%d\n", ans);

	return 0;
}