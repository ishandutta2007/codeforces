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

const int MOD = 1000000009;

const int pp = 5200007;

int n, m, k, kk;
string s[32];
int p[32][32];
int b[1024000][12];
i64 hh[pp];
int gg[pp];
VI q[1012][12];
int d[1024000];

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

void calc_pref(const char *s, int *p, int n)
{
	int q = -1;
	p[0] = -1;
	For(i, 1, n-1)
	{
		while (q != -1 && s[i] != s[q+1]) q = p[q];
		if (s[i] == s[q+1]) q++;
		p[i] = q;
	}
}

i64 calc_hash(int *a, int n)
{
	i64 z = 170;
	forn(i, n)
	{
		z = z * 23917 + (a[i] + 170);
	}
	return z;
}

void hinsert(i64 x, int k)
{
	int j = x % pp;
	if (j < 0) j += pp;
	while (hh[j] != -1)
	{
		if (hh[j] == x) return;
		j += 1997;
		if (j >= pp) j -= pp;
	}
	hh[j] = x;
	gg[j] = k;
}

int hfind(i64 x)
{
	int j = x % pp;
	if (j < 0) j += pp;
	while (hh[j] != -1)
	{
		if (hh[j] == x) return gg[j];
		j += 1997;
		if (j >= pp) j -= pp;
	}
	return -1;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(hh, 0xff, sizeof(hh));
	cin >> n >> m;
	forn(i, m)
	{
		cin >> s[i];
	}
	sort(s, s+m);
	m = unique(s, s+m) - s;
	forn(i, m)
	{
		calc_pref(s[i].c_str(), p[i], s[i].sz);
	}
	clr(d);
	kk = 0;

	int tmp[12];
	forn(i, m)
	{
		tmp[i] = -1;
	}
	tmp[m] = 0;
	tmp[m+1] = 0;
	i64 h = calc_hash(tmp, m+2);
	d[kk] = 1;
	memcpy(b[kk], tmp, (m + 2) * sizeof(*tmp));
	q[0][0].pb(kk);
	hinsert(h, kk++);
	int y[12];

	int ans = 0;
	forn(i, n)
	{
		forn(l, 20)
		{
			forn(q1, q[i][l].sz)
			{
				int *x = b[q[i][l][q1]];
				forn(c, 26)
				{
					char cc = c + 'A';
					int nl = l + 1;
					bool bb = false;
					forn(t, m)
					{
						int q = x[t];
						while (q != -1 && s[t][q+1] != cc) q = p[t][q];
						if (s[t][q+1] == cc) q++;
						if (q == (int)s[t].sz - 1)
						{
							q = p[t][q];
							if ((int)s[t].sz >= l+1) nl = 0, bb = true;
						}
						y[t] = q;
					}
					forn(t, m)
					{
						if (y[t] + 1 >= l+1)
						{
							bb = true;
							break;
						}
					}
					if (bb)
					{
						y[m] = i+1;
						y[m+1] = nl;

						i64 h = calc_hash(y, m+2);
						int z = hfind(h);
						if (z == -1)
						{
							z = kk;
							d[kk] = 0;
							memcpy(b[kk], y, (m + 2) * sizeof(*y));
							q[i+1][nl].pb(kk);
							hinsert(h, kk++);
						}
						add(d[z], d[q[i][l][q1]]);
						if (i+1 == n && !nl)
						{
							add(ans, d[q[i][l][q1]]);
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}