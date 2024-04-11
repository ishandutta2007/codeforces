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
typedef long long i64;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    vi l(m), r(m), t(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> t[i] >> c[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int best = 1e8, cost = 0;
        bool was = false;
        for (int j = 0; j < m; ++j) if (l[j] <= i && r[j] >= i) {
            was = true;
            if (t[j] < best) {
                best = t[j];
                cost = c[j];
            }
        }
        if (was)
            res += cost;
    }
    cout << res << endl;
    return 0;
}