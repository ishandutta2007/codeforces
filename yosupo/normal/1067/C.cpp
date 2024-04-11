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
    using P = pair<int, int>;
    set<P> st;
    auto add = [&](int x, int y) {
        cout << x << " " << y << endl;
        st.insert({x, y});
    };
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int j = i;
        int p = j % 2; j /= 2;
        int x = (j + 1) / 2;
        if (j % 2) x *= -1;
        add(x, abs(x) + 2 * p);
    }
/*    if (n <= 11) {
        for (int i = 0; i < n; i++) {
            add(i/2, i%2);
        }
    } else {
        int l = n / 3;
        for (int i = 1; i <= l; i++) {
            add(i, -1);
            add(i, -2);
        }
        int n2 = n - 2 * l;
        for (int i = 0; i < n2; i++) {
            int he = i / 2;
            he = (he % 4) + (he / 4 * 8) + 2;
            add((i % 2 == 0 ? 1 : l), he);
        }
    }*/
    //check
    /*assert(st.size() == n);
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    while (true) {
        bool up = false;
        for (int x = -1000; x <= 1000; x++) {
            for (int y = -1000; y <= 1000; y++) {
                if (st.count({x, y})) continue;
                int cnt = 0;
                for (int i = 0; i < 8; i++) {
                    if (st.count({x + dx[i], y + dy[i]})) cnt++;
                }
                if (cnt >= 4) {
                    up = true;
                    st.insert({x, y});
                }
            }
        }
        if (!up) break;
    }
    cout << n << " " << (n * n / 10) << " " << st.size() << endl;
*/
    return 0;
}