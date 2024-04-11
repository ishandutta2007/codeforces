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

const int MAXN = 400000 * 9;

int l;
char s[202400];
int d[MAXN + 1];
int pa[MAXN + 1];
bool bad[101];
bool u[MAXN + 1];
bool ans[MAXN + 1];

int len(int x)
{
	if (x < 10000)
	{
		if (x < 100)
		{
			if (x < 10) return 1;
			else return 2;
		}
		else
		{
			if (x < 1000) return 3;
			else return 4;
		}
	}
	else
	{
		if (x < 1000000)
		{
			if (x < 100000) return 5;
			else return 6;
		}
		else
		{
			if (x < 10000000) return 7;
			else return 8;
		}
	}
}

void precalc()
{
	clr(bad);
	For(i, 1, 9)
	{
		For(j, 1, 9)
		{
			if (i + j >= 10)
			{
				bad[i * 10 + j] = true;
			}
		}
	}
	For(i, 1, 9)
	{
		d[i] = 0;
	}
//	int ma = 0;
//	int mj = 0;
	int prev = -10000000;
	int cnt = 0;
	For(i, 10, MAXN)
	{
		d[i] = 3;
		int k = len(i);
		int b[10];
		int x = i;
		int z = 0;
		forn(j, k)
		{
			b[j] = x % 10;
			x /= 10;
			z += b[j];
		}
		if (z < 10)
		{
			d[i] = 1;
			pa[i] = 0;
			continue;
		}
		if (!bad[z])
		{
			d[i] = 2;
			pa[i] = 0;
			continue;
		}
		if (bad[z])
		{
			d[i] = 3;
			pa[i] = 0;
//			continue;
		}
		forn(mask, 1 << (k - 1))
		{
			int sum = 0;
			int cur = 0;
			ford(j, k)
			{
				cur = cur * 10 + b[j];
				if (!(mask & (1 << (k - j - 1))))
				{
					sum += cur;
					cur = 0;
				}
			}
			if (sum == i) continue;
//			if (i == 289)
//			{
//				cerr << sum << " " << d[sum] << endl;
//			}
			if (d[sum] + 1 < d[i])
			{
				d[i] = d[sum] + 1;
				pa[i] = mask;
			}
			if (d[i] == 2) break;
		}
		if (d[i] == 3)
		{
			int z = 0;
			forn(j, k)
			{
				z += b[j];
			}

			if (z == 19 || z == 28 || z == 37 || z == 46)
			{
//				cerr << i << " " << z << " " << i - prev << endl;
				if (i - prev <= 9) cnt++;
				else cnt = 0;
/*				if (cnt > ma)
				{
					ma = cnt;
					mj = i;
				}*/
				prev = i;
			}
		}
/*		if (d[i] > 3)
		{
			cerr << i << " " << d[i] << " " << pa[i] << endl;
//			break;
		}*/
	}
//	printf("ma = %d, mj = %d\n", ma, mj);
}

void print_ans(int x)
{
	forn(t, 2)
	{
		int k = len(x);
		int mask = pa[x];
		int b[10];
		int q = x;
		int z = 0;
		forn(r, k)
		{
			b[r] = q % 10;
			q /= 10;
			z += b[r];
		}
		int sum = 0;
		int cur = 0;
		ford(j, k)
		{
			cur = cur * 10 + b[j];
			printf("%d", b[j]);
			if (!(mask & (1 << (k - j - 1))))
			{
				if (j) putchar('+');
				sum += cur;
				cur = 0;
			}
		}
		x = sum;
		puts("");
	}
}

void gen_in()
{
	l = 98721;
	forn(i, l - 1)
	{
		s[i] = '9';
	}
	s[l - 1] = '1';
	s[l] = '\0';
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	
	precalc();

	scanf("%d", &l);
	scanf("%s", s);

//	gen_in();

	int sum = 0;
	forn(i, l)
	{
		sum += s[i] - '0';
	}
	For(st, 1, 6)
	{
		int ss = sum;
		int s0 = 0;
		int w = st - 1;
		clr(ans);
		forn(i, st)
		{
			ss -= s[i] - '0';
			s0 = s0 * 10 + s[i] - '0';
			if (i < st - 1) ans[i] = true;
		}
		ss += s0;
		for(;;)
		{
			if (d[ss] <= 2)
			{
				forn(i, l)
				{
					printf("%c", s[i]);
					if (i < l - 1 && !ans[i]) putchar('+');
				}
				puts("");
				print_ans(ss);
				return 0;
			}
			w++;
			while (w < l - 1 && s[w] == '0') w++;
			if (w >= l - 1) break;
			ans[w] = true;
			ss += (s[w] - '0') * 9;
			if (ss >= MAXN) break;
			w++;
		}
	}
	return 239;

	if (d[sum] <= 2)
	{
		forn(i, l)
		{
			if (i) putchar('+');
			printf("%c", s[i]);
		}
		puts("");
		print_ans(sum);
	}
	else
	{
		clr(u);
		clr(ans);
		forn(i, l)
		{
			if (s[i] == '0') u[i] = true;
		}

		for(;;)
		{
			int x;
			do
			{
				x = rand() % (l - 1);
			}
			while (u[x]);
			ans[x] = true;
			u[x] = true;
			u[x + 1] = true;
			if (x > 0) u[x - 1] = true;
			sum += (s[x] - '0') * 9;
			if (d[sum] <= 2) break;
		}
		forn(i, l)
		{
			if (i && !ans[i]) putchar('+');
			printf("%c", s[i]);
		}
		puts("");
		print_ans(sum);
	}
	
	return 0;
}