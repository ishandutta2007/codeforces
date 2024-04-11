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

int n, m, k;
int t[5024];
VI b[5024];
int orig[5024];
int num[5024];
bool g[5024][5024];
bool u[5024];
int ans[5024][2];
int pa[5024];
int p1[5024];
int idx[5024];

bool find(int v)
{
	u[v] = true;
	forn(i, k)
	{
		if (g[v][i] && pa[i] == -1)
		{
			pa[i] = v;
			return true;
		}
	}
	forn(i, k)
	{
		if (g[v][i] && (pa[i] == -1 || (!u[pa[i]] && find(pa[i]))))
		{
			pa[i] = v;
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
	scanf("%d%d", &n, &m);
	clr(u);
	forn(i, n)
	{
		scanf("%d", &t[i]);
		if (t[i] == 0)
		{
			int x;
			scanf("%d", &x);
			b[i].resize(x);
			forn(j, x)
			{
				scanf("%d", &b[i][j]);
				b[i][j]--;
			}
		}
		else if (t[i] == 1)
		{
			b[i].resize(2);
			forn(j, 2)
			{
				scanf("%d", &b[i][j]);
				b[i][j]--;
			}
		}
		else //if (t[i] == 2)
		{
			b[i].resize(3);
			forn(j, 3)
			{
				scanf("%d", &b[i][j]);
				b[i][j]--;
				u[b[i][j]] = true;
			}
		}
	}
	k = 0;
	forn(i, m)
	{
		if (!u[i])
		{
			orig[k] = i;
			num[i] = k++;
		}
	}
	int kk = k;
	forn(i, n)
	{
		if (t[i] != 2) continue;
		forn(j, 3)
		{
			orig[k] = i;
			num[b[i][j]] = k;
		}
		k++;
	}
	clr(g);
	forn(i, n)
	{
		if (t[i] == 0)
		{
			for (int j : b[i])
			{
				g[i][num[j]] = true;
			}
		}
		else if (t[i] == 1)
		{
			For(j, b[i][0], b[i][1])
			{
				g[i][num[j]] = true;
			}
		}
/*		else //if (t[i] == 2)
		{
//			g[i][num[b[i][0]]] = true;
		}*/
	}
	memset(pa, 0xff, sizeof(pa));
	memset(p1, 0xff, sizeof(p1));
	forn(i, n)
	{
		idx[i] = i;
	}
	sort(idx, idx + n, [](int l, int r) {
		bool l1 = t[l] == 1;
		bool r1 = t[r] == 1;
		if (l1 != r1) return l1;
		return b[l][0] > b[r][0];
	});
	forn(i1, n)
	{
		int i = idx[i1];
		forn(j, k)
		{
			if (g[i][j] && pa[j] == -1)
			{
				pa[j] = i;
				p1[i] = j;
				break;
			}
		}
	}
	clr(u);
	forn(i1, n)
//	forn(i, n)
	{
		int i = idx[i1];
		if (p1[i] != -1) continue;
		if (find(i)) clr(u);
	}
	int cnt = 0;
	forn(i, k)
	{
		if (pa[i] != -1)
		{
			if (i < kk)
			{
				ans[cnt][0] = pa[i];
				ans[cnt][1] = orig[i];
				cnt++;
			}
			else
			{
				int v = pa[i];
				int y = -1;
				bool fnd = false;
				if (t[v] == 0)
				{
					for (int vn : b[v])
					{
						if (num[vn] == i)
						{
							fnd = true;
							y = vn;
							break;
						}
					}
				}
				else //if (t[v] == 1)
				{
					For(vn, b[v][0], b[v][1])
					{
						if (num[vn] == i)
						{
							fnd = true;
							y = vn;
							break;
						}
					}
				}
				assert(fnd);
				ans[cnt][0] = v;
				ans[cnt][1] = y;
				cnt++;
				int bn = orig[i];
				forn(j, 3)
				{
					if (b[bn][j] == y) continue;
					ans[cnt][0] = bn;
					ans[cnt][1] = b[bn][j];
					cnt++;
				}
			}
		}
		else
		{
			if (i >= kk)
			{
				int bn = orig[i];
				forn(j, 2)
				{
					ans[cnt][0] = bn;
					ans[cnt][1] = b[bn][j];
					cnt++;
				}
			}
		}
	}

	printf("%d\n", cnt);
	forn(i, cnt)
	{
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
	}

	return 0;
}