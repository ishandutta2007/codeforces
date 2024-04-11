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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int p = 131;
int h[1<<20][50];
double res[1 << 20];

int main() {
    memset(h, 0, sizeof(h));
    memset(res, 0, sizeof(res));
    int n;
    cin >> n;
    vs v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int k = v[0].size();
    for (int mask = 1; mask < (1 << k); ++mask) {
        for (int b = 0; b < k; ++b) if (mask & (1 << b)) {
            int m1 = mask ^ (1 << b);
            for (int i = 0; i < n; ++i) {
                h[mask][i] = p*h[m1][i] + v[i][b];
            }
            break;
        }
    }
    for (int mask = (1 << k) - 1; mask >= 0; --mask) {
        sort(h[mask], h[mask] + n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i && h[mask][i] == h[mask][i-1]) continue;
            if (i+1 < n && h[mask][i] == h[mask][i+1]) continue;
            ++cnt;
        }
        if (cnt < n) {
            int sum = 0;
            for (int b = 0; b < k; ++b) if (!(mask & (1 << b))) {
                int m1 = mask ^ (1 << b);
                sum += 1;
                res[mask] += res[m1];
            }
//            cerr << mask << ' ' << cnt << ' ' << sum << ' ' << res[mask] << endl;
            res[mask] /= sum;
            res[mask] += n-cnt;
        }
    }
    printf("%.15lf\n", res[0]/n);
    return 0;
}