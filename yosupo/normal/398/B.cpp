#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int MN = 2010;
double dp[MN][MN];
bool used[MN][MN] = {};
int n;
double solve(int x, int y) {
    if (x < 0 || y < 0) return 0;
    if (!x && !y) return 0;
    if (used[x][y]) return dp[x][y];
    double xc = x*(n-y), yc = (n-x)*y, xyc = x*y, c = (n-x)*(n-y);
    xc /= n*n-c; yc /= n*n-c; xyc /= n*n-c; c /= n*n;
    double res = 1/(1-c);
    res += xc*solve(x-1, y);
    res += yc*solve(x, y-1);
    res += xyc*solve(x-1, y-1);
    used[x][y] = true;
    dp[x][y] = res;
    return res;
}
int main() {
    int m;
    cin >> n >> m;
    bool x[MN] = {}, y[MN] = {}; 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        x[a] = true; y[b] = true;
    }
    int xc, yc;
    xc = count(x, x+n, false);
    yc = count(y, y+n, false);
    printf("%.20f\n", solve(xc, yc));
    return 0;
}