#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

char was[10000001];

int main() {
    int n, k, q;
    scanf("%d%d", &n, &k);
    vi a(n);
    for (int i = 0; i < a.size(); ++i) {
        scanf("%d", &a[i]);
        was[a[i]] = 1;
    }
    scanf("%d", &q);
    for (int tt = 0; tt < q; ++tt) {
        int x;
        scanf("%d", &x);
        int mi = k + 1;
        for (int i = 0; i < n; ++i) {
            if (x % a[i] == 0) mi = min(mi, x/a[i]);
            for (int j = 1; j < k; ++j) {
                int y = x - j * a[i];
                if (y <= 0) break;
                for (int t = 1; t <= k-j; ++t) if (y % t == 0 && y / t <= a.back()) {
                    if (was[y/t]) mi = min(mi, j + t);
                }
            }
        }
        if (mi <= k) cout << mi << endl;
        else cout << -1 << endl;
    }
    return 0;
}