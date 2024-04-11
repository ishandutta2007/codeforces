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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const ll MD = 1e9+7.1;
const int MN = 2010;
ll dp[MN][MN];
bool used[MN][MN] = {};
int n;

ll solve(int i, int k) {
    if (k <= 0) {
        return 1;
    }
    if (used[i][k]) {
        return dp[i][k];
    }
    used[i][k] = true;
    ll r = 0;
    for (int j = i; j <= n; j += i) {
        r += solve(j, k-1);
        r %= MD;
    }
    dp[i][k] = r;
    return r;
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    cout << solve(1, k) << endl;
    return 0;
}