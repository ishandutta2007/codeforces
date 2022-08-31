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
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

ll lcm(ll a, ll b) {
    return a/__gcd(a, b)*b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        int s = a[i];
        int j;
        for (j = 1; j < 2*n; j++) {
            if (s == i) break;
            s = a[s];
        }
//        cout << j << endl;
        if (j == 2*n) {
            cout << -1 << endl;
            return 0;
        }
        if (j % 2 == 0) j /= 2;
        ans = lcm(ans, j);
    }
    cout << ans << endl;
    return 0;
}