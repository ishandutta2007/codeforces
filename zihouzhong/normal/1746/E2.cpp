#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> corr, wrong;
    corr.emplace_back(0, n - 1);
    auto test = [&](int i) {
        cout << "! " << i + 1 << endl;
        string bit;
        cin >> bit;
        if (bit == ":)") exit(0);
    };
    auto ask = [&](vector<int> val) {
        cout << "? " << val.size();
        for (int x : val) {
            cout << " " << x + 1;
        }
        cout << endl;
        string bit;
        cin >> bit;
        return bit;
    };
    while (1) {
        int sz_corr = 0, sz_wrong = 0;
        for (auto [x, y] : corr) {
            sz_corr += y - x + 1;
        }
        for (auto [x, y] : wrong) {
            sz_wrong += y - x + 1;
        }
        if (sz_corr + sz_wrong <= 2) break;
        int need_wrong = sz_wrong / 2;
        int need_corr = (sz_corr + sz_wrong % 2 + 1) / 2;
        vector<pair<int, int>> corr1, corr0, wrong1, wrong0;
        for (auto [x, y] : corr) {
            if (!need_corr) {
                corr0.emplace_back(x, y);
            } else if (y - x + 1 <= need_corr) {
                corr1.emplace_back(x, y);
                need_corr -= y - x + 1;
            } else {
                corr1.emplace_back(x, x + need_corr - 1);
                corr0.emplace_back(x + need_corr, y);
                need_corr = 0;
            }
        }
        for (auto [x, y] : wrong) {
            if (!need_wrong) {
                wrong0.emplace_back(x, y);
            } else if (y - x + 1 <= need_wrong) {
                wrong1.emplace_back(x, y);
                need_wrong -= y - x + 1;
            } else {
                wrong1.emplace_back(x, x + need_wrong - 1);
                wrong0.emplace_back(x + need_wrong, y);
                need_wrong = 0;
            }
        }
        vector<int> val;
        for (auto [x, y] : corr1) {
            for (int i = x; i <= y; i++) val.push_back(i);
        }
        for (auto [x, y] : wrong1) {
            for (int i = x; i <= y; i++) val.push_back(i);
        }
        if (ask(val) == "YES") {
            corr = corr1;
            corr.insert(corr.end(), wrong1.begin(), wrong1.end());
            wrong = corr0;
        } else {
            corr = corr0;
            corr.insert(corr.end(), wrong0.begin(), wrong0.end());
            wrong = corr1;
        }
    }
    for (auto [x, y] : corr) {
        for (int i = x; i <= y; i++) test(i);
    }
    for (auto [x, y] : wrong) {
        for (int i = x; i <= y; i++) test(i);
    }
    return 0;
}