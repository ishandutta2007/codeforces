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
    int n;
    cin >> n;
    V<int> v(n+1);
    for (int i = 0; i < n; i++) cin >> v[i];
    v[n] = v[0];

    using P = pair<int, int>;
    V<P> pt;
    for (int i = 0; i < n; i++) {
        int ldi = n - v[i], rdi = v[i+1];
        pt.push_back(P(rdi - ldi, i));
    }
    sort(pt.begin(), pt.end());

    V<int> res(n);
    for (int i = 0; i < n; i++) res[pt[i].second] = i;

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}