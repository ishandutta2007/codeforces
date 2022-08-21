#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

void ok() {
    cout << "YES" << endl;
    exit(0);
}

void imp() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s; s--;
    V<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (!a[0]) imp();
    if (a[s]) ok();
    if (!b[s]) imp();
    for (int i = s+1; i < n; i++) {
        if (a[i] && b[i]) ok();
    }
    imp();
}