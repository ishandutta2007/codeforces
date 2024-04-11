#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define mt make_tuple
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define next hunext
#define rank hurank
#define prev huprev
#define link hulink
#define hash huhash
#define y0 yy0
#define y1 yy1
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (false) cerr
#endif

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;
typedef long double ldouble;

const int inf = 1e9;
const double pi = 4 * atan(1.0);
const double eps = 1e-9;

const int N = 20;

double _P[N];
double P[N];

double D[1 << N];
double sum[1 << N];

double Q[N];

int ind[N];

int main() {
#define TASK "A"
#ifdef LOCAL42
	freopen(TASK ".in", "r", stdin);
	freopen(TASK ".out", "w", stdout);
#else

#endif

	int _n, k;
	scanf("%d %d", &_n, &k);

	int n = 0;

	for (int i = 0; i < _n; i++) {
		scanf("%lf", &_P[i]);
		if (_P[i] > eps)
			P[n] = _P[i], ind[i] = n, n++;
		else
			ind[i] = -1;

	}

	k = min(k, n);



	D[0] = 1;
	sum[0] = 0;

	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				sum[i] = sum[i ^ (1 << j)] + P[j];
				break;
			}
		}
	}

	for (int msk = 0; msk < (1 << n); msk++) {
		for (int i = 0; i < n; i++) {
			if ((msk >> i) & 1) {
				continue;
			}
			assert(P[i] > eps);
			D[msk ^ (1 << i)] += D[msk] * (P[i]) / (1 - sum[msk]);
		}
	}

	for (int msk = 0; msk < (1 << n); msk++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if ((msk >> i) & 1) {
				cnt++;
			}
		}
		if (cnt == k) {
			for (int i = 0; i < n; i++) {
				if ((msk >> i) & 1)
					Q[i] += D[msk];
			}
		}
	}


	for (int i = 0; i < _n; i++) {
		if (ind[i] == -1)
			printf("0 ");
		else
			printf("%.10lf ", Q[ind[i]]);
	}

	return 0;
}