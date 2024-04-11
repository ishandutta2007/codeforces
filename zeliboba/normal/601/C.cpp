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
    cin >> n >> m;
    if (m == 1) {
        printf("1\n");
        return 0;
    }
    vi x(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        s += x[i];
    }
    vd d(n*m + 1);
    d[0] = 1;
    for (int i = 0; i < n; ++i) {
        vd nd(d.size(), 0.);
        /*for (int j = 1; j <= m; ++j) if (j != x[i]) {
            for (int it = 0; it + j < d.size(); ++it) nd[it + j] += d[it];
        }*/
        double sum = 0;
        for (int it = 0; it < nd.size(); ++it) {
            nd[it] += sum;
            sum += d[it];
            if (it >= m) sum -= d[it-m];
        }
        for (int it = 0; it + x[i] < d.size(); ++it) nd[it + x[i]] -= d[it];
        for (int it = 0; it < nd.size(); ++it) nd[it] /= (m-1);
        d.swap(nd);
    }
    double res = 0;
    for (int i = 0; i < s; ++i) res += d[i];
    printf("%.12lf\n", res * (m - 1) + 1);
    return 0;
}