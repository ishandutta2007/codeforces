#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, m;
    cin >> n >> m;
    V<ll> xv = {1LL, TEN(9)+1};
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x; x++;
        xv.push_back(x);
    }
    sort(xv.begin(), xv.end());

    int k = int(xv.size()) - 1;
    V<int> ims(k+1);
    for (int i = 0; i < m; ++i) {
        ll x1, x2, y;
        cin >> x1 >> x2 >> y; x2++;
        x1 = lower_bound(xv.begin(), xv.end(), x1) - xv.begin();
        x2 = upper_bound(xv.begin(), xv.end(), x2) - xv.begin();
        x2--;
        if (x1 || x1 > x2) continue;
        ims[0]++; ims[x2]--;
    }
    int ans = TEN(9);
    for (int i = 0; i < k; i++) {
        ims[i+1] += ims[i];
        ans = min(ans, ims[i] + i);
    }

    cout << ans << endl;
    return 0;
}