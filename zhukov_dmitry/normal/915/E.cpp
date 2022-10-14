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
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

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
template <typename T> void my_random_shuffle(T b, T e) { for(ssize_t i = 1; i < (e - b); i++) { swap(b[i], b[rand() % (i + 1)]); } }
#define random_shuffle my_random_shuffle
#endif

template <class _T> inline _T sqr(const _T &x) { return x * x; }

// Types
typedef long double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

const int MAXN = 302400;

struct tnode
{
	int all = -1;
	int sum = 0;
};

int n, m, k;
int b[MAXN][3];
const int z = 1 << 20;
int xs[z + 1];
tnode t[z * 2];

static_assert(z >= (MAXN * 2 + 1));

void tfill(int v, int l, int r, int ll, int rr, int k)
{
	if (l > rr || r < ll) return;
	if (l <= ll && rr <= r)
	{
		t[v].all = k;
		t[v].sum = k ? xs[rr + 1] - xs[ll] : 0;
		return;
	}
	if (t[v].all != -1)
	{
		t[v * 2].all = t[v].all;
		t[v * 2].sum = t[v].all ? xs[(ll + rr) / 2 + 1] - xs[ll] : 0;
		t[v * 2 + 1].all = t[v].all;
		t[v * 2 + 1].sum = t[v].all ? xs[rr + 1] - xs[(ll + rr) / 2 + 1] : 0;
		t[v].all = -1;
	}
	tfill(v * 2, l, r, ll, (ll + rr) / 2, k);
	tfill(v * 2 + 1, l, r, (ll + rr) / 2 + 1, rr, k);
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	scanf("%d%d", &n, &m);
	k = 0;
	forn(i, m)
	{
		forn(j, 3)
		{
			scanf("%d", &b[i][j]);
		}
		b[i][0]--;
		xs[k++] = b[i][0];
		xs[k++] = b[i][1];
	}
	xs[k++] = 0;
	xs[k++] = n;
	sort(xs, xs + k);
	k = unique(xs, xs + k) - xs;
	For(i, k, z)
	{
		xs[i] = n;
	}
	forn(i, m)
	{
		forn(j, 2)
		{
			b[i][j] = lower_bound(xs, xs + k, b[i][j]) - xs;
		}
	}

	t[1].all = 1;
	t[1].sum = n;
	forn(i, m)
	{
		tfill(1, b[i][0], b[i][1] - 1, 0, z - 1, b[i][2] - 1);
		printf("%d\n", t[1].sum);
	}

	return 0;
}