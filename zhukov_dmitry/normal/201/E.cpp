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

const int INF = 0x3f3f3f3f;

int n, m;
int c[1024][1024];

int c_c(int n, int m)
{
	if (m < 0) return 0;
	if (n < m) return 0;
	if (n <= 1000) return c[n][m];
	if (m >= 4) return INF;
	if (m == 0) return 1;
	if (m == 1) return n;
	if (m == 2) return min(n * (i64)(n - 1) / 2, (i64)INF);
	// m == 3
	i64 tmp = (n * (i64)(n - 1) / 2);
	if (tmp > INF) return INF;
	tmp = tmp * (n - 2) / 3;
	if (tmp > INF) return INF;
	return tmp;
}

int f(int w, int m)
{
	int ans = 0;

	int k = 0;
//	cerr << "---" << endl;
	For(i, 0, w)
	{
		int cc = c_c(w, i);
//		cerr << cc << endl;
//		i64 kk = cc * (i64)i / w;
		int kk = c_c(w - 1, i - 1);
//		cerr << w << " " << i << "  " << kk << " " << cc * (i64)i / w << endl;
		if (k + kk > m)
		{
//			cerr << i << " " << k << " " << kk << endl << endl;
			i64 tmp = (m - k) * (i64)w / i;
			tmp -= 2;
			if (tmp > INF) tmp = INF;
			int x = tmp;
//			cerr << ans << " " << x << endl;
//			int x = 0;
			if (x < 0) x = 0;
			ans += x;
			if (ans > INF) return INF;

//			for(;;)
			x++;
			while (x < cc)
			{
				i64 t = ((x * (i64)i + w - 1) / w);
				if (t + k > m) break;
//				k += t;
				ans++;
				if (ans > INF) return INF;
				x++;
			}

			break;
		}
		ans += cc;
		if (ans > INF) return INF;
		k += kk;
	}

	return ans;
}

int solve(int n, int m)
{
	int ans = n - 1;
	if (n == 1) return 0;
	if (m == 1) return n - 1;

	int mi = 1;
	int ma = 1000000000;
	while (mi < ma)
	{
		int q = (mi + ma) / 2;
		int z = f(q, m);
//		cerr << q << " " << z << endl;
		if (z >= n) ma = q;
		else mi = q + 1;
	}
	ans = mi;

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

	clr(c);
	forn(i, 1001)
	{
		c[i][i] = c[i][0] = 1;
		For(j, 1, i - 1)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] > INF) c[i][j] = INF;
		}
	}
//	cerr << f(10, 7) << endl;
//	return 0;

	int qq;
	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d%d", &n, &m);
		int ans = solve(n, m);
		printf("%d\n", ans);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}