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

int n;
char s[2024000];
char s3[2024000];
char s2[2024000];
int a[1024000];
bool b[1024000];

void solve(char *s, int n, int &ansp, int &ansq)
{
	int m = 0;
	forn(i, n)
	{
		if (i && s[i] != 'X' && s[i] == s[i-1]) s2[m++] = 'X';
		s2[m++] = s[i];
	}
	forn(i, m)
	{
		s[i] = s2[i];
	}
	n = m;

	int k = 0;
	int st = -1;
	forn(i, n)
	{
		if (s[i] != 'X')
		{
			if (st == -1) st = i;
		}
		else
		{
			if (st != -1)
			{
				a[k] = i - st;
				b[k] = (s[st] == 'L') != (st & 1);
				k++;
				st = -1;
			}
		}
	}
	if (st != -1)
	{
		a[k] = n - st;
		b[k] = (s[st] == 'L') != (st & 1);
		k++;
		st = -1;
	}
	m = 0;
	forn(i, k)
	{
		if (m && b[i] == b[m-1])
		{
			a[m-1] += a[i];
		}
		else
		{
			a[m] = a[i];
			b[m] = b[i];
			m++;
		}
	}
	k = m;
	if (!k)
	{
		ansp = 0;
		ansq = 1;
		return;
	}

	ansp = 0;
	ansq = n;
	forn(i, k)
	{
		if (b[i]) ansp += a[i];
	}
	if (ansq & 1)
	{
		int s = 0;
		int ma = 0;
		int mj = -1;
		ford(i, k)
		{
			if (!b[i])
			{
				s += a[i];
			}
			else
			{
				s -= a[i];
			}
			if (s > ma)
			{
				ma = s;
				mj = i;
			}
		}
		if (ma >= 1)
		{
			ansp += ma;
			ansq += 1;
			if (mj)
			{
				a[mj-1] += a[mj];
				k--;
				For(j, mj, k-1)
				{
					a[j] = a[j+1];
				}
			}
			else
			{
				For(j, mj, k-1)
				{
					b[j] = !b[j];
				}
			}
		}
		ansq += ansq & 1;
	}

	forn(i, k)
	{
		if (a[i] > 1 && !b[i])
		{
			ansp += a[i];
			ansq += 2;
		}
	}

	if (ansp * 2 > ansq)
	{
		bool r = false;
		forn(i, k)
		{
			if (i && a[i-1] > 1 && a[i] == 1 && b[i])
			{
				r = true;
			}
			if (r && a[i] > 1 && !b[i])
			{
				ansp -= 1;
				ansq -= 2;
			}
			r = r && a[i] == 1;
		}
	}
	else
	{
		forn(i, k)
		{
			if (a[i] == 1 && !b[i])
			{
				ansp += 1;
				ansq += 2;
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

	gets(s);
	n = strlen(s);
	int ansp = 0;
	int ansq = 0;
	if (s[0] != 'X' && s[n-1] == s[0])
	{
		forn(i, n)
		{
			s3[i] = s[i];
		}
		s3[n] = 'X';
		solve(s3, n+1, ansp, ansq);
		forn(i, n)
		{
			s3[i+1] = s[i];
		}
		s3[0] = 'X';
		int p, q;
		solve(s3, n+1, p, q);
		if (p * ansq > ansp * q)
		{
			ansp = p;
			ansq = q;
		}
	}
	else
	{
		solve(s, n, ansp, ansq);
	}

//	cerr << k << endl;
//	cerr << ansp << " " << ansq << endl;

//	printf("%0.6lf\n", ansp * 100.0 / ansq);
	printf("%d.%06d\n", ansp * 100 / ansq, (int)(((i64)ansp * 100000000 / ansq) - (i64)ansp * 100 / ansq * 1000000));

	return 0;
}