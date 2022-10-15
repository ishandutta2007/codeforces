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
    int n;
    cin >> n;
    vi l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    double sum = 0;
    for (int i = 0; i < n; ++i) {
/*        for (int j = l[i]; j <= r[i]; ++j) {
            ll prod = 1;
            for (int t = 0; t < n; ++t) if (t != i) {
                prod *= max(0, min(r[t], j-1) - l[t] + 1);
            }
            sum += prod;
        }*/
        for (int j = 1; j <= r[i]; ++j) {
            for (int mask = 1; mask < (1 << n); ++mask) if (!(mask & (1 << i))) {
                ll prod = 1;
                int cnt = 0;
                for (int t = 0; t < n; ++t) if (mask & (1 << t)) {
                    ++cnt;
                }
                for (int t = 0; t < n; ++t) if (t != i) {
                    if (mask & (1 << t)) {
                        if (!(l[t] <= j && j <= r[t])) 
                            prod = 0;
                    } else {
                        prod *= max(0, min(r[t], j-1) - l[t] + 1);
                    }
                }
                if (j >= l[i]) sum += prod * (double)j / (cnt + 1);
                sum += prod * (double)j * min(r[i] - j, r[i] - l[i] + 1);
//                cerr << i << ' ' << j << ' ' << prod << ' ' << min(r[i] - j, r[i] - l[i] + 1) << endl;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        sum /= r[i]-l[i]+1;
    printf("%.12lf\n", sum);
    return 0;
}