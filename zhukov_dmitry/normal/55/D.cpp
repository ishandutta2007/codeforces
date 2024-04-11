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
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int a[20];
i64 d[2][20][48][2520];
int b[256];
int p2[10];
int p3[10];
int p5[10];
int p7[10];
int mods[25200];

/*void precalc(int l)
{
	int ee = 0;
	if (d[0][0][0][0] != -1) ee = 1;
	For(eq, ee, 1)
	{
		forn(k, l)
		{
			forn(mask, 48)
			{
				forn(r, 2520)
				{
					i64 &ans = d[eq][k][mask][r];
					ans = 0;

					int up = 9;
					if (eq) up = a[k];
					For(i, 0, up)
					{
						int x = mask;
						int c2 = x & 3;
						x >>= 2;
						int c5 = x & 1;
						x >>= 1;
						int c7 = x & 1;
						x >>= 1;
						int c3 = x;
						if (i == 2 && c2 < 1) c2 = 1;
						if (i == 3 && c3 < 1) c3 = 1;
						if (i == 4 && c2 < 2) c2 = 2;
						if (i == 5 && c5 < 1) c5 = 1;
						if (i == 6 && c2 < 1) c2 = 1;
						if (i == 6 && c3 < 1) c3 = 1;
						if (i == 7 && c7 < 1) c7 = 1;
						if (i == 8 && c2 < 3) c2 = 3;
						if (i == 9 && c3 < 2) c3 = 2;
						int newmask = (((((c3 << 1) | c7) << 1) | c5) << 2) | c2;
						int en = eq && i == a[k];
						int mm = (r * 10 + i) % 2520;
						if (!k) ans += !(mm % b[newmask]);
						else ans += d[en][k-1][newmask][mm];
					}
				}
			}
		}
	}
}
*/
i64 f(int k, int mask, int r, bool eq)
{
	if (k < 0)
	{
		return r % b[mask] == 0;
	}
	i64 &ans = d[eq][k][mask][r];
	if (ans != -1) return ans;
	ans = 0;

	int up = 9;
	if (eq) up = a[k];
	int mm = mods[r * 10];
	For(i, 0, up)
	{
		int x = mask;
		int c2 = x & 3;
		x >>= 2;
		int c5 = x & 1;
		x >>= 1;
		int c7 = x & 1;
		x >>= 1;
		int c3 = x;
		if (i == 2 && c2 < 1) c2 = 1;
		if (i == 3 && c3 < 1) c3 = 1;
		if (i == 4 && c2 < 2) c2 = 2;
		if (i == 5 && c5 < 1) c5 = 1;
		if (i == 6 && c2 < 1) c2 = 1;
		if (i == 6 && c3 < 1) c3 = 1;
		if (i == 7 && c7 < 1) c7 = 1;
		if (i == 8 && c2 < 3) c2 = 3;
		if (i == 9 && c3 < 2) c3 = 2;
		int newmask = (((((c3 << 1) | c7) << 1) | c5) << 2) | c2;
		bool en = eq && i == a[k];
		if (!k || d[en][k-1][newmask][mm] == -1) ans += f(k-1, newmask, mm, en);
		else ans += d[en][k-1][newmask][mm];
		mm++;
		if (mm == 2520) mm = 0;
	}

	return ans;
}

i64 f(i64 n)
{
	int l = 0;
	i64 x = n;
	do
	{
		a[l++] = x % 10;
		x /= 10;
	}
	while (x);
	i64 ans = 0;

	memset(d[1], 0xff, sizeof(d[1]));
//	precalc(l);
	ans += f(l-1, 0, 0, 1);

	return ans;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(d, 0xff, sizeof(d));
	p2[0] = p3[0] = p5[0] = p7[0] = 1;
	For(i, 1, 9)
	{
		p2[i] = p2[i-1] * 2;
		p3[i] = p3[i-1] * 3;
		p5[i] = p5[i-1] * 5;
		p7[i] = p7[i-1] * 7;
	}
	forn(i, 25200)
	{
		mods[i] = i % 2520;
	}
	forn(mask, 48)
	{
		b[mask] = 1;
		int x = mask;
		int c2 = x & 3;
		x >>= 2;
		int c5 = x & 1;
		x >>= 1;
		int c7 = x & 1;
		x >>= 1;
		int c3 = x;
#define be(x) b[mask] *= p##x[c##x]
		be(2);
		be(3);
		be(5);
		be(7);
	}
	int qq;
	scanf("%d", &qq);
	while (qq--)
	{
		i64 l, r;
		scanf("%I64d%I64d", &l, &r);
		printf("%I64d\n", f(r) - f(l-1));
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %ld ms\n", (et_1 - et_0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}