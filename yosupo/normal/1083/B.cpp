#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int main() {
    ios::sync_with_stdio(false); // Warning!!!!!
    cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    ll dif = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        dif *= 2;
        if (s[i] == 'b') dif--;
        if (t[i] == 'b') dif++;
        dif = min(dif, TEN(10));
        ans += min(k, dif + 1);
    }
    cout << ans << endl;
    return 0;
}