#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxa = 1000010;
int n, a[maxn], mn[maxa];
vector<int> V[maxa];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 2; i < maxa; i++) if (!mn[i]) {
        for (int j = i; j < maxa; j += i) mn[j] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        while (x > 1) {
            int y = mn[x];
            V[y].push_back(i);
            while (!(x % y)) x /= y;
        }
    }
    vector<int> U = {0, 1};
    for (int i = 2; i < maxa; i++) {
        int c = (a[0] % i == 0) + (a[1] % i == 0);
        if (!c || V[i].empty()) continue;
        vector<int> occ(n);
        for (int j = 2; j < n; j++) {
            int x = a[j];
            while (!(x % i)) x /= i, occ[j]++;
        }
        vector<int> id(n - 2);
        iota(id.begin(), id.end(), 2);
        sort(id.begin(), id.end(), [&](int i, int j) { return occ[i] < occ[j]; });
        for (int j = 0; j < id.size() && j < c; j++) {
            U.push_back(id[j]);
        }
    }
    sort(U.begin(), U.end());
    U.resize(unique(U.begin(), U.end()) - U.begin());
    auto get = [&](int S) {
        long long g = 0;
        for (int i = 0; i < U.size(); i++) if (S >> i & 1) {
            for (int j = i + 1; j < U.size(); j++) {
                if (S >> j & 1) g = __gcd(g, 1LL * a[U[i]] * a[U[j]]);
            }
        }
        return g;
    };
    long long need = get((1 << U.size()) - 1);
    vector<int> b;
    for (int S = 1; S < 1 << U.size(); S++) if (get(S) == need) {
        if (__builtin_popcount(S) > 14) continue;
        for (int i = 0; i < U.size(); i++) {
            if (S >> i & 1) b.push_back(U[i]);
        }
        break;
    }
    vector<vector<int>> res;
    for (int S = 1; S < 1 << b.size(); S++) {
        int coef = (__builtin_parity(S) ? -1 : 1) * (__builtin_popcount(S) - 2);
        while (coef) {
            vector<int> V;
            if (coef > 0) V = {0}, coef--;
            else V = {1}, coef++;
            V.push_back(__builtin_popcount(S));
            for (int i = 0; i < b.size(); i++) {
                if (S >> i & 1) V.push_back(b[i] + 1);
            }
            res.push_back(V);
        }
    }
    cout << res.size() << "\n";
    for (auto &vec : res) {
        for (int x : vec) cout << x << " ";
        cout << "\n";
    }
    return 0;
}