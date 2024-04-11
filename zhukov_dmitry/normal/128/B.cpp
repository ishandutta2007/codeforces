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
#define clrn(x, n) memset(x, 0, (n) * sizeof(x[0]))
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

#define INF 0x7f7f7f7f

const int MAXN = 256000;

int n;
char s[MAXN];
int z;
int buf[MAXN * 8 + 2390];
int bs;

inline bool leq(int a1, int a2, int b1, int b2)
{
	return a1 < b1 || (a1 == b1 && a2 <= b2);
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
	return a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3));
}

void cnt_sort(int *a, int *b, int *r, int n, int k)
{
	int *cnt = buf + bs; bs += k+1;
	clrn(cnt, k+1);

	forn(i, n)
	{
		cnt[r[a[i]]]++;
	}

	for(int i=0, sum=0; i<=k; i++)
	{
		int tmp = cnt[i];
		cnt[i] = sum;
		sum += tmp;
	}

	forn(i, n)
	{
		b[cnt[r[a[i]]]++] = a[i];
	}

	bs -= k+1;
}

void suffix_array(int *s, int *sa, int n, int k)
{
	int n0 = (n+2) / 3, n1 = (n+1) / 3, n2 = n / 3, n02 = n0 + n2;
	int *s0 = buf + bs; bs += n0;
	int *sa0 = buf + bs; bs += n0;
	int *s12 = buf + bs; bs += n02+3; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
	int *sa12 = buf + bs; bs += n02+3; sa12[n02] = sa12[n02+1] = sa12[n02+2] = 0;

	int m = 0;
	forn(i, n+n0-n1)
	{
		if (i % 3)
		{
			s12[m++] = i;
		}
	}

	cnt_sort(s12, sa12, s+2, n02, k);
	cnt_sort(sa12, s12, s+1, n02, k);
	cnt_sort(s12, sa12, s  , n02, k);

	m = 0;
	int c0 = -1, c1 = -1, c2 = -1;
	forn(i, n02)
	{
		if (s[sa12[i]] != c0 || s[sa12[i]+1] != c1 || s[sa12[i]+2] != c2)
		{
			m++;
			c0 = s[sa12[i]];
			c1 = s[sa12[i]+1];
			c2 = s[sa12[i]+2];
		}
		if (sa12[i] % 3 == 1)
		{
			s12[sa12[i] / 3] = m;
		}
		else
		{
			s12[sa12[i] / 3 + n0] = m;
		}
	}

	if (m != n02)
	{
		suffix_array(s12, sa12, n02, m);
		forn(i, n02)
		{
			s12[sa12[i]] = i + 1;
		}
	}
	else
	{
		forn(i, n02)
		{
			sa12[s12[i] - 1] = i;
		}
	}

	m = 0;
	forn(i, n02)
	{
		if (sa12[i] < n0)
		{
			s0[m++] = sa12[i] * 3;
		}
	}

	cnt_sort(s0, sa0, s, n0, k);

	int p = 0;
	int t = n0 - n1;
#define geti() (sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2)
	forn(z, n)
	{
		int i = geti();
		int j = sa0[p];
		if (sa12[t] < n0 ? leq(s[i], s12[sa12[t]+n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[sa12[t]-n0+1], s[j], s[j+1], s12[j/3 + n0]))
		{
			sa[z] = i;
			t++;
			if (t == n02)
			{
				for(z++; p<n0; p++, z++)
				{
					sa[z] = sa0[p];
				}
			}
		}
		else
		{
			sa[z] = j;
			p++;
			if (p == n0)
			{
				for(z++; t<n02; t++, z++)
				{
					sa[z] = geti();
				}
			}
		}
	}

	bs -= n02+3; 	
	bs -= n02+3;	
	bs -= n0;     
	bs -= n0;    	
}

void suff_arr(char *s, int *sa, int n)
{
	int *a = buf + bs; bs += n+3;
	a[n] = a[n+1] = a[n+2] = 0;
	forn(i, n)
	{
		a[i] = (unsigned char)s[i];
	}

	suffix_array(a, sa, n, 128);

	bs -= n+3;
}

void calc_lcp(char *s, int *sa, int *pa, int n, int *lcp)
{
	forn(i, n)
	{
		int j = pa[i];
		if (j == n-1) lcp[pa[i]] = 0;
		else
		{
			int x = (i ? max(lcp[pa[i-1]] - 1, 0) : 0);
			j = sa[j+1];
			while (s[i+x] == s[j+x]) x++;
			lcp[pa[i]] = x;
		}
	}
}

bool go(int *sa, int p, int l, int r, int &k)
{
	if (s[sa[l] + p] == '\0') l++;
	if (l > r) return false;
	int last = l;
	For(i, l, r - 1)
	{
		if (s[sa[i] + p] != s[sa[i + 1] + p])
		{
			if (go(sa, p, last, i, k)) return true;
			last = i + 1;
		}
	}
	if (last != l)
	{
		if (go(sa, p, last, r, k)) return true;
	}
	else
	{
		For(i, l, r)
		{
			if (s[sa[i] + p] != '\0')
			{
				if (!k)
				{
					forn(j, p + 1)
					{
						putchar(s[sa[i] + j]);
					}
					puts("");
					return true;
				}
				k--;
			}
		}
		if (go(sa, p + 1, last, r, k)) return true;
	}
	return false;
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%s", s);
	int k;
	scanf("%d", &k);
	n = strlen(s);

	bs = 0;

	int *sa = buf + bs; bs += n;
	suff_arr(s, sa, n);
	int *pa = buf + bs; bs += n;
	forn(i, n)
	{
		pa[sa[i]] = i;
	}
/*	int *lcp = buf + bs; bs += n;
	calc_lcp(s, sa, pa, n, lcp);

	forn(i, n)
	{
		printf("%s %d\n", s + sa[i], lcp[i]);
	}
*/
	bs -= n;
	bs -= n;
	bs -= n;

	k--;
	if (!go(sa, 0, 0, n-1, k)) puts("No such line.");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}