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

int n, m;
int c[10240];
int a[20240];
int b[20240];
int an[20240];
int bn[20240];
int col[10240];
int col2[10240];
int q[10240];
int qb, qe;
int e[10240][2];
int ans[10240];
int ind[10240];
int u[10240];

bool bfs(int k, int cc, int c2)
{
	qb = qe = 0;
	col[k] = cc;
	col2[k] = c2;
	q[qe++] = k;

	while (qb != qe)
	{
		k = q[qb++];
//		k = q[--qe];
		int *aa = a + c[k];
		int cnt = c[k+1] - c[k];
		while (cnt--)
		{
			int i = *aa++;
			if (col[i] == -1)
			{
				col[i] = 1 - col[k];
				col2[i] = c2;
				q[qe++] = i;
			}
			else if (col[i] != 1 - col[k])
			{
				return false;
			}
		}
	}
	return true;
}

bool check()
{
	memset(col, 0xff, sizeof(col));
	int cnt = 0;
	forn(j, n)
	{
		if (col[j] == -1)
		{
			if (!bfs(j, 0, cnt)) return false;
			cnt++;
		}
	}
	return true;
}

bool cmp(int p1, int p2)
{
	return a[p1] < a[p2];
}

void bebebe(int k, int i1, int i2)
{
	int x1 = a[i1];
	int x2 = a[i2];
	int j1 = lower_bound(a+c[x1], a + c[x1+1], k) - a;
	int j2 = lower_bound(a+c[x2], a + c[x2+1], k) - a;
	a[i1] = n;
	a[j1] = n+1;
	a[i2] = n+2;
	a[j2] = n+3;
	bool bb = check();
	if (!bb)
	{
		ans[b[i1]] = ans[b[i2]] = 0;
	}
	else
	{
		ans[b[i2]] = (col2[k] != col2[x1] || col[k] != col[x1]);
		ans[b[i1]] = (col2[k] != col2[x2] || col[k] != col[x2]);
	}
	a[i1] = x1;
	a[i2] = x2;
	a[j1] = k;
	a[j2] = k;
}

void rec(int k, int pa, int &t)
{
	u[k] = 1;
	int tt = 0;
	int v1 = -1;
	for(int i1 = c[k]; i1 < c[k+1]; i1++)
	{
		int i = a[i1];
		if (!u[i])
		{
			rec(i, k, an[i1]);
			if (/*an[i1]*/ans[b[i1]] == -1)
			{
				if (!tt)
				{
					v1 = i1;
					tt = 1;
				}
				else
				{
					bebebe(k, i1, v1);
					tt = 0;
				}
			}
		}
		else if (u[i] == 1 && i != pa)
		{
			if (!tt)
			{
				v1 = i1;
				tt = 1;
			}
			else
			{
				bebebe(k, i1, v1);
				tt = 0;
			}
		}
	}
	if (pa != -1 && tt == 1)
	{
		for(int i1 = c[k]; i1 < c[k+1]; i1++)
		{
			if (a[i1] == pa)
			{
				bebebe(k, i1, v1);
				tt = 0;
				break;
			}
		}
		t = 0;
	}
	else
	{
		if (pa == -1) t = tt;
		else t = 1;
	}
	u[k] = 2;
}

void calc(int k)
{
	int t = 0;
	rec(k, -1, t);
	if (t)
	{
		for(int i1 = c[k]; i1 < c[k+1]; i1++)
		{
			int i = b[i1];
			if (ans[i] == -1)
			{
				int xx = e[i][0];
				int yy = e[i][1];
				int i1 = lower_bound(a+c[xx], a + c[xx+1], yy) - a;
				int i2 = lower_bound(a+c[yy], a + c[yy+1], xx) - a;
				a[i1] = n;
				a[i2] = n+1;
				ans[i] = check();
				a[i1] = yy;
				a[i2] = xx;
				break;
			}
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	clr(c);
	forn(i, m)
	{
		scanf("%d%d", &e[i][0], &e[i][1]);
		e[i][0]--;
		e[i][1]--;
		c[e[i][0]]++;
		c[e[i][1]]++;
	}

	for(int sum = 0, i = 0; i <= n; i++)
	{
		int tmp = sum;
		sum += c[i];
		c[i] = tmp;
	}

	forn(i, m)
	{
		b[c[e[i][0]]] = i;
		a[c[e[i][0]]++] = e[i][1];
		b[c[e[i][1]]] = i;
		a[c[e[i][1]]++] = e[i][0];
	}
	ford(i, n)
	{
		c[i+1] = c[i];
	}
	c[0] = 0;
	forn(i, n)
	{
		int cnt = c[i+1] - c[i];
		forn(j, cnt)
		{
			ind[j] = c[i] + j;
		}
		sort(ind, ind+cnt, cmp);
		forn(j, cnt)
		{
			an[c[i] + j] = a[ind[j]];
			bn[c[i] + j] = b[ind[j]];
		}
	}
	forn(i, c[n])
	{
		a[i] = an[i];
		b[i] = bn[i];
	}
	c[n+1] = c[n+2] = c[n+3] = c[n+4] = c[n];
	forn(i, m)
	{
		ans[i] = 1;
	}
	if (!check())
	{
		memset(ans, 0xff, sizeof(ans));
		clr(u);
		forn(i, n)
		{
			if (!u[i])
			{
				calc(i);
			}
		}
	}

	int k = 0;
	forn(i, m)
	{
		k += ans[i];
//		if (ans[i] == -1) for(;;);
	}
	printf("%d\n", k);
	bool f = true;
	forn(i, m)
	{
		if (ans[i])
		{
			if (!f) putchar(' ');
			f = false;
			printf("%d", i+1);
		}
	}
	puts("");

	return 0;
}