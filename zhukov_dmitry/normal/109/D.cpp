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

int n, k, t;
int a[102400];
int a1[102400];
int a0[102400];
int b[102400];
int ans[1024000][2];
int p[102400];
bool u[102400];

bool cmp(int p1, int p2)
{
	if (a[p1] != a[p2]) return a[p1] < a[p2];
	return a1[p1] < a1[p2];
}

void precalc()
{
	t = -1;
	forn(i, n)
	{
		b[i] = i;
	}
	stable_sort(b, b+n, cmp);
	forn(i, n)
	{
		p[b[i]] = i;
	}
	forn(i, n)
	{
		int x = a[i];
		bool bb = true;
		while (x)
		{
			bb = bb && (x % 10 == 4 || x % 10 == 7);
			x /= 10;
		}
		if (bb && (t == -1 || b[i] == i)) t = i;
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
//      freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		a1[i] = i;
	}
	memcpy(a0, a, sizeof(a));
	precalc();
	bool sr = true;
	forn(i, n)
	{
		sr = sr && b[i] == i;
	}
	if (sr)
	{
		puts("0");
		return 0;
	}
	if (t == -1)
	{
		puts("-1");
		return 0;
	}
	k = 0;
//      cerr << t << endl;
	if (p[t] != t)
	{
		ans[k][0] = t;
		ans[k][1] = p[t];
		k++;
		cerr << t << " " << p[t] << endl;
//		return 0;
		swap(a[t], a[p[t]]);
		swap(a1[t], a1[p[t]]);
		precalc();
	}
	memcpy(p, b, sizeof(p));
	cerr << t << endl;
	clr(u);
	forn(i, n)
	{
		if (!u[i])
		{
			int x = i;
			u[x] = true;
			if (x == p[x]) continue;
			ans[k][0] = x;
			ans[k][1] = t;
			k++;
			int prev = x;
			x = p[x];
			while (x != i)
			{
				u[x] = true;
				ans[k][0] = x;
				ans[k][1] = prev;
				k++;
				prev = x;
				x = p[x];
			}
			ans[k][0] = prev;
			ans[k][1] = t;
			k++;
		}
	}
	
	printf("%d\n", k);
	forn(i, k)
	{
//		cerr << a0[ans[i][0]] << " " << a0[ans[i][1]] << endl;
/*		forn(j, n)
		{
			cerr << a0[j] << " ";
		}
		cerr << endl;*/
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
		swap(a0[ans[i][0]], a0[ans[i][1]]);
	}
/*	forn(i, n)
	{
		cerr << a0[i] << " ";
	}
	cerr << endl;
*/
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}