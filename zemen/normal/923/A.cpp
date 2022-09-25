#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int lp[N];

void precalc() {
	vector<int> primes;
	fill_n(lp, N, -1);
	lp[1] = 1;
	for (int i = 2; i < N; i++) {
		if (lp[i] == -1) {
			primes.pb(i);
			lp[i] = i;
		}
		for (int j = 0; j < len(primes) && primes[j] <= lp[i] && i * primes[j] < N; j++) {
			lp[i * primes[j]] = primes[j];
		}
	}
	for (int i = 2; i < N; i++) {
		lp[i] = max(lp[i], lp[i / lp[i]]);
	}
	for (int i = 2; i < N; i++) {
		if (lp[i] != i) {
			lp[i] = i - lp[i] + 1;
		} else {
			lp[i] = inf;
		}
	}
}

int ans = inf;
int n;

void check(int x) {

}

int main() {
#ifdef XCODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    precalc();
    cin >> n;
    vector<int> cur;
    int t = n;
    for (int i = 2; i * i <= n; i++) {
    	if (n % i == 0) {
    		cur.pb(i);
    		while (n % i == 0) {
    			n /= i;
    		}
    	}
    }
    if (n != t && n > 1) {
    	cur.pb(n);
    }
    n = t;
    sort(all(cur));
    int minValue = inf, it = n - 1;
    for (int i : cur) {
    	int j = n - i + 1;
    	while (it >= j) {
    		minValue = min(minValue, lp[it--]);
    	}
    	ans = min(ans, j);
    	ans = min(ans, minValue);
    }
    cout << ans << endl;
    return 0;
}