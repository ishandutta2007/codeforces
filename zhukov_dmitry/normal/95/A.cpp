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

int n;
char a[128][128];
char a1[128][128];
char s[128];
char s1[128];
char s0[128];
bool b[128];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	while (scanf("%d", &n) == 1)
	{
		forn(i, n)
		{
			scanf("%s", a[i]);
		}
		scanf("%s", s);
		scanf("%s", s0);
		memcpy(a1, a, sizeof(a));
		memcpy(s1, s, sizeof(s));
		clr(b);
		int l = strlen(s);
		forn(i, l)
		{
			s[i] = tolower(s[i]);
		}
		forn(i, n)
		{
			int li = strlen(a[i]);
			forn(j, li)
			{
				a[i][j] = tolower(a[i][j]);
			}
		}
		forn(i, n)
		{
			int li = strlen(a[i]);
			forn(j, l)
			{
				if (!strncmp(s+j, a[i], li))
				{
					forn(k, li)
					{
						b[j+k] = true;
					}
				}
			}
		}
		memcpy(a, a1, sizeof(a));
		memcpy(s, s1, sizeof(s));
		forn(i, l)
		{
			if (b[i])
			{
				char cc = tolower(s[i]);
				if (cc != *s0) s[i] += *s0 - cc;
				else if (cc != 'a') s[i] += 'a' - cc;
				else s[i] += 'b' - cc;
			}
		}
		puts(s);
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}