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

#define x first
#define y second

int n;
int a[102400];
int l[102400];
int r[102400];
int pa[102400];
PII z[102400];
int ll[102400];
int rr[102400];
int ls[102400];
int rs[102400];
i64 sum[102400];
int cnt[102400];

void dfs(int k)
{
	ll[k] = rr[k] = ls[k] = rs[k] = k;
 	if (l[k] == -1)
	{
		return;
	}

	dfs(l[k]);
	dfs(r[k]);
	ll[k] = ll[l[k]];
	rr[k] = rr[r[k]];
	ls[k] = rr[l[k]];
	rs[k] = ll[r[k]];
}

void dfs2(int k)
{
	if (l[k] == -1)
	{
		return;
	}

	sum[l[k]] = sum[k] + a[rs[k]];
	cnt[l[k]] = cnt[k] + 1;
	sum[r[k]] = sum[k] + a[ls[k]];
	cnt[r[k]] = cnt[k] + 1;

	dfs2(l[k]);
	dfs2(r[k]);
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(l, 0xff, sizeof(l));
	memset(r, 0xff, sizeof(r));
	scanf("%d", &n);
	int root = 1;
	forn(i, n)
	{
		scanf("%d%d", &pa[i], &a[i]);
		if (pa[i] != -1) pa[i]--;
		else root = i;

		if (pa[i] != -1)
		{
			int v = pa[i];
			if (l[v] == -1) l[v] = i;
			else r[v] = i;
		}
		z[i] = mp(a[i], i);
	}
	sort(z, z+n);
	forn(i, n)
	{
		if (l[i] != -1)
		{
			if (a[l[i]] > a[r[i]]) swap(l[i], r[i]);
		}
	}

	dfs(root);
	clr(sum);
	clr(cnt);
	dfs2(root);

	int k;
	scanf("%d", &k);
	forn(i, k)
	{
		int x;
		scanf("%d", &x);
		int t = lower_bound(z, z+n, mp(x, -1)) - z;
		if (t == n) t--;
		int q = ls[z[t].second];
//		cerr << q << endl;
//		cerr << sum[q] << " " << cnt[q] << endl;
		if (cnt[q]) printf("%0.10lf\n", sum[q] * 1.0 / cnt[q]);
		else puts("0.0000000000");
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}