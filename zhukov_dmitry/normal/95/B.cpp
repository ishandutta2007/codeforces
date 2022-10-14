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

char s[1024000];
int a[1024000];
int n;
char ans[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	time_t et_0 = clock();
#else
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s", s);
	n = strlen(s);
	forn(i, n)
	{
		a[i] = s[i] - '0';
	}
	if (n % 2 == 1)
	{
		int k = n / 2 + 1;
		forn(i, k)
		{
			putchar('4');
		}
		forn(i, k)
		{
			putchar('7');
		}
		puts("");
		return 0;
	}
	clr(ans);
	
	int k4 = 0;
	int k7 = 0;
	forn(i, n)
	{
		k4 += a[i] == 4;
		k7 += a[i] == 7;
	}
	int k = n / 2;
	int bb = 0;
	forn(i, k)
	{
		if (a[i] > 7)
		{
			bb = 1;
			break;
		}
		if (a[i] < 7)
		{
			bb = -1;
			break;
		}
	}
	if (!bb)
	forn(i, k)
	{
		if (a[k+i] > 4)
		{
			bb = 1;
			break;
		}
		if (a[k+i] < 4)
		{
			bb = -1;
			break;
		}
	}
	if (bb == 1)
	{
		k++;
		forn(i, k)
		{
			putchar('4');
		}
		forn(i, k)
		{
			putchar('7');
		}
		puts("");
		return 0;
	}
	if (!bb)
	{
		k4 = 0;
		k7 = 0;
		forn(i, n)
		{
			k4 += s[i] == '4';
			k7 += s[i] == '7';
		}
		if (k4 != k7) for(;;);
		puts(s);
		return 0;
	}
	forn(i, n)
	{
		ans[i] = '4';
	}
	k4 = 0;
	k7 = 0;
	bb = 0;
	forn(i, n)
	{
		if (bb)
		{
			if (k4 < k)
			{
				ans[i] = '4';
				k4++;
			}
			else
			{
				ans[i] = '7';
				k7++;
			}
		}
		else if (a[i] < 4 && k4 < k)
		{
			ans[i] = '4';
			bb = 1;
			k4++;
		}
		else if (a[i] == 4 && k4 < k)
		{
			ans[i] = '4';
			k4++;
		}
		else if (a[i] < 7 && k7 < k)
		{
			ans[i] = '7';
			bb = 1;
			k7++;
		}
		else if (a[i] == 7 && k7 < k)
		{
			ans[i] = '7';
			k7++;
		}
		else
		{
			int j = i - 1;
			while (ans[j] == '7' || k7 == k)
			{
				k7 -= ans[j] == '7';
				j--;
			}
			ans[j++] = '7';
			k4 = k7 = 0;
			forn(l, j)
			{
				k4 += ans[l] == '4';
				k7 += ans[l] == '7';
			}
			while (j < n)
			{
				if (k4 < k)
				{
					ans[j] = '4';
					k4++;
				}
				else
				{
					ans[j] = '7';
					k7++;
				}
				j++;
			}
			bb = 1;
			break;
		}
	}
	k4 = 0;
	k7 = 0;
	forn(i, n)
	{
		k4 += ans[i] == '4';
		k7 += ans[i] == '7';
	}
	if (k4 != k7) for(;;);
	puts(ans);

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}