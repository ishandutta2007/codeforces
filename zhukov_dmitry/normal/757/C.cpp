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
const ld EPS = 1e-11;

const int MOD = 1000000007;

int n, m;
int a[1024000];
SI s[1024000];
VI c[1024000];
int f[1024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	f[0] = 1;
	For(i, 1, 1000000)
	{
		f[i] = f[i - 1] * (i64)i % MOD;
	}
	scanf("%d%d", &n, &m);
	forn(i, m)
	{
		a[i] = 0;
		s[0].insert(i);
	}
	int t = 1;
	forn(i, n)
	{
		int k;
		scanf("%d", &k);
		map < int, int > d;
		forn(j, k)
		{
			int x;
			scanf("%d", &x);
			x--;
			d[x]++;
		}
		int ma = 0;
		
		fori(it, d)
		{
			c[it->second].pb(it->first);
			ma = max(ma, it->second);
		}
		For(j, 1, ma)
		{
			if (c[j].empty()) continue;
			map < int, int > np;
			fori(it, c[j])
			{
				int pos = a[*it];
				if (np.find(pos) == np.end()) np[pos] = t++;
				int nt = np[pos];
//				cerr << i << " " << j << " " << *it << " " << pos << " -> " << t << endl;
				s[pos].erase(*it);
				a[*it] = nt;
				s[nt].insert(*it);
			}
			c[j].clear();
		}
	}
	int ans = 1;
	forn(i, t)
	{
		if (s[i].empty()) continue;
		ans = ans * (i64)(f[s[i].sz]) % MOD;
	}
	printf("%d\n", ans);
	
	return 0;
}