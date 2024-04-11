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
const int MN = 200200;

vector<int> g[MN];

using P = array<int, 2>;
P dfs(int p, int b) {
    int ans[3] = {0, -10000000, -10000000};
    for (int d: g[p]) {
        if (d == b) continue;
        P res = dfs(d, p);
        ans[2] = max(ans[2]+res[0], ans[1]+res[1]);
        ans[1] = max(ans[1]+res[0], ans[0]+res[1]);
        ans[0] += res[0];
    }
    P ret;
    ret[0] = max(max(ans[0], ans[1]+1), ans[2]+2);
    ret[1] = max(ans[0], ans[1]+1);
    return ret;
}

ll solve() {
    int n; ll x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n == 2) return x;
    if (x > y) {
        for (int i = 0; i < n; i++) {
            if (g[i].size() == n-1) return x + y * (n-2);
        }
        return y * (n-1);
    }
    int re = dfs(0, -1)[0];
    return re * x + (n-1-re) * y;
}

int main() {
    cout << solve() << endl;
    return 0;
}