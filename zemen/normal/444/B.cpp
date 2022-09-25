#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "b"
#define LOCAL_INPUT NAME ".in"
//~ #define LOCAL_OUTPUT NAME ".out"
//~ #define INPUT NAME ".in"
//~ #define OUTPUT NAME ".out"

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
		clock_t start = clock();
		#ifdef LOCAL_INPUT
			assert(freopen(LOCAL_INPUT, "r", stdin));
		#endif
		#ifdef LOCAL_OUTPUT
			assert(freopen(LOCAL_OUTPUT, "w", stdout));
		#endif
	#else
		#ifdef INPUT
			assert(freopen(INPUT, "r", stdin));
		#endif
		#ifdef OUTPUT
			assert(freopen(OUTPUT, "w", stdout));
		#endif
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef _GEANY
		fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
	#endif
}

ll X;
int n, d;
int a[100001];
int b[100001];
typedef unsigned int ui;

ll getNextX() {
    X = (X * 37 + 10007) % 1000000007;
    return X;
}

void initAB() {
	int i;
    for (i = 0; i < n; i = i + 1) {
        a[i] = i;
    }
    for (i = 0; i < n; i = i + 1) {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for (i = 0; i < n; i = i + 1) {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for (i = 0; i < n; i = i + 1) {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

#define mod 32
#define mod1 31
#define shift 5
//~ #define mod 1
//~ #define mod1 0
//~ #define shift 0

ui x[mod][300001 / mod];
int bd[mod];
ui m[300001 / mod];
int pos[100001];
int res[100001];

void solve() {
	cin >> n >> d >> X;
	initAB();
	//~ for (int i = 0; i < n; ++i)
		//~ cerr << a[i] << ' ';
	//~ cerr << '\n';
	//~ for (int i = 0; i < n; ++i)
		//~ cerr << b[i] << ' ';
	//~ cerr << '\n';
	
	for (int offset = 0; offset < mod; ++offset) {
		for (int i = offset; i < n; i += mod) {
			bd[offset] = i / mod + 1;
			for (int j = 0; j < mod && i + j < n; ++j) {
				x[offset][i / mod] |= (ui(1) << j);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		m[i >> shift] |= (ui(b[i]) << (i & mod1));
	}
	for (int i = 0; i < n; ++i)
		pos[a[i]] = i;
	for (int i = n - 1; i >= 0; --i) {
		int offset = pos[i] & mod1;
		int st = pos[i] >> shift;
		for (int j = st; j < bd[offset]; ++j) {
			ui r = (x[offset][j] & m[j - st]);
			if (r) {
				for (int k = 0; k < mod; ++k) {
					if (r & (ui(1) << k)) {
						int bit = offset + j * mod + k;
						res[bit] = i + 1;
						for (int off = 0; off < mod; ++off) {
							if (off <= bit) {
								x[off][(bit - off) / mod] ^= (ui(1) << ((bit - off) & mod1));
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << res[i] << '\n';
}