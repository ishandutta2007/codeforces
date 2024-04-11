#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int &x : a) cin >> x;
        auto chk = [&](int t, int need) {
            vector<int> b;
            for (int x : a) {
                if (x >= 2 * t) b.push_back(x / t);
            }
            sort(b.begin(), b.end(), greater<>());
            long long sum = 0;
            for (int i = 0; i < b.size(); i++) {
                sum += b[i];
                if (2 * (i + 1) <= need && need <= sum) return 1;
            }
            return 0;
        };
        if (chk(n, m) || chk(m, n)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}