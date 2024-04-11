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

int n, m, k, x;
i64 f[1024];
char s1[1024];
char s2[1024];

bool check(int p0, int p1, int cnt, int len, char *s)
{
	s[0] = 'A' + p0;
	s[len - 1] = 'A' + p1;
	s[len] = '\0';
	int z = 0;
	For(i, 1, len - 2)
	{
		if (z < cnt)
		{
			if (s[i - 1] == 'A') s[i] = 'C';
			else s[i] = 'A';
			if (s[i - 1] == 'A' && s[i] == 'C') z++;
		}
		else
		{
			s[i] = 'B';
		}
	}
	z = 0;
	For(i, 1, len - 1)
	{
		if (s[i - 1] == 'A' && s[i] == 'C') z++;
	}
//	cerr << z << " " << cnt << " " << len << " " << s << " " << (z == cnt) << endl;
	return (z == cnt);
}

i64 calc(int *p, int k)
{
	i64 add = p[1] == 0 && p[2] == 2;
	if (k == 3) return add;
	int pn[4];
	pn[0] = p[2];
	pn[1] = p[3];
	pn[2] = p[0];
	pn[3] = p[3];
	return calc(pn, k - 1) + add * f[k - 2];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	For(i, 3, 100)
	{
		f[i] = f[i - 2] + f[i - 1];
	}
	scanf("%d%d%d%d", &k, &x, &n, &m);
	forn(mask, 81)
	{
		int t = mask;
		int p[4];
		forn(i, 4)
		{
			p[i] = t % 3;
			t /= 3;
		}
		if (n == 1 && p[0] != p[1]) continue;
		if (m == 1 && p[2] != p[3]) continue;
		i64 cur = calc(p, k);
		i64 rem = x - cur;
		if (rem < 0) continue;
		For(i, 0, 50)
		{
			For(j, 0, 50)
			{
				if (rem != i * f[k - 2] + j * f[k - 1]) continue;
				if (check(p[0], p[1], i, n, s1) && check(p[2], p[3], j, m, s2))
				{
//					cerr << rem << " " << i << " " << j << endl;
					puts(s1);
					puts(s2);
					return 0;
				}
			}
		}
	}

	puts("Happy new year!");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}