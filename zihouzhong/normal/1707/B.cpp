#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<array<int, 2>> V, _V;
        for (int i = 0; i + 1 < n; i++) {
            V.push_back({a[i + 1] - a[i], 1});
        }
        for (int $ = 1; $ < n; $++) {
            _V.clear(), sort(V.begin(), V.end());
            for (auto &p : V) {
                if (_V.empty() || p[0] > _V.back()[0]) _V.push_back(p);
                else _V.back()[1] += p[1];
            }
            swap(V, _V);
            if ($ == n - 1) {
                cout << V[0][0] << "\n"; break;
            }
            _V.clear();
            for (int i = 0; i < V.size(); i++) {
                if (i) _V.push_back({V[i][0] - V[i - 1][0], 1});
                if (V[i][1] > 1) _V.push_back({0, V[i][1] - 1});
            }
            swap(V, _V);
        }
    }
    return 0;
}