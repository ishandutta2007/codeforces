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

const int SHAMANIC = 6061;

struct tp{int x,y;};

bool operator < (tp p1, tp p2)
{
	return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

bool operator == (tp p1, tp p2)
{
	return p1.y == p2.y && p1.x == p2.x;
}

int n, k, m;
tp a[202400];
int e[202400][4];
char s[1024];
int xx[202400];
int yy[202400];
bool c[202400];
tp ps[202400];
int ind[202400];
int d[202400];
tp ans[202400];
tp pp[202400];
int d2[202400];

int t1[1 << 19];
int t2[1 << 19];
int z;

void tadd(int x, int y)
{
	int y0 = y;
	y += z;
	while (y)
	{
		if (t1[y] < x || (t1[y] == x && t2[y] < y0))
		{
			t1[y] = x;
			t2[y] = y0;
		}
		y >>= 1;
	}
}

void tmax(int x, int &ansx, int &ansy)
{
	ansx = ansy = -1;
	int l = z;
	int r = z + x;
	while (l <= r)
	{
		if (l & 1)
		{
			if (t1[l] > ansx || (t1[l] == ansx && t2[l] > ansy))
			{
				ansx = t1[l];
				ansy = t2[l];
			}
		}
		if (!(r & 1))
		{
			if (t1[r] > ansx || (t1[r] == ansx && t2[r] > ansy))
			{
				ansx = t1[r];
				ansy = t2[r];
			}
		}
		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}
}

bool cmpi(int p1, int p2)
{
	if (ps[p1].x != ps[p2].x) return ps[p1].x < ps[p2].x;
	return ps[p1].y > ps[p2].y;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &k);
	forn(i, k)
	{
		tp p;
		scanf("%s%d%d", s, &p.x, &p.y);
		p.x *= -1;
		p.y *= -1;
		if (*s == 'a') e[i][0] = 1;
		if (*s == 'r') e[i][0] = -1;
		if (*s == 'f') e[i][0] = 0;
		a[i] = p;
		xx[i] = p.x;
		yy[i] = p.y;
	}
	while (k % SHAMANIC != 0)
	{
		e[k][0] = 1;
		tp p;
		p.x = -1000000003;
		p.y = -1000000003 - k;
		a[k] = p;
		xx[k] = p.x;
		yy[k] = p.y;
		k++;
	}
	m = k;
	sort(xx, xx+k);
	sort(yy, yy+k);
	forn(i, k)
	{
		a[i].x = lower_bound(xx, xx+k, a[i].x) - xx;
		a[i].y = lower_bound(yy, yy+k, a[i].y) - yy;
		e[i][1] = a[i].x;
		e[i][2] = a[i].y;
	}

	sort(a, a+k);
	n = unique(a, a+k) - a;
	clr(c);
	z = 1;
	while (z < k) z <<= 1;

	forn(i, k / SHAMANIC)
	{
		int cnt = 0;
		forn(j, SHAMANIC)
		{
			int t = i * SHAMANIC + j;

			if (e[t][0] == -1)
			{
				tp p;
				p.x = e[t][1];
				p.y = e[t][2];
				int x = lower_bound(a, a+n, p) - a;
				if (c[x])
				{
					c[x] = false;
					pp[cnt++] = a[x];
				}
			}
		}

		memset(t1, 0xff, (z + k) * sizeof(t1[0]));
		int kk = 0;
		forn(j, SHAMANIC)
		{
			int t = i * SHAMANIC + j;
			ans[t].x = -1;
			ans[t].y = -1;
			if (e[t][0] == 0)
			{
				ps[kk].x = e[t][1];
				ps[kk].y = e[t][2];
				d[kk] = 0;
				d2[kk] = t;
				ind[kk] = kk;
				kk++;
			}
		}
		forn(j, n)
		{
			if (c[j])
			{
				ps[kk].x = a[j].x;
				ps[kk].y = a[j].y;
				d[kk] = 1;
				ind[kk] = kk;
				kk++;
			}
		}
		sort(ind, ind+kk, cmpi);
		forn(j1, kk)
		{
			int j = ind[j1];
			if (d[j] == 0)
			{
				int tx, ty;
				tmax(ps[j].y - 1, tx, ty);
				if (tx != -1)
				{
					ans[d2[j]].x = tx;
					ans[d2[j]].y = ty;
				}
			}
			else
			{
				tadd(ps[j].x, ps[j].y);
			}
		}

		sort(pp, pp+cnt);
		forn(j, SHAMANIC)
		{
			int t = i * SHAMANIC + j;
			tp p;
			p.x = e[t][1];
			p.y = e[t][2];
			if (e[t][0] == 0)
			{
				forn(l, cnt)
				{
					if (pp[l].y >= p.y) break;
					if (pp[l].x < p.x)
					{
						if (pp[l].x > ans[t].x || (pp[l].x == ans[t].x && pp[l].y > ans[t].y))
						{
							ans[t] = pp[l];
						}
					}
				}

				if (ans[t].x == -1)
				{
					puts("-1");
				}
				else
				{
					printf("%d %d\n", -xx[ans[t].x], -yy[ans[t].y]);
				}
			}
			else if (e[t][0] == 1)
			{
				pp[cnt++] = p;
				int r = cnt-1;
				while (r && pp[r] < pp[r-1])
				{
					swap(pp[r], pp[r-1]);
					r--;
				}
			}
			else
			{
				forn(l, cnt)
				{
					if (pp[l] == p)
					{
						cnt--;
						For(r, l, cnt-1)
						{
							pp[r] = pp[r+1];
						}
						l--;
					}
				}
			}
		}

		forn(j, SHAMANIC)
		{
			int t = i * SHAMANIC + j;
			tp p;
			p.x = e[t][1];
			p.y = e[t][2];
			if (e[t][0] == 0) continue;

			int x = lower_bound(a, a+n, p) - a;
			if (e[t][0] == 1)
			{
				c[x] = true;
			}
			else
			{
				c[x] = false;
			}
		}
	}

	return 0;
}