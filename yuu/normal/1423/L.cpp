#include <bits/stdc++.h>

using namespace std;

using bs = bitset<1024>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, S, D; cin >> N >> S >> D;
    vector<bs> basis(N);
    vector<int> xr(N);
    vector<int> go;
    int idx = 0;
    for (int s = 0; s < S; ++s) {
        int M; cin >> M;
        bs cur{};
        while (M--) {
            int z; cin >> z;
            cur.set(--z);
        }
        int v = 0;
        bool ok = false;
        while (cur.count()) {
            int i = cur._Find_first();
            if (basis[i].count()) {
                cur ^= basis[i];
                v ^= xr[i];
            } else {
                basis[i] = cur;
                xr[i] = v | (1 << idx++);
                ok = true;
                break;
            }
        }
        if (!ok) go.emplace_back(v);
    }
    vector<int> ppc(1 << 15);
    for (int i = 1; i < 1<<15; ++i) ppc[i] = ppc[i>>1]+(i&1);
    const int B = 15;
    vector<pair<int, int>> options;
    vector<int> ans;
    int sz = go.size();
    if (sz <= B) {
        function<void(int, int, int)> rec = [&](int i, int ad, int xr) {
            if (i == go.size()) options.emplace_back(ad, xr);
            else {
                rec(i+1, ad, xr);
                rec(i+1, ad+1, xr^go[i]);
            }
        };
        rec(0, 0, 0);
    } else {
        int Z = idx;
        ans.resize(1 << Z);
        for (int i = 0; i < (1 << Z); ++i) ans[i] = ppc[i];
        for (int v : go) {
            vector<int> nans = ans;
            for (int i = 0; i < (1<<Z); ++i) {
                nans[i ^ v] = min(nans[i ^ v], ans[i] + 1);
            }
            ans.swap(nans);
        }
    };
    auto pop = [&](int x) {
        return ppc[x >> 15] + ppc[x & ((1 << 15) - 1)];
    };
    while (D--) {
        int K; cin >> K;
        bs cur{};
        while (K--) {
            int z; cin >> z;
            cur.set(--z);
        }
        bool fail = false;
        int msk = 0;
        while (cur.count()) {
            int i = cur._Find_first();
            if (!basis[i].count()) {
                fail = true;
                break;
            } else {
                cur ^= basis[i];
                msk ^= xr[i];
            }
        }
        if (fail) {
            cout << "-1\n";
        } else if (sz <= B) {
            int ret = S;
            for (auto z : options) ret = min(ret, z.first + pop(z.second ^ msk));
            cout << ret << '\n';
        } else {
            cout << ans[msk] << '\n';
        }
    }
}