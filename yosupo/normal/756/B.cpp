#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

const int MN = 100100;

int dp[MN];
int t[MN];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i+1] = 20 + dp[i];
        int l;
        l = upper_bound(t, t+n, t[i]-90) - t;
        dp[i+1] = min(dp[i+1], 50 + dp[l]);
        l = upper_bound(t, t+n, t[i]-1440) - t;
        dp[i+1] = min(dp[i+1], 120 + dp[l]);
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i+1]-dp[i] << endl;
    }
    return 0;
}