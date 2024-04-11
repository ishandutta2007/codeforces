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

    int n, k, p;
    cin >> n >> k >> p;
    V<int> a(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i+1]; a[i+1] %= p;
        a[i+1] += a[i];
        a[i+1] %= p;
    }

//    cout << "DEBUG AS: ";
//    for (int d: a) cout << d << ", "; cout << endl;

    V<int> dp(n+1, -10000); dp[0] = 0;
    for (int ph = 1; ph <= k; ph++) {
        V<int> rmq(p, -10000);
        V<int> ndp(n+1, -10000);
        int mi = -10000;
        for (int i = 0; i <= n; i++) {
            ndp[i] = mi;
            for (int j = a[i]+1; j < p; j++) {
                ndp[i] = max(ndp[i], 1+rmq[j]);
            }
//            for (int j = a[i]; j >= 0; j -= 10) {
//                ndp[i] = min(ndp[i], rmq[j]);
//             }
            rmq[a[i]] = max(rmq[a[i]], dp[i]);
//            for (int j = a[i]; j < min(p, a[i]+10); j++) {
//                rmq[j] = min(rmq[j], dp[i]);
//            }
            mi = max(mi, dp[i]);
        }
/*        for (int d: ndp) {
            cout << d << ", ";
        }cout << endl;*/
        dp = ndp;
    }

    cout << (a[n] + dp[n] * p) << endl;
    return 0;
}