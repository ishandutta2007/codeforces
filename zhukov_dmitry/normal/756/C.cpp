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
template <typename T> void my_random_shuffle(T *b, T *e) { For(i, 1, (int)(e - b) - 1) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

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

const int DIV = 320;

struct tnode
{
	int sum;
	int ma;
};

int n, m;
int b[1024000][3];
int a[1024000];
int sign[1024000];
tnode s[1024000 / DIV + 1];

void add(int idx)
{
	int x = b[idx][0];
	a[x] = idx;
	sign[x] = b[idx][1];
	s[x / DIV].sum += b[idx][1];
	int &ma = s[x / DIV].ma;
	int sum = 0;
	ma = 0;
	int z = x / DIV * DIV;
	ford(i, DIV)
	{
		sum += sign[z + i];
		if (sum > ma) ma = sum;
	}
}

int solve()
{
	int sum = 0;
	ford(i, m)
	{
		if (sum + s[i].ma <= 0)
		{
			sum += s[i].sum;
			continue;
		}
		int z = i * DIV;
		ford(j, DIV)
		{
			sum += sign[z + j];
			if (sum > 0)
			{
				return b[a[z + j]][2];
			}
		}
	}
	return -1;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d", &n);
	m = (n + DIV - 1) / DIV;
	clr(s);
	clr(sign);
	forn(i, n)
	{
		scanf("%d%d", &b[i][0], &b[i][1]);
		if (b[i][1] == 1) scanf("%d", &b[i][2]);
		else b[i][1] = -1;
		b[i][0]--;
	}
	forn(i, n)
	{
		add(i);
		int ans = solve();
		printf("%d\n", ans);
	}
	
	return 0;
}