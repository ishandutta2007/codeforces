#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    V<int> fi(n, TEN(9)), ed(n, -1);
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a; a--;
        fi[a] = min(fi[a], i);
        ed[a] = max(ed[a], i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (fi[i] == TEN(9)) ans++;
        if (i < n - 1 && fi[i] > ed[i + 1]) ans++;
        if (i && fi[i] > ed[i - 1]) ans++;
    }
    cout << ans << endl;

    return 0;
}