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
char *g_str_;
int g_s_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(x) (g_str_ = gets(x))

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

int n, m;
string s;
string b[6] = {"noob", "random", "average", "hardcore", "pro", "jury error"};
MSI d;
int a[1024];
int t[1024];

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	
	m = 0;
	cin >> n;
	forn(i, n)
	{
		int x;
		cin >> s >> x;
		if (!d.count(s)) d[s] = 0, m++;
		d[s] = max(d[s], x);
	}
	m = 0;
	fori(it, d)
	{
		a[m++] = it->second;
	}
	forn(i, m)
	{
		int l = 0;
		forn(j, m)
		{
			l += a[i] < a[j];
		}
		int w = 0;
		forn(j, m)
		{
			w += a[i] > a[j];
		}
		if (l * 2 > m) t[i] = 0;
		else if (l * 100 <= m * 50 && l * 100 > m * 20) t[i] = 1;
		else if (l * 100 <= m * 80 && l * 100 > m * 10) t[i] = 2;
		else if (l * 100 <= m * 90 && l * 100 > m * 1) t[i] = 3;
		else if (l * 100 <= m * 99) t[i] = 4;
		else t[i] = 5;
	}
	cout << m << endl;
	m = 0;
	fori(it, d)
	{
		cout << it->first << " " << b[t[m++]] << endl;
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}