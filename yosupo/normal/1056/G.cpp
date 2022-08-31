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

    int n, m;
    cin >> n >> m;
    int s; ll t;
    cin >> s >> t; s--;
    int t_mod = int(t % n);

    V<ll> prev(n, -1);
    while (t) {
        if (s < m) {
            s += t_mod;
            if (s >= n) s -= n;
        } else {
            s -= t_mod;
            if (s < 0) s += n;
        }
        t--;
        t_mod--;
        if (t_mod == -1) t_mod = n-1;

        if (t_mod == 0) {
            if (prev[s] == -1) prev[s] = t;
            else {
                ll freq = prev[s] - t;
                t -= t / freq * freq;
            }
        }
    }
    cout << s + 1 << endl;
    return 0;
}