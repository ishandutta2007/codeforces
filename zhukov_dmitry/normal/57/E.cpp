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

const int MAXN = 2048;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

i64 k;
int n, m;
int d[MAXN][MAXN];
bool w[MAXN][MAXN];
bool u[MAXN][MAXN];
int q[MAXN * MAXN * 2][2];
int c[MAXN];

int mypow(int a, int k, int p)
{
	int ans = 1;
	int j = 1;
	while (j <= k) j <<= 1;
	j >>= 1;
	while (j)
	{
		ans = (i64)ans * ans % p;
		if (j & k) ans = (i64)ans * a % p;
		j >>= 1;
	}
	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t t0 = clock();
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	clr(w);
	clr(u);
	m = MAXN / 2;
	cin >> k >> n;
	forn(i, n)
	{
		int x, y;
		cin >> x >> y;
		w[x + m][y + m] = true;
	}
	int qb = 0;
	int qe = 0;
	q[qe][0] = m;
	q[qe][1] = m;
	qe++;
	u[m][m] = true;
	d[m][m] = 0;
	
	while (qb != qe)
	{
		int x = q[qb][0];
		int y = q[qb][1];
		qb++;
		forn(l, 8)
		{
			int xn = x + dx[l];
			int yn = y + dy[l];
			if (xn < 0 || xn >= MAXN || yn < 0 || yn >= MAXN || w[xn][yn] || u[xn][yn]) continue;
			d[xn][yn] = d[x][y] + 1;
			u[xn][yn] = true;
			q[qe][0] = xn;
			q[qe][1] = yn;
			qe++;
		}
	}
	
	clr(c);
	forn(i, MAXN)
	{
		forn(j, MAXN)
		{
			if (u[i][j] && d[i][j] < MAXN)
			{
				c[d[i][j]]++;
			}
		}
	}
	int r = m / 2 - 17;
	
	if (k <= r)
	{
		int sum = 0;
		forn(i, k+1)
		{
			sum += c[i];
		}
		cout << sum << endl;
	}
	else
	{
		int a[10];
		
		forn(i, 10)
		{
			a[i] = c[r+i];
		}
		int b[10];
		int sum = 0;
		forn(i, r)
		{
			sum += c[i];
		}
		b[0] = sum;
		forn(i, 9)
		{
			b[i+1] = a[0];
/*			forn(j, 10-i)
			{
				cerr << a[j] << " ";
			}
			cerr << endl;*/
			forn(j, 9 - i)
			{
				a[j] = a[j+1] - a[j];
			}
		}
		
		const int MOD = 1000000007;
		i64 ans = 0;
		
		i64 z = (k - (r-1) + MOD) % MOD;
		i64 ff = 120;
		forn(i, 6)
		{
			i64 s = b[i];
			int f = 1;
			forn(j, i)
			{
				s = s * (z - j) % MOD;
				f = f * (j+1);
			}
			ans = (ans + s * (ff / f)) % MOD;
		}
		ans = (ans * mypow(ff, MOD-2, MOD)) % MOD;
		
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		cout << ans << endl;
	}

#ifdef ROOM_311
	time_t t1 = clock();
	fprintf(stderr, "execution time = %ld ms\n", (t1 - t0) * 1000 / CLOCKS_PER_SEC);
#endif
	return 0;
}