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
#include <map>

using namespace std;

typedef long long ll;
const int MN = 2010;
int n, k;
ll a[MN];
ll md;
int dp[MN][MN];

int solve(int last, int i) {
    if (i == n) return 0;
    if (last == -1) {
        return min(solve(last, i+1)+1, solve(i, i+1));
    }
    if (dp[last][i] != -1) return dp[last][i];
    int r = solve(last, i+1)+1;
    if (abs(a[i]-a[last]) <= (i-last)*md) {
        r = min(r, solve(i, i+1));
    }
    dp[last][i] = r;
    return r;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = -1, r = 1LL << 40;
    while (r - l > 1) {
        md = (r+l) / 2;
        fill_n(dp[0], MN*MN, -1);
        if (solve(-1, 0) > k) {
            l = md;
        } else {
            r = md;
        }
    }
    cout << r << endl;
    return 0;
}