#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vd p(n + 1);
    for (int i = 0; i <= n; ++i)
        scanf("%lf", &p[i]);
    vector<vd> dyn(2e2);
    for (int i = 0; i < dyn.size(); ++i)
        dyn[i].resize(i * n + 1);
    for (int i = 0; i < dyn[1].size(); ++i)
        dyn[1][i] = p[i];
    double res = p[n / 2];
    for (int i = 2; i < dyn.size(); ++i) {
        for (int j = 0; j < dyn[i].size(); ++j) {
            for (int k = max(0, j - (int)dyn[i - 1].size() + 1); k <= min(n, j); ++k) {
                dyn[i][j] = max(dyn[i][j], p[k] + dyn[i - 1][j - k]);
            }
        }
        res = max(res, dyn[i][(n * i) / 2] / i);
    }
    printf("%lf\n", res);
    return 0;
}