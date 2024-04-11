#pragma GCC optimize("Ofast")
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
typedef double ld;
typedef long long i64;
typedef unsigned long long u64;
typedef pair < int, int > PII;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;

// Constants
const ld PI = 3.1415926535897932384626433832795L;
const ld EPS = 1e-9;

int p[1024000];
bool u[1024000];
int e[1024000];
int sum[1024000];
bool z[22][1 << 20];
bool nz[1 << 20];

const int SHIFT = 20;
const int LEN = 1 << SHIFT;

struct cd{ld x,y;};

int n, s, q, h, m;
ld si[LEN];
ld si0[LEN];
int rev[LEN];
cd a[LEN];
cd b[LEN];
cd c[LEN];
bool allok = false;
int kk;

void mktab0()
{
	ld a, b;
	rev[0] = 0;
	for (q=1; q<n; q <<= 1)
	{
		forn(i, q)
		{
			rev[i] <<= 1;
			rev[i+q] = rev[i] + 1;
		}
	}
	a = 2.0 * PI / n;
	q = n >> 2;
	h = n >> 1;
	For(i, 0, n >> 3)
	{
		b = a * i;
		si[q - i] = cos(b);
		si[i] = sin(b);
	}
	For(i, 1, q) si[q+i] = si[q-i];
	For(i, 0, q) si[h+i] = -si[i];
}

void mktab()
{
	rev[0] = 0;
	for (q=1; q<n; q <<= 1)
	{
		forn(i, q)
		{
			rev[i] <<= 1;
			rev[i+q] = rev[i] + 1;
		}
	}
	q = n >> 2;
	h = n >> 1;
	For(i, 0, n >> 3)
	{
		si[q - i] = si0[(q - i) << (20 - m)];
		si[i] = si0[i << (20 - m)];
	}
	For(i, 1, q) si[q+i] = si[q-i];
	For(i, 0, q) si[h+i] = -si[i];
}

void precalc()
{
	m = 20;
	n = 1 << m;
	mktab0();
	memcpy(si0, si, sizeof(si));
}

void step(int k, cd *a, cd *b)
{
	int m = n >> k, c = m, d = 0;
	cd t, u, v, r;
	r.x = 1.0;
	r.y = 0.0;
	forn(i, h)
	{
		t = a[2 * i];
		u = a[2 * i + 1];
		v.x = u.x * r.x - u.y * r.y;
		v.y = u.x * r.y + u.y * r.x;
		b[i].x = t.x + v.x;
		b[i].y = t.y + v.y;
		b[h+i].x = t.x - v.x;
		b[h+i].y = t.y - v.y;
		c--;
		if (c==0)
		{
			c = m;
			d += m;
			r.x = si[d+q];
			r.y = si[d];
		}
	}
}

void step2(int k, cd *a, cd *b)
{
	int m = n >> k, c = m, d = 0;
	cd t, u, v, r;
	r.x = 1.0;
	r.y = 0.0;
	forn(i, h)
	{
		t = a[2 * i];
		u = a[2 * i + 1];
		v.x = u.x * r.x - u.y * r.y;
		v.y = u.x * r.y + u.y * r.x;
		b[i].x = t.x + v.x;
		b[i].y = t.y + v.y;
		b[h+i].x = t.x - v.x;
		b[h+i].y = t.y - v.y;
		c--;
		if (c==0)
		{
			c = m;
			d += m;
			r.x = si[d+q];
			r.y = -si[d];
		}
	}
}

void fourier(cd *a, cd *c)
{
	forn(i, m)
	{
		if (i&1) step(i+1, c, a);
		else step(i+1, a, c);
	}
	if (!(m & 1))
	{
		memcpy(c, a, n * sizeof(c[0]));
	}
}

void fourier2(cd *a, cd *c)
{
	forn(i, m)
	{
		if (i&1) step2(i+1, c, a);
		else step2(i+1, a, c);
	}
	if (!(m & 1))
	{
		memcpy(c, a, n * sizeof(c[0]));
	}
}

void tuda(bool *from, cd *to)
{
	memset(to, 0, n * sizeof(to[0]));
	forn(i, n)
	{
		to[rev[i]].x = from[i];
	}
	fourier(to, c);
	forn(i, n)
	{
		to[rev[i]] = c[i];
	}
}

void obratno(cd *a, bool *ans)
{
	fourier2(a, c);
	memset(ans, 0, n * sizeof(ans[0]));
	forn(i, n)
	{
		ans[i] = (int)(c[i].x / n + 0.5);
	}
}

void go(bool *x, int xs, bool *y, int ys)
{
	int len = xs + ys + 1;
/*	if (x[kk] || y[kk])
	{
		allok = true;
		return;
	}*/
	if (xs <= 250 && ys <= 250)
	{
		forn(i, len)
		{
			nz[i] = 0;
		}
		For(i, 0, xs)
		{
			if (!x[i]) continue;
			For(j, 0, ys)
			{
				nz[i + j] |= y[j];
			}
		}
	}
	else
	{
		m = 5;
		while ((1 << m) < len) m++;
		n = 1 << m;
		mktab();
		tuda(x, a);
		tuda(y, b);
		for(int i = 0; i < n; i++)
		{
			ld xx = a[i].x * b[i].x - a[i].y * b[i].y;
			ld yy = a[i].x * b[i].y + a[i].y * b[i].x;
			a[i].x = xx;
			a[i].y = yy;
		}
		obratno(a, nz);
	}
	memmove(x, nz, len);
	memset(y, 0, ys + 1);
}

/*void test()
{
	bool x[256];
	bool y[256];
	clr(x);
	clr(y);
	int xs = 7;
	int ys = 9;
	x[0] = 1;
	x[3] = 1;
	x[7] = 1;
	y[0] = 1;
	y[5] = 1;
	y[9] = 1;

	int len = xs + ys + 1;

	m = 2;
	while ((1 << m) < len) m++;
	n = 1 << m;
	mktab0();
	tuda(x, a);
	tuda(y, b);
	for(int i = 0; i < n; i++)
	{
		ld xx = a[i].x * b[i].x - a[i].y * b[i].y;
		ld yy = a[i].x * b[i].y + a[i].y * b[i].x;
		a[i].x = xx;
		a[i].y = yy;
	}
	obratno(a, nz);
	For(i, 0, len)
	{
		fprintf(stderr, "%d %d\n", i, nz[i]);
	}
	fprintf(stderr, "-----\n");
}
*/
void solve_mi(int h, int l, int r, int k = -1)
{
//	if (allok) return;
	if (l == r)
	{
		z[h][e[l]] = true;
		z[h][0] = true;
		return;
	}
	int m = l;
	while (m + 1 < r && abs((sum[r + 1] - sum[m + 1]) - (sum[m + 1] - sum[l])) > abs((sum[r + 1] - sum[m + 2]) - (sum[m + 2] - sum[l]))) m++;
//	cerr << l << " " << r << " " << m << " " << e[m] << " " << e[m + 1] << " " << sum[m] - sum[l] << " " << sum[r + 1] - sum[m] << endl;
//	cerr << l << " " << r << " " << m << " " << e[m] << " " << e[m + 1] << " " << sum[m + 1] - sum[l] << " " << sum[r + 1] - sum[m + 1] << endl;
//	cerr << endl;
//	int m = (l + r) / 2;

	solve_mi(h, l, m);
	solve_mi(h + 1, m + 1, r);
//	if (allok) return;
	if (k < 0) go(z[h], sum[m + 1] - sum[l], z[h + 1], sum[r + 1] - sum[m + 1]);
	else
	{
		For(i, 0, k)
		{
			if (z[h][i] && z[h + 1][k - i]) z[h][k] = true;
		}
	}
}

char buf[7024000];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
#endif
	
//	test();
//	return 0;

	int n, k;
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf, "%d%d", &n, &k);
	fgets(buf, sizeof(buf), stdin);
	char *h = buf;
	forn(i, n)
	{
		int x = 0;
		while (*h < '0' || *h > '9') h++;
		while (*h >= '0' && *h <= '9') x = x * 10 + *h++ - '0';
		p[i] = x;
//		scanf("%d", &p[i]);
		p[i]--;
	}
	if (k == 0 || k == n)
	{
		printf("%d %d\n", k, k);
		return 0;
	}

/*	{
		srand(1183815);
		int l = 500000;
		n = 1000000;
		k = 500000;
		int s = 0;
		while (s < n)
		{
			int z = min(n - s, l);
			forn(i, z - 1)
			{
				p[s + i] = s + i + 1;
			}
			p[s + z - 1] = s;
			s += z;
			l = 2;
//			l++;
		}
//		forn(i, n)
//		{
//			p[i] = i % 5 == 0 ? i + 4 : i - 1;
//			p[i] = i ^ 1;
//		}
	}*/
//	random_shuffle(p, p + n);

	int gg = 0;
	clr(u);
	int m = 0;
	forn(i, n)
	{
		if (u[i]) continue;
		int x = i;
		int cnt = 0;
		do
		{
			u[x] = true;
			cnt++;
			x = p[x];
		}
		while (x != i);
		gg = __gcd(gg, cnt);
		e[m++] = cnt;
	}
	sort(e, e + m);
//	random_shuffle(e, e + m);
	int s2 = 0;
	sum[0] = 0;
	forn(i, m)
	{
		s2 += e[i] / 2;
		sum[i + 1] = sum[i] + e[i];
	}
	int ansmi, ansma;
	if (s2 >= k) ansma = k * 2;
	else ansma = min(n, s2 * 2 + (k - s2));
//	cerr << "m = " << m << endl;
	if (k % gg != 0) ansmi = k + 1;
	else
	{
		precalc();
		kk = min(k, n - k);
//		kk = k;
		solve_mi(0, 0, m - 1, kk);
		ansmi = allok || z[0][kk] ? k : k + 1;
	}

	printf("%d %d\n", ansmi, ansma);
	
	return 0;
}