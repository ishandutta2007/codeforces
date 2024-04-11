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
const int MN = 100100;
ll num[MN];
ll dp[MN];
ll solve(int i) {
    if (i == MN-1) return 0; 
    if (dp[i] != -1) return dp[i];
    dp[i] = max(solve(i+1), num[i]*i+solve(i+2));
    return dp[i];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        num[u]++;
    }
    fill_n(dp, MN, -1);
    cout << solve(0) << endl;
    return 0;
}