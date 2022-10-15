#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> cur(n), val;
    map<int, pair<int, set<int>>> mp;
    for (int i = 0; i < n; i++) {
        if (!mp.count(a[i])) {
            mp[a[i]].first = val.size();
            val.push_back(a[i]);
        }
        mp[a[i]].second.insert(i);
        cur[i] = mp[a[i]].first;
    }
    auto convert = [&](int x, int y) {
        if (!mp.count(y)) {
            mp[y].first = val.size();
            val.push_back(y);
        }
        auto &[id1, v1] = mp[x];
        auto &[id2, v2] = mp[y];
        if (v1.size() < v2.size()) {
            for (int x : v1) cur[x] = id2;
            v2.insert(v1.begin(), v1.end());
        } else {
            for (int x : v2) cur[x] = id1;
            v1.insert(v2.begin(), v2.end());
            val[id1] = y, swap(mp[x], mp[y]);            
        }
        mp.erase(x);
    };
    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y, x--;
            mp[val[cur[x]]].second.erase(x);
            if (!mp.count(y)) {
                mp[y].first = val.size();
                val.push_back(y);
            }
            mp[y].second.insert(x);
            cur[x] = mp[y].first;
        } else if (op == 2) {
            x--;
            cout << val[cur[x]] << "\n";
        } else {
            cin >> y;
            int mid = (x + y) / 2;
            while (1) {
                auto it = mp.lower_bound(x);
                if (it == mp.end() || it->first > y) break;
                convert(it->first, it->first <= mid ? x - 1 : y + 1);
            }
        }
    }
    return 0;
}