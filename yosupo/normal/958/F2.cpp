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
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    int tsm = 0;
    int ec = k;
    V<int> tar(k);
    for (int i = 0; i < k; i++) {
        cin >> tar[i];
        tsm += tar[i];
        if (tar[i] == 0) ec--;
    }

    V<int> cnt(k);

    int l = 0, r;
    for (r = 1; r <= n; r++) {
        cnt[a[r-1]]++;
        if (cnt[a[r-1]] == tar[a[r-1]]) ec--;
        while (l < r && cnt[a[l]] > tar[a[l]]) {
            cnt[a[l]]--;
            l++;
        }
        if (ec == 0) break;
    }
    if (ec) {
        cout << -1 << endl;
        return 0;
    }
    // cout << "wow " << r << " " << l << endl;
    // for (int d: cnt) cout << d << ", "; cout << endl;
    int ans = r-l-tsm;
    for (r = r+1; r <= n; r++) {
        cnt[a[r-1]]++;
        while (l < r && cnt[a[l]] > tar[a[l]]) {
            cnt[a[l]]--;
            l++;
        }
        ans = min(ans, r-l-tsm);
    }

    cout << ans << endl;
    return 0;
}