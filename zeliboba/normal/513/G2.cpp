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

int c2(int x) {
    return x*(x + 1)/2;
}

int main() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vvd p(n, vd(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
        if (a[j] > a[i]) {
            p[i][j] = 1;
        } //else p[j][i] = 1;
    }
    int div = n*(n + 1)/2;
    for (int t = 0; t < k; ++t) {
        vvd np(n, vd(n));
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
            //np[i][j] += (1 - p[i][j]) * (j + 1) * (n - i) / div;
            int mul = c2(i - j - 1) + c2(j) + c2(n-i-1);
            np[i][j] += p[i][j] * mul;
            cerr << mul << endl;
            for (int i1 = 0; i1 <= j; ++i1) for (int j1 = j; j1 < i; ++j1) {
                np[i][i1 + j1 - j] += p[i][j];
                assert(i > i1 + j1 - j);
                ++mul;
            }
            for (int i1 = j + 1; i1 <= i; ++i1) for (int j1 = i; j1 < n; ++j1) {
                np[i1 + j1 - i][j] += p[i][j];
                assert(i1 + j1 - i > j);
                ++mul;
            }
            for (int i1 = 0; i1 <= j; ++i1) for (int j1 = i; j1 < n; ++j1) {
                np[i1 + j1 - j][i1 + j1 - i] += 1-p[i][j];
                assert(i1 + j1 - j > i1 + j1 - i);
                ++mul;
            }
//            cerr << mul << ' ' << div << ' ' << i << ' ' << j << endl;
            assert(mul == div);
        }
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) {
            np[i][j] /= div;
        }
        p.swap(np);
    }
    double res = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j)
        res += p[i][j];
    printf("%.10lf\n", res);
    return 0;
}