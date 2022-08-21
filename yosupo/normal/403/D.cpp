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

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MD = 1e9+7.1;
const int MN = 1010;
int dp[MN][50];
ll f[MN];
int solve(int n, int k) {
    if (n < 0) return 0;
    if (!k) return 1;
    if (n == 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    ll r = solve(n-1, k);
    for (int i = 0; i < n; i++) {
        r += solve(n-i-1-(k-1)*(i+1), k-1);
    }
    r %= MD;
    dp[n][k] = (int)r;
    return (int)r;
}

int main() {
    f[0] = 1;
    for (int i = 1; i < MN; i++) {
        f[i] = f[i-1]*i%MD;
    }
    fill_n(dp[0], MN*50, -1);
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (k < 50) {
            printf("%d\n", (int)(f[k]*solve(n, k)%MD));
        } else {
            printf("0\n");
        }
    }
    return 0;
}