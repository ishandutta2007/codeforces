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

int n, z;
int a[202400];
i64 t[1 << 19];
i64 b[1 << 19];
char s[10240000];

void tadd(int v, int l, int r, int ll, int rr, int k)
{
	if (l > rr || r < ll) return;
	if (l <= ll && r >= rr)
	{
		b[v] += k;
		return;
	}
	if (b[v])
	{
		b[v*2] += b[v];
		b[v*2+1] += b[v];
		b[v] = 0;
	}
	tadd(v*2, l, r, ll, (ll+rr) >> 1, k);
	tadd(v*2+1, l, r, ((ll+rr) >> 1) + 1, rr, k);

	t[v] = min(t[v*2] + b[v*2], t[v*2+1] + b[v*2+1]);
}

i64 tmin(int v, int l, int r, int ll, int rr)
{
	i64 ans = 0x3f3f3f3f3f3f3f3fLL;
	if (l > rr || r < ll) return ans;
	if (l <= ll && r >= rr)
	{
		return t[v] + b[v];
	}
	if (b[v])
	{
		b[v*2] += b[v];
		b[v*2+1] += b[v];
		b[v] = 0;
	}
	ans = min(ans, tmin(v*2, l, r, ll, (ll+rr) >> 1));
	ans = min(ans, tmin(v*2+1, l, r, ((ll+rr) >> 1) + 1, rr));
	t[v] = min(t[v*2] + b[v*2], t[v*2+1] + b[v*2+1]);

	return ans;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	srand(56756);
	gets(s);
	sscanf(s, "%d", &n);
	gets(s);
	char *h = s;
#define readInt(x) do { int sign = 1; x = 0; while (!isdigit(*h) && *h != '-') h++; if (*h == '-') sign = -1, h++; while (isdigit(*h)) x = x * 10 + *h++ - '0'; x *= sign; } while (0)
	forn(i, n)
	{
		readInt(a[i]);
	}
	memset(t, 0x3f, sizeof(t));
	clr(b);

	z = 1 << 18;

	forn(i, n)
	{
		t[z+i] = a[i];
	}
	Ford(i, z-1, 1)
	{
		t[i] = min(t[i*2], t[i*2+1]);
	}
	gets(s);
	int k;
	sscanf(s, "%d", &k);
	forn(i, k)
	{
		gets(s);
		h = s;
		int x, y;
		readInt(x);
		readInt(y);
		while (*h && (!isdigit(*h) && *h != '-')) h++;

		if (*h)
		{
			int q;
			readInt(q);
			if (x <= y)
			{
				tadd(1, x, y, 0, z-1, q);
			}
			else
			{
				tadd(1, x, n-1, 0, z-1, q);
				tadd(1, 0, y, 0, z-1, q);
			}
		}
		else
		{
			i64 ans = 0x3f3f3f3f3f3f3f3fLL;

			if (x <= y)
			{
				ans = min(ans, tmin(1, x, y, 0, z-1));
			}
			else
			{
				ans = min(ans, tmin(1, x, n-1, 0, z-1));
				ans = min(ans, tmin(1, 0, y, 0, z-1));
			}

			printf("%I64d\n", ans);
		}
	}

	return 0;
}