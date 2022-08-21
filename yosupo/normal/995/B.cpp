#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    os << "["; for (auto p: v) os << p << ", "; os << "]";
    return os;
}

int main() {
    int n;
    cin >> n;
    VV<int> p(n);
    for (int i = 0; i < 2*n; i++) {
        int a;
        cin >> a; a--;
        p[a].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int li = p[i][0], ri = p[i][1];
            int lj = p[j][0], rj = p[j][1];
            if (li < lj && rj < ri) ans += 2;
            if (lj < li && ri < rj) ans += 2;
            if (li < lj && lj < ri && ri < rj) ans++;
            if (lj < li && li < rj && rj < ri) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}