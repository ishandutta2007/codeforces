#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> res(30);
    for (int i = 0; i < 30; i++) {
        vector<pair<int, int>> ev;
        for (int j = 0; j < n; j++) {
            if (r[j] - l[j] + 1 >= (1 << i)) {
                ev.emplace_back(0, 1);
            } else {
                int x = l[j] % (1 << i), y = r[j] % (1 << i);
                if (x <= y) {
                    ev.emplace_back(x, 1);
                    ev.emplace_back(y + 1, -1);
                } else {
                    ev.emplace_back(0, 1);
                    ev.emplace_back(y + 1, -1);
                    ev.emplace_back(x, 1);
                }
            }
        }
        sort(ev.begin(), ev.end());
        int cur = 0;
        for (auto &[_, v] : ev) {
            res[i] = max(res[i], cur += v);
        }
    }
    cin >> q;
    while (q--) {
        int w;
        cin >> w;
        cout << res[__builtin_ctz(w)] << "\n";
    }
    return 0;
}