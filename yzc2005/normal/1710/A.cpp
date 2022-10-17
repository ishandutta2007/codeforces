#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }
        auto check = [&]() {
            long long sum = 0;
            vector<int> b;
            for (auto x : a) {
                int val = x / m;
                if (val < 2) {
                    continue;
                }
                b.push_back(val);
            }
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            for (int i = 0; i < (int) b.size() && (i + 1) * 2 <= n; ++i) {
                sum += b[i];
                if (sum >= n) {
                    return true;
                }
            }
            return false;
        };
        bool f = check();
        swap(n, m);
        f |= check();
        if (f) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}