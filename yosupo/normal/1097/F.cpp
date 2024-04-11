#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

const int MD = 7020;
using B = bitset<MD + 1>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    V<B> mp(MD + 1);
    for (int i = 1; i <= MD; i++) {
        for (int j = i; j <= MD; j += i) {
            mp[j].set(i);
        }
    }
    B mebi(MD + 1); mebi.set();
    for (int i = 2; i <= MD; i++) {
        for (int j = i * i; j <= MD; j += i * i) {
            mebi.reset(j);
        }
    }
    V<B> q_mp(MD + 1);
    for (int i = 1; i <= MD; i++) {
        for (int j = 1; i * j <= MD; j++) {
            if (mebi.test(j)) q_mp[i].set(i * j);
        }
    }

    int n, q;
    cin >> n >> q;
    V<B> g(n);
    string ans;
    for (int ph = 0; ph < q; ph++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            //set
            int x, v;
            cin >> x >> v; x--;
            g[x] = mp[v];
        } else if (ty == 2) {
            int x, y, z;
            cin >> x >> y >> z; x--; y--; z--;
            g[x] = g[y] ^ g[z];
        } else if (ty == 3) {
            int x, y, z;
            cin >> x >> y >> z; x--; y--; z--;
            g[x] = g[y] & g[z];
        } else if (ty == 4) {
            int x, v;
            cin >> x >> v; x--;
            int u = (g[x] & q_mp[v]).count() % 2;
            if (u) ans += "1";
            else ans += "0";
        } else {
            assert(false);
        }
    }
    cout << ans << endl;
    return 0;
}