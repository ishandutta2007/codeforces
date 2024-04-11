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

    ll a, b;
    cin >> a >> b;
    ll mi = 1, ma = a;
    mi = max(mi, b-a);
    ma = min(ma, b-1);
    ma = min(ma, (b-1)/2);
    if (mi <= ma) cout << ma-mi+1 << endl;
    else cout << 0 << endl;
    return 0;
}