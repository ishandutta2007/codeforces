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

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vi t(m), h(m);
    int ma = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &t[i], &h[i]);
        ma = max(ma, h[i]);
        if (i && (abs(h[i] - h[i-1]) > t[i] - t[i-1])) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        if (i) {
            int d = t[i] - t[i-1];
            int x = min(h[i], h[i-1]);
            int y = max(h[i], h[i-1]);
            d -= y - x;
            ma = max(ma, y + d / 2);
        }
    }
    ma = max(ma, t[0] - 1 + h[0]);
    ma = max(ma, n - t.back() + h.back());
    printf("%d\n", ma);
    return 0;
}