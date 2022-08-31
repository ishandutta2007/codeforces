#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    // n = rand() % 10 + 1;
    // m = rand() % 20 + 1;
    using P = pair<int, int>;
    V<set<P>> g(n);
    for (int i = 0; i < n; i++) g[i].insert(P(-1, 0));
    auto adde = [&](int s, int t, int w) {
        P k;
        {
            auto it = g[s].lower_bound(P(w, -1)); it--;
            int c = it->second;
            k = P(w, c+1);
        }
        auto it = g[t].lower_bound(P(w+1, -1)); it--;
        if (it->second >= k.second) return;
        it = g[t].lower_bound(P(w, -1));
        while (it != g[t].end() && it->second <= k.second) {
            it = g[t].erase(it);
        }
        g[t].insert(k);
    };
    // struct E {
    //     int from, to, w, le;
    // };
    // V<E> v;
    // auto adde2 = [&](int s, int t, int w) {
    //     int le = 1;
    //     for (auto e: v) {
    //         if (e.to == s && e.w < w) {
    //             le = max(le, e.le + 1);
    //         }
    //     }
    //     v.push_back(E{s, t, w, le});
    // };
    for (int i = 0; i < m; i++) {
        int a, b, w;
        // a = rand() % n;
        // b = rand() % n;
        // w = rand() % 10;
        cin >> a >> b >> w; a--; b--;
        adde(a, b, w);
//        adde2(a, b, w);
    }
    int ma = 0;
//     for (int i = 0; i < n; i++) {
// /*        for (auto p: g[i]) {
//             cout << "(" << p.first << ", " << p.second << "), ";
//         }
//         cout << endl;*/
//     }
    for (int i = 0; i < n; i++) ma = max(ma, g[i].rbegin()->second);
    cout << ma << endl;
/*    int ma2 = 0;
    for (auto e: v) ma2 = max(ma2, e.le);
    assert(ma == ma2);*/
    return;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
//    srand(time(NULL));
//    for (int ph = 0; ph < 10000000; ph++) solve();
    solve();
}