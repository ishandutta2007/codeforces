#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
const int MN = 55;
int main() {
    int n;
    cin >> n;
    int g[MN][MN];
    int res[MN];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    bool f = false;
    for (int i = 0; i < n; i++) {
        int ma = -1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ma = max(ma, g[i][j]);
        }
        if (ma == n-1) {
            if (!f) {
                res[i] = n-1;
                f = true;
            } else res[i] = n;
        } else {
            res[i] = ma;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    } cout << endl;
    return 0;
}