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
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 110;
int n;
int a[MN];

int dp[MN][3];
bool used[MN][3];
int solve(int p, int b) {
    if (p == n) return 0;
    if (used[p][b]) return dp[p][b];
    used[p][b] = true;
    int ans = solve(p+1, 0)+1;
    if (b != 1 && (a[p] & 1)) {
        ans = min(ans, solve(p+1, 1));
    }
    if (b != 2 && (a[p] & 2)) {
        ans = min(ans, solve(p+1, 2));
    }
    return dp[p][b] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, 0) << endl;
    return 0;
}