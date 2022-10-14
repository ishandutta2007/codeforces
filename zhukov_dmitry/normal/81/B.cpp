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

char s[102400];
string a[102400];
int k;

int main()
{
#ifdef ROOM_311
	time_t et_0 = clock();
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	gets(s);
	int n = strlen(s);
	k = 0;
	string t = "";
	forn(i, n)
	{
		t += s[i];
		if (t == "," || t == "..." || (t[0] == ' ' && (i == n-1 || s[i+1] != ' ')) || (isdigit(t[0]) && (i == n-1 || !isdigit(s[i+1]))))
		{
			if (t[0] == ' ') t = " ";
			a[k++] = t;
			t = "";
		}
	}
	string last = "?";
	forn(i, k)
	{
		if (i > 0 && (last[0] == ',' || (last[0] != ' ' && a[i][0] == '.')))
		{
			printf(" ");
			last = " ";
		}
		if (a[i] == " ")
		{
			if ((isdigit(last[0]) && i < n-1 && isdigit(a[i+1][0])) || (last != " " && !isdigit(last[0]) && last[0] != '.'))
			{
				a[i] = " ";
				printf("%s", a[i].c_str());
				last = a[i];
			}
		}
		else
		{
			printf("%s", a[i].c_str());
			last = a[i];
		}
	}
	puts("");

#ifdef ROOM_311
	time_t et_1 = clock();
	fprintf(stderr, "Execution time = %0.0lf ms\n", (et_1 - et_0) * 1000.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}