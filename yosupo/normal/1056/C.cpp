#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

int main() {
    int n, m;
    cin >> n >> m;
    V<int> pw(2*n), mt(2*n, -1);
    for (int i = 0; i < 2*n; i++) cin >> pw[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        mt[a] = b; mt[b] = a;
    }
    V<bool> used(2*n);
    auto query = [&](int x){
        used[x] = true;
        x++;
        cout << x << endl;
    };
    auto my_turn = [&](){
        for (int i = 0; i < 2*n; i++) {
            if (used[i] || mt[i] == -1 || !used[mt[i]]) continue;
            query(i);
            return true;
        }
        for (int i = 0; i < 2*n; i++) {
            if (used[i] || mt[i] == -1) continue;
            if (pw[i] < pw[mt[i]]) continue;
            query(i);
            return true;
        }
        int m_i = -1;
        for (int i = 0; i < 2*n; i++) {
            if (used[i] || mt[i] != -1) continue;
            if (m_i == -1 || pw[m_i] < pw[i]) {
                m_i = i;
            }
        }
        if (m_i == -1) return false;
        query(m_i);
        return true;
    };
    auto your_turn = [&](){
        int x;
        cin >> x; x--;
        used[x] = true;
        return x;
    };
    int t;
    cin >> t;
    if (t == 1) my_turn();
    for (int i = 0; i < n; i++) {
        your_turn();
        my_turn();
    }
    return 0;
}