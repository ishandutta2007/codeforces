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

#define clr(x) memset((x), 0, sizeof(x))
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
typedef long long i64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, m;
MSI d;
int a[16][16];
int c[3];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(a);
	n = 0;
	cin >> m;
	forn(i, m)
	{
		string s1, s2;
		cin >> s1 >> s2 >> s2;
		if (!d.count(s1)) d[s1] = n++;
		if (!d.count(s2)) d[s2] = n++;
		a[d[s1]][d[s2]] = 1;
	}
	cin >> c[0] >> c[1] >> c[2];
	n = 7;
	int p3 = 1;
	forn(i, n)
	{
		p3 *= 3;
	}
	int a1 = 2100000000, a2 = 2100000000;
	forn(mask, p3)
	{
		int b[8];
		int x = mask;
		int cnt[3] = {0};
		forn(i, n)
		{
			cnt[b[i] = x % 3]++;
			x /= 3;
		}
		if (!cnt[0] || !cnt[1] || !cnt[2]) continue;
		int e[8];
		forn(i, 7)
		{
			e[i] = c[b[i]] / cnt[b[i]];
		}
		int mi = e[0];
		int ma = e[0];
		int z = 0;
		forn(i, 7)
		{
			mi = min(mi, e[i]);
			ma = max(ma, e[i]);
			forn(j, 7)
			{
				if (b[i] == b[j]) z += a[i][j];
			}
		}
		if (ma - mi < a1 || (ma - mi == a1 && z > a2))
		{
			a1 = ma - mi;
			a2 = z;
		}
	}

	cout << a1 << " " << a2 << endl;

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}