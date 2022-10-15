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

int qq;
char s[10240];
int p26[10];

void precalc()
{
	p26[0] = 1;
	For(i, 1, 6)
	{
		p26[i] = p26[i-1] * 26;
	}
}

void solve1(char *s)
{
	int l = strlen(s);
	int x = 0;
	int y = 0;
	forn(i, l)
	{
		if (isdigit(s[i]))
		{
			sscanf(s+i, "%d", &x);
			int t = 0;
			forn(j, i)
			{
				t = t * 26 + (s[j] - 'A');
			}
			y += t;
			break;
		}
		y += p26[i];
	}
	printf("R%dC%d\n", x, y);
}

void solve2(char *s)
{
	int l = strlen(s);
	int x = 0;
	int y = 0;
	forn(i, l)
	{
		if (s[i] == 'R')
		{
			sscanf(s+i+1, "%d", &x);
		}
		if (s[i] == 'C')
		{
			sscanf(s+i+1, "%d", &y);
			y--;
		}
	}

	l = 1;
	while (y >= p26[l]) y -= p26[l], l++;
	char t[8];
	ford(i, l)
	{
		t[i] = y % 26 + 'A';
		y /= 26;
	}
	t[l] = '\0';

	printf("%s%d\n", t, x);
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	precalc();

	scanf("%d", &qq);
	forn(i, qq)
	{
		scanf("%s", s);
		int cnt = 0;
		int l = strlen(s);
		forn(j, l - 1)
		{
			cnt += !isdigit(s[j]) && isdigit(s[j+1]);
		}
		if (cnt == 1) solve1(s);
		else solve2(s);
	}

	return 0;
}