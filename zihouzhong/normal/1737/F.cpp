#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(const vector<int> &b) {
    if (*max_element(b.begin(), b.end()) > 3) return {};
    int c3 = count(b.begin(), b.end(), 3);
    if (c3 >= 2) return {};
    int c2 = count(b.begin(), b.end(), 2);
    if (c3 >= 1 && c2 >= 1) return {};
    int c1 = count(b.begin(), b.end(), 1);
    if (c3 == 1) {
        vector<vector<int>> res{{2}, {1}, {3}};
        int n = 1;
        while (c1--) {
            n++;
            for (int i = 0; i < res.size(); i++) {
                res[i].push_back(i % 2);
            }
            auto _res = res;
            vector<int> e(n), o(n);
            e[n - 1] = o[0] = 1;
            _res.push_back(e);
            for (auto &v : res) {
                v.back() = 1 - v.back();
            }
            _res.insert(_res.end(), res.begin(), res.end());
            int p = find(_res.begin(), _res.end(), e) - _res.begin();
            int q = find(_res.begin(), _res.end(), o) - _res.begin();
            swap(_res[p], _res[q]);
            swap(res, _res);
        }
        for (auto &v : res) {
            reverse(v.begin(), v.end());
        }
        return res;
    }
    if (c2 >= 3) return {};
    vector<vector<int>> res;
    if (c2 == 2) res = {{2, 2}, {1, 0}, {2, 1}, {0, 2}, {1, 1}, {2, 0},
        {1, 2}, {0, 1}};
    if (c2 == 1) res = {{2}, {1}};
    while (c1--) {
        auto _res = res;
        reverse(res.begin(), res.end());
        _res.insert(_res.end(), res.begin(), res.end());
        for (int i = 0; i < _res.size(); i++) {
            _res[i].push_back(i % 2);
        }
        int n = _res.size() ? _res[0].size() : 1;
        vector<int> e(n);
        e[n - 1] = 1;
        _res.push_back(e);
        swap(res, _res);
    }
    for (auto &v : res) {
        reverse(v.begin(), v.end());
    }
    return res;
}

void solve() {
    int m;
    cin >> m;
    vector<pair<int, int>> bp(m);
    for (int i = 0; i < m; i++) {
        cin >> bp[i].first;
        bp[i].second = i;
    }
    sort(bp.begin(), bp.end());
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        b[i] = bp[i].first;
    }
    auto ansp = solve(b);
    if (ansp.empty()) {
        cout << "-1\n";
        return;
    }
    auto ans = ansp;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < m; j++) {
            ans[i][bp[j].second] = ansp[i][j];
        }
        for (int x : ans[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}