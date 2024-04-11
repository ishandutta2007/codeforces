#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

#ifdef ROOM_311
__attribute__((destructor)) void fini_main()
{
	fprintf(stderr, "Execution time = %0.0lf ms\n", clock() * 1000.0 / CLOCKS_PER_SEC);
}
#endif

#define MY_RAND 1
#if MY_RAND
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() { rnd_data = rnd_data * 0x5DEECE66DULL + 0xB; return (rnd_data >> 17) & 0x7FFFFFFF; }
#define rand my_rand
#define srand my_srand
template <typename T> void my_random_shuffle(T b, T e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uin(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(b, a) ? a = b, true : false; }
template<typename type_t, typename less_t = std::less<type_t>> inline bool uax(type_t &a, const type_t &b, const less_t &ls = less_t()) { return ls(a, b) ? a = b, true : false; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

int n;
char s1[1024000];
char s2[1024000];
int a[2][1024000];
int d[1024000][2];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	scanf("%s%s", s1, s2);
	forn(i, n)
	{
		a[0][i] = s1[i] == '1';
		a[1][i] = s2[i] == '1';
//		cerr << a[0][i] << " " << a[1][i] << endl;
	}
	memset(d, 0x3f, sizeof(d));
	d[0][0] = a[0][0] != 0;
	d[0][1] = a[0][0] != 1;
	For(i, 1, n - 1)
	{
		uin(d[i][0], d[i - 1][a[1][i - 1]] + (a[0][i] != 0));
		uin(d[i][1], d[i - 1][a[1][i - 1]] + (a[0][i] != 1));
		if (a[0][i] == a[1][i - 1])
		{
			uin(d[i][0], d[i - 1][0] + 1);
			uin(d[i][1], d[i - 1][1] + 1);
		}
	}
/*	forn(i, n)
	{
		cerr << i << " " << d[i][0] << " " << d[i][1] << endl;
	}*/
	int ans = d[n - 1][a[1][n - 1]];
	printf("%d\n", ans);
	
	return 0;
}