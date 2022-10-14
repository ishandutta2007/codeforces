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

int n, m, k;
int t[102400];
int x[102400];
int ind[102400];
int ind2[102400];
int ans[102400];

bool cmp(int p1, int p2)
{
	return t[p1] < t[p2];
}

bool cmp2(int p1, int p2)
{
	return x[p1] < x[p2];
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d", &n, &m);
	forn(i, n)
	{
		scanf("%d%d", &t[i], &x[i]);
		ind[i] = i;
	}
	sort(ind, ind+n, cmp);
	int cur = 0;
	k = 0;
	forn(i1, n)
	{
		int i = ind[i1];
		if (t[i] > cur) cur = t[i];
		ind2[k++] = i;
		if (i1 == n - 1 || k == m)
		{
			sort(ind2, ind2 + k, cmp2);
			int add = 0;
			forn(l1, k)
			{
				int l = ind2[l1];
				int j1 = l1;
				while (j1 + 1 < k && x[ind2[j1 + 1]] == x[l]) j1++;
				
				For(p1, l1, j1)
				{
					int p = ind2[p1];
					ans[p] = cur + add + x[p];
				}
				add += (j1 - l1 + 1) / 2 + 1;
				l1 = j1;
			}
			cur += add + x[ind2[k - 1]] * 2;
			k = 0;
		}
	}
	forn(i, n)
	{
		printf("%d%c", ans[i], " \n"[i == n - 1]);
	}
	
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}