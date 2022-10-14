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

int n;
char a[10240];
i64 q[1024];
i64 qn[1024];

i64 tuda(int *x)
{
	i64 z = 0;
	forn(i, 4)
	{
		z = z * 20000 + x[i];
	}
	return z;
}

void ottuda(i64 z, int *x)
{
	ford(i, 4)
	{
		x[i] = z % 20000;
		z /= 20000;
	}
}

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	string s = "GHRS";
	scanf("%d%s", &n, a);
	int t[4] = {0};
	int k = 0;
	q[k++] = tuda(t);
	forn(i, n)
	{
		int kn = 0;
		int c = (a[i] == '?') ? -1 : (find(s.begin(), s.end(), a[i]) - s.begin());

		forn(j, k)
		{
			ottuda(q[j], t);
			if (c == -1)
			{
				int mi = 200000;
				forn(l, 4)
				{
					if (t[l] < mi) mi = t[l];
				}
				forn(l, 4)
				{
					if (t[l] == mi)
					{
						t[l]++;
						i64 z = tuda(t);
						qn[kn++] = z;
						t[l]--;
					}
				}
			}
			else
			{
				t[c]++;
				i64 z = tuda(t);
				qn[kn++] = z;
			}
		}

		k = kn;
		memcpy(q, qn, k * sizeof(q[0]));
		sort(q, q+k);
		k = unique(q, q+k) - q;
	}

	bool w[4] = {0};
	forn(j, k)
	{
		ottuda(q[j], t);
		int mi = 200000;
		forn(l, 4)
		{
			if (t[l] < mi) mi = t[l];
		}
		forn(l, 4)
		{
			if (t[l] == mi)
			{
				w[l] = true;
			}
		}
	}

	string ans[4] = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};

	forn(i, 4)
	{
		if (w[i])
		{
			puts(ans[i].c_str());
		}
	}

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}