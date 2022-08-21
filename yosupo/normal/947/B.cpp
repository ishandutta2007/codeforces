#include <bits/stdc++.h>

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
    V<ll> v(n), t(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    ll tsm = 0;
    for (int i = 0; i < n; i++) {
        v[i] += tsm;
        tsm += t[i];
        t[i] = tsm;
    }
    sort(begin(v), end(v));
    ll cnt = 0, sm = 0;
    V<ll> ans(n);
    for (int i = 0; i < n; i++) {
        while (cnt < n && v[cnt] <= t[i]) {
            sm += v[cnt];
            cnt++;
        }
        ans[i] = (n - cnt) * t[i] + sm;
    }
    for (int i = n-1; i >= 1; i--) {
        ans[i] -= ans[i-1];
    }
    for (int i = 0; i < n; i++) {
        ans[i] -= (n-1-i) * (t[i] - (i ? t[i-1] : 0));
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}