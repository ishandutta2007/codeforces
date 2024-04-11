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

char s[2000];

int main()
{
#ifdef ROOM_311
//	freopen("input.txt", "rt", stdin);
#endif
	
	int p[10];
	forn(i, 10)
	{
		p[i] = i;
	}
//	srand(1254);
//	random_shuffle(p, p + 10);
	int cnt = 0;
	forn(ii, 10)
	{
//		while (clock() * 1000.0 / CLOCKS_PER_SEC < 50 * (ii + 1));
		int i = p[ii];
		printf("%d\n", i);
		fflush(stdout);
		fgets(s, sizeof(s), stdin);
		s[strlen(s) - 1] = '\0';
		int len = strlen(s);
		string h;
		forn(i, len)
		{
			if (isalpha(s[i])) h += s[i];
		}
		strcpy(s, h.c_str());
/*		forn(i, len)
		{
			if (s[i] == '\'') for(;;);
			if (s[i] == '?') for(;;);
			if (s[i] == '!') for(;;);
		}*/
		if (!strcmp(s, "no"))
		{
			cnt++;
			if (cnt > 3)
			{
				puts("normal");
				return 0;
			}
			continue;
		}
		if (
/*			!strcmp(s, "great!") ||
			!strcmp(s, "don't think so") ||
			!strcmp(s, "not bad") ||
			!strcmp(s, "cool") ||
			!strcmp(s, "don't touch me!")*/
			!strcmp(s, "great") ||
			!strcmp(s, "dontthinkso") ||
			!strcmp(s, "notbad") ||
			!strcmp(s, "cool") ||
			!strcmp(s, "donttouchme")
		) {
/*			size_t size = 10000000 * (ii + 1);
			char *b = new char[size];
			int sum = 0;
			memset(b, 0xff, size);
			forn(i, size)
			{
				sum += b[i];
			}
			cerr << sum << endl;
*/
			puts("normal");
		}
		else if (
/*			!strcmp(s, "are you serious?") ||
			!strcmp(s, "don't even") ||
			!strcmp(s, "worse") ||
			!strcmp(s, "terrible") ||
			!strcmp(s, "go die in a hole") ||
			!strcmp(s, "no way")*/
			!strcmp(s, "areyouserious") ||
			!strcmp(s, "donteven") ||
			!strcmp(s, "worse") ||
			!strcmp(s, "terrible") ||
			!strcmp(s, "godieinahole") ||
			!strcmp(s, "noway")
		) {
/*			size_t size = 40000000 * (ii + 1);
			char *b = new char[size];
			int sum = 0;
			memset(b, 0xff, size);
			forn(i, size)
			{
				sum += b[i];
			}
			cerr << sum << endl;
*/
			puts("grumpy");
		}
		else
		{
/*			int len = strlen(s);
			forn(i, len)
			{
				if (s[i] == '\'') exit(239);
			}*/
//			puts("grumpy");
//			return 0;
			for(;;);
		}
		return 0;
	}
	
	return 0;
}