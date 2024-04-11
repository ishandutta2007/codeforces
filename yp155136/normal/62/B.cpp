#include <bits/stdc++.h>
using namespace std;

vector<int> v[26];

int Q(int id, int pos, int sz) {
    if (v[id].empty()) return sz;
    auto iter = lower_bound(v[id].begin(), v[id].end(), pos);
    int ret = 1111111;
    if (iter != v[id].end()) {
        ret = min(ret, *iter - pos);
    }
    if (iter != v[id].begin()) {
        --iter;
        ret = min(ret, pos - *iter);
    }
    return ret;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        v[ s[i] - 'a' ].push_back(i);
    }
    while (n--) {
        string t; cin >> t;
        long long ans = 0;
        for (int i = 0; i < (int)t.size(); ++i) {
            ans += Q(t[i] - 'a', i, t.size());
        }
        cout << ans << '\n';
    }
}