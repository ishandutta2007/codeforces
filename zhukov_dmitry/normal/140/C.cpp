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

FILE *g_f_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))

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

int n;
int a[102400];
map < int, int > c;
set < PII > d;
int ans[102400][4];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%d", &a[i]);
		c[a[i]]++;
	}
	fori(it, c)
	{
		d.insert(mp(it->second, it->first));
	}
	int k = 0;
	
	for(;;)
	{
		__typeof(d.begin()) it1 = d.end();
		if (it1 == d.begin()) break;
		it1--;
		__typeof(d.begin()) it2 = it1;
		if (it2 == d.begin()) break;
		it2--;
		__typeof(d.begin()) it3 = it2;
		if (it3 == d.begin()) break;
		it3--;
		ans[k][0] = it1->second;
		ans[k][1] = it2->second;
		ans[k][2] = it3->second;
		k++;
		PII p1 = *it1;
		PII p2 = *it2;
		PII p3 = *it3;
		d.erase(p1);
		d.erase(p2);
		d.erase(p3);
		if (--p1.first) d.insert(p1);
		if (--p2.first) d.insert(p2);
		if (--p3.first) d.insert(p3);
	}
	
	printf("%d\n", k);
	forn(i, k)
	{
		sort(ans[i], ans[i] + 3, greater < int > () );
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}