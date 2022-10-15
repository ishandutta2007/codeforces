#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef vector<long long> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

long long MAX = 1000000000;

int main() {
    MAX *= MAX;
    int n;
    cin >> n;
    vector<pii> coord(n);
    vi x(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> c[i];
        coord[i].first = x[i];
        coord[i].second = c[i];
    }
    sort(coord.begin(), coord.end());
    for (int i = 0; i < n; ++i) {
        x[i] = coord[i].first;
        c[i] = coord[i].second;
    }
    vi res(n + 1);
    res[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        res[i] = c[i];
        long long add = 0;
        long long best = MAX;
        for (int t = i + 1; t <= n; ++t) {
            add += x[t - 1] - x[i];
            best = min(best, res[t] + add);
        }
        res[i] += best;
    }
    cout << res[0] << endl;
    return 0;
}