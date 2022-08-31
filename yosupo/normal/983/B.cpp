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
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    VV<int> dp(n, V<int>(n)), dpm(n, V<int>(n));
    for (int l = 0; l < n; l++) {
        dp[l][l] = dpm[l][l] = a[l];
    }
    for (int d = 2; d <= n; d++) {
        for (int l = 0; l+d <= n; l++) {
            int r = l+d-1;
            dp[l][r] = dp[l][r-1] ^ dp[l+1][r];
            dpm[l][r] = max(dpm[l][r-1], dpm[l+1][r]);
            dpm[l][r] = max(dpm[l][r], dp[l][r]);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        cout << dpm[a][b] << endl;
    }
    return 0;
}