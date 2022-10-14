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

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int n, m, k, z;
VI a[102400];
int e[202400][2];
VI c[102400];
int ind[102400];
int ans[2024000][4];
bool u[102400];
int u2[102400];
int gg;

bool cmp(int p1, int p2)
{
	return c[p1].sz > c[p2].sz;
}

int nv(int v, int i)
{
	int t = a[v][i];
	if (e[t][0] == v) return e[t][1];
	else return e[t][0];
}

bool findc(int v, int ne, int &v1, int &v2)
{
	u2[v] = 1;

	forn(i, a[v].sz)
	{
		int vn = nv(v, i);
		if (!u2[vn])
		{
			if (findc(vn, a[v][i], v1, v2)) return true;
		}
		else if (u2[vn] == 1 && a[v][i] != ne)
		{
			v1 = v;
			v2 = vn;
			return true;
		}
	}

	u2[v] = 2;

	return false;
}

void dfs0(int v, int k)
{
	u[v] = true;
	c[k].pb(v);
	forn(i, a[v].sz)
	{
		int vn = nv(v, i);
		if (!u[vn])
		{
			dfs0(vn, k);
		}
	}
}

void go(int v);

void dfs(int v)
{
	u[v] = true;
	if (!z || ans[z-1][0] != 0 || ans[z-1][1] != v)
	{
		ans[z][0] = 0;
		ans[z][1] = v;
		z++;
	}
	forn(i, a[v].sz)
	{
		int vn = nv(v, i);
		if (!u[vn])
		{
			dfs(vn);
		}

		if (!z || ans[z-1][0] != 0 || ans[z-1][1] != v)
		{
			ans[z][0] = 0;
			ans[z][1] = v;
			z++;
		}
	}
}

void dfs2(int v, int ne)
{
	u2[v] = 1;

	if (!z || ans[z-1][0] != 0 || ans[z-1][1] != v)
	{
		ans[z][0] = 0;
		ans[z][1] = v;
		z++;
	}

	forn(i, a[v].sz)
	{
		int vn = nv(v, i);
		if (!u2[vn])
		{
			dfs2(vn, a[v][i]);

			if (!z || ans[z-1][0] != 0 || ans[z-1][1] != v)
			{
				ans[z][0] = 0;
				ans[z][1] = v;
				z++;
			}

			gg++;
			if (gg < k)
			{
				ans[z][0] = 1;
				int q = a[v][i];
				ans[z][1] = q;
				ans[z][2] = e[q][0];
				ans[z][3] = e[q][1];
				int v2 = c[ind[gg]][0];
				if (e[q][0] == vn) ans[z][2] = v2;
				else ans[z][3] = v2;
				z++;

				go(v2);

				ans[z][0] = 0;
				ans[z][1] = v;
				z++;
			}
		}
		else if (u2[vn] == 1 && a[v][i] != ne)
		{
			gg++;
			if (gg < k)
			{
				ans[z][0] = 1;
				int q = a[v][i];
				ans[z][1] = q;
				ans[z][2] = e[q][0];
				ans[z][3] = e[q][1];
				int v2 = c[ind[gg]][0];
				if (e[q][0] == vn) ans[z][2] = v2;
				else ans[z][3] = v2;
				z++;

				go(v2);

				ans[z][0] = 0;
				ans[z][1] = v;
				z++;
			}
		}
	}

	u2[v] = 2;
}

void go(int v)
{
	dfs(v);
	dfs2(v, -1);
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[i][0] = x;
		e[i][1] = y;
		a[x].pb(i);
		a[y].pb(i);
	}

	int v1 = -1;
	int v2 = -1;
	clr(u2);
	forn(i, n)
	{
		if (!u2[i])
		{
			if (findc(i, -1, v1, v2)) break;
		}
	}
	clr(u2);


	clr(u);
	k = 0;
	forn(i, n)
	{
		if (!u[i])
		{
			dfs0(i, k);
			k++;
		}
	}

	forn(i, k)
	{
		ind[i] = i;
	}
	sort(ind+1, ind+k, cmp);

	clr(u);
	clr(u2);

	z = 0;
	gg = 0;
	int st = 0;
	if (n > 1 && !a[0].sz)
	{
		forn(i, n)
		{
			if (v1 != -1 && i != v1) continue;
			if (a[i].sz > 1)
			{
				ans[z][0] = 0;
				ans[z][1] = 0;
				z++;

				int t;
				if (v2 != -1)
				{
					t = -1;
					forn(j, a[i].sz)
					{
						int vn = nv(i, j);
						if (vn == v2)
						{
							t = a[i][j];
							For(l, j, a[i].sz - 2)
							{
								a[i][l] = a[i][l+1];
							}
							a[i].pop_back();
							break;
						}
					}
				}
				else
				{
					t = a[i].back();
					a[i].pop_back();
				}
				ans[z][0] = 1;
				ans[z][1] = t;
				ans[z][2] = e[t][0];
				ans[z][3] = e[t][1];
				int q;
				if (e[t][0] == i) ans[z][3] = 0, q = e[t][1];
				else ans[z][2] = 0, q = e[t][0];
				z++;

				forn(j, a[q].sz)
				{
					if (a[q][j] == t)
					{
						For(l, j, a[q].sz - 2)
						{
							a[q][l] = a[q][l+1];
						}
						a[q].pop_back();
						break;
					}
				}
				st = i;

/*				forn(j, n)
				{
					cerr << j << ": ";
					forn(l, a[j].sz)
					{
						cerr << a[j][l] << " ";
					}
					cerr << endl;
				}
				cerr << st << endl;
*/
/*				ans[z][0] = 0;
				ans[z][1] = st;
				z++;
*/
				forn(j, k)
				{
					c[j].clear();
				}
				clr(u);
				k = 0;
				forn(j, n)
				{
					if (!u[j])
					{
						dfs0(j, k);
						k++;
					}
				}

				clr(u);
				clr(u2);

				forn(j, k)
				{
					forn(l, c[j].sz)
					{
						if (c[j][l] == i)
						{
							swap(c[j], c[1]);
							break;
						}
					}
				}
				gg = 1;
				forn(j, k)
				{
					ind[j] = j;
				}
				sort(ind+2, ind+k, cmp);

				u[0] = true;
				u2[0] = 2;

				break;
			}
		}
	}

	go(st);

	forn(i, n)
	{
		if (!u[i])
		{
//			fprintf(stderr, "%d ", i);
			z = -1;
		}
	}

	if (z == -1)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		int cnt = 0;
		forn(i, z)
		{
			if (ans[i][0] == 1)
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
		ans[z][0] = 1;
		forn(i, z)
		{
			int j = i;
			while (!ans[j][0]) j++;

			printf("%d", j - i);
			For(l, i, j - 1)
			{
				printf(" %d", ans[l][1] + 1);
			}
			puts("");

			if (j < z)
			{
				printf("%d %d %d\n", ans[j][1] + 1, ans[j][2] + 1, ans[j][3] + 1);
			}

			i = j;
		}
	}
    
#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}