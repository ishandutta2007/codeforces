#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int INF = 0x3f3f3f3f;

int n, k;
int a[26][26];
char s1[102400];
char s2[102400];
char s[102400];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	memset(a, 0x3f, sizeof(a));
	scanf("%s%s", s1, s2);
	n = strlen(s1);
	if (strlen(s2) != n)
	{
		puts("-1");
		return 0;
	}
	scanf("%d", &k);
	forn(i, k)
	{
		char c1, c2;
		int x, y, z;
		scanf(" %c %c%d", &c1, &c2, &z);
		x = c1 - 'a';
		y = c2 - 'a';
		a[x][y] = min(a[x][y], z);
	}
	forn(i, 26)
	{
		a[i][i] = 0;
	}
	forn(k, 26)
	{
		forn(i, 26)
		{
			forn(j, 26)
			{
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	
	int ans = 0;
	forn(i, n)
	{
		int c1 = s1[i] - 'a';
		int c2 = s2[i] - 'a';
		s[i] = ' ';
		int mi = INF;
		int mj = -1;
		forn(j, 26)
		{
			if (a[c1][j] + a[c2][j] < mi)
			{
				mi = a[c1][j] + a[c2][j];
				mj = j;
			}
		}
		if (mj == -1)
		{
			puts("-1");
			return 0;
		}
		ans += mi;
		s[i] = mj + 'a';
	}

	printf("%d\n", ans);
	s[n] = '\0';
	puts(s);

	return 0;
}