#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> b(n + 1);
        vector<vector<pair<int, int>>> V(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            int l, r;
            if (!b[i]) {
                l = i + 1, r = n;
            } else {
                l = i / (b[i] + 1) + 1, r = i / b[i];
            }
            V[l].emplace_back(r, i);
        }
        vector<int> a(n + 1);
        set<pair<int, int>> S;
        for (int i = 1; i <= n; i++) {
            for (auto &p : V[i]) S.insert(p);
            a[S.begin()->second] = i, S.erase(S.begin());
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}