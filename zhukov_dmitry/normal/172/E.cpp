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
char *g_ss_;
#define freopen(a, b, c) (g_f_ = freopen(a, b, c))
#define scanf(...) (g_s_ = scanf(__VA_ARGS__))
#define sscanf(...) (g_s_ = sscanf(__VA_ARGS__))
#define gets(x) (g_ss_ = gets(x))

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
char s[2024000];
char s2[2024000];
i64 x[1024000];
int a[1024000];
int b[1024000];
bool tk[1024000];
int tt;

i64 calc_h(char *s, int n)
{
	i64 hh = 0;
	forn(i, n)
	{
		hh = (hh * 17231139 + s[i] + 3) % 31131123917311241LL;
	}
	return hh;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	int m = 0;
	gets(s);
	int len = strlen(s);
	int start = -1;
	For(i, 1, len - 2)
	{
		if (isalpha(s[i]) && !isalpha(s[i - 1])) start = i;
		if (isalpha(s[i]) && !isalpha(s[i + 1])) x[m++] = calc_h(s + start, i - start + 1);
	}
	sort(x, x+m);
	m = unique(x, x+m) - x;
	int cnt = 0;
	For(i, 1, len - 2)
	{
		if (isalpha(s[i]) && !isalpha(s[i - 1])) start = i;
		if (isalpha(s[i]) && !isalpha(s[i + 1]))
		{
			a[cnt] = lower_bound(x, x + m, calc_h(s + start, i - start + 1)) - x + 1;
			if (s[start - 1] == '/') a[cnt] *= -1;
			else if (s[i + 1] == '/') a[cnt + 1] = -a[cnt], cnt++;
			cnt++;
		}
	}
	
	gets(s2);
	sscanf(s2, "%d", &n);
	forn(i, n)
	{
		gets(s2);
		int ans = 0;
		int l = strlen(s2);
		int k = 0;
		start = -1;
		forn(j, l)
		{
			if (isalpha(s2[j]) && (!j || !isalpha(s2[j - 1]))) start = j;
			if (isalpha(s2[j]) && (j == l - 1 || !isalpha(s2[j + 1])))
			{
				i64 h = calc_h(s2 + start, j - start + 1);
				if (binary_search(x, x + m, h)) b[k++] = lower_bound(x, x + m, h) - x + 1;
				else b[k++] = m + 239;
			}
		}
		tt = 0;
		int kk = 0;
		forn(j, cnt)
		{
			if (a[j] > 0)
			{
				if (kk < k && a[j] == b[kk])
				{
					if (kk == k - 1)
					{
						ans++;
						tk[tt] = false;
					}
					else
					{
						kk++;
						tk[tt] = true;
					}
				}
				else tk[tt] = false;
				tt++;
			}
			else
			{
				tt--;
				if (tk[tt]) kk--;
			}
		}
		cout << ans << endl;
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}