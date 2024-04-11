#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n;
    cin >> n;
    V<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(begin(v), end(v));
    V<int> w = v;

    int ans = 0;
    while (v.size()) {
        int d = v.back(); v.pop_back();
        while (w.size() && w.back() >= d) w.pop_back();
        if (!w.size()) break;
        ans++;
        w.pop_back();
    }
    cout << ans << endl;
    return 0;
}