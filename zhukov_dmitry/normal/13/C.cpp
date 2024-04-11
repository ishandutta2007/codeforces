#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

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

typedef signed   long long i64;

int n, m;
int a[5020];
int ind[5020];
int pa[5020];
int l[5020];
int r[5020];
int b[5020];
i64 ans;
char s[102400];
char ss[102400];

bool cmp(int p1, int p2)
{
	return a[p1] > a[p2];
}

int find(int x)
{
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}

void unite(int x, int y)
{
	if (rand() & 1) swap(x, y);
	pa[x] = y;
	l[y] = min(l[x], l[y]);
	r[y] = max(r[x], r[y]);
}

void go(int x, int cnt)
{
	forn(ii, cnt)
	{
		int v = find(x);
		r[v]++;
		pa[r[v]] = v;
		if (r[v] < m-1 && pa[r[v]+1] != -1)
		{
			unite(v, find(r[v]+1));
			v = find(x);
		}
		
		if (r[v] >= m-1)
		{
			int k = 0;
			For(j, l[v], m-1)
			{
				b[k++] = a[j];
			}
			nth_element(b, b+k/2, b+k);
			int t = b[k/2];
			For(j, l[v], m-1)
			{
				ans += abs(a[j] - t);
			}
			m = l[v];
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	srand(601311);

	int len = 0;
	while (gets(ss))
	{
		int l = strlen(ss);
		forn(i, l)
		{
			s[len++] = ss[i];
		}
		s[len++] = ' ';
	}
	char *h = s;
	n = 0;
	while (isspace(*h)) h++;
	while (!isspace(*h)) n = n * 10 + *h++ - '0';
	forn(i, n)
	{
		while (isspace(*h)) h++;
		int sign = 1;
		if (*h == '-') sign = -1, h++;
		a[i] = 0;
		while (!isspace(*h)) a[i] = a[i] * 10 + *h++ - '0';
		a[i] *= sign;
		ind[i] = i;
		pa[i] = -1;
	}
	sort(ind, ind+n, cmp);

	ans = 0;
	m = n;
	forn(i1, n)
	{
		int i = ind[i1];
		if (i >= m) continue;
		if (i && pa[i-1] != -1)
		{
			go(i-1, 2);
		}
		else if (pa[i] == -1)
		{
			pa[i] = i;
			l[i] = i;
			r[i] = i;
			if (i < m-1 && pa[i+1] != -1)
			{
				unite(find(i), find(i+1));
			}
			go(i, 1);
		}
		else
		{
			go(i, 2);
		}
	}

	printf("%I64d\n", ans);

	return 0;
}