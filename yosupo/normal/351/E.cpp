#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;

struct Pi {
    int x, y;
    Pi() {}
    Pi(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator<(const Pi &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator>(const Pi &r) const {
        if (x != r.x) return x > r.x;
        return y > r.y;
    }
};

struct Ti {
    int x, y, z;
    Ti() {}
    Ti(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
};
int mar[2010];
int sum[2010], sumb[2010];
int n;
int dp[2010][2010];
int calc(int i, int u) {
    if (i == n) return 0;
    if (dp[i][u] != -1) return dp[i][u];
    int r1 = calc(i+1, u+1)+sum[n-1]-sum[i];
    int r2 = calc(i+1, u)+u+sum[i];
    dp[i][u] = min(r1, r2);
    return dp[i][u];
}
int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    sum[0] = mar[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1]+mar[i];
    }
    return calc(0, 0);
}
int main() {
    int m;
    cin >> m;
    list<int> data;
    set<int, greater<int>> s;
    for (int i = 0; i < m; i++) {
        int u;
        cin >> u; u = abs(u);
        data.push_back(u);
        s.insert(u);
    }
    int r = 0;
    for (int d: s) {
        data.push_back(d);
        int c = 0;
        n = 0;
        for (int k: data) {
            if (k == d) {
                mar[n] = c;
                n++;
                c = 0;
            } else {
                c++;
            }
        }
        r += solve();
        data.remove(d);
    }
    cout << r << endl;
    return 0;
}