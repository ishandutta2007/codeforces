#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int L = 10, val[7] = {0b1011111100, 0b0010100010, 0b1110000101,
        0b1101100011, 0b1100101100, 0b1111100101, 0b0101001101};
    map<vector<int>, int> mp[7];
    for (int i = 0; i < 7; i++) {
        for (int S = 0; S < 1 << L; S++) {
            vector<int> arr;
            for (int j = 0; j <= i; j++) {
                arr.push_back(__builtin_popcount(S & val[j]));
            }
            mp[i][arr] = mp[i].count(arr) ? -1 : S;
        }
    }
    auto ask = [&](const vector<int> &v) {
        string s(n, 'F');
        for (int i : v) s[i] = 'T';
        cout << s << endl;
        int x;
        if (cin >> x, x == n) exit(0);
        return x;
    };
    int o = ask({});
    vector<int> p(n), res;
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), mt19937(time(0)));
    auto solve = [&](int l, int r) {
        vector<int> arr;
        for (int i = 0; i < 7; i++) {
            vector<int> a;
            for (int j = 0; l + j <= r; j++) {
                if (val[i] >> j & 1) a.push_back(p[l + j]);
            }
            arr.push_back((ask(a) - o + a.size()) / 2);
            int S = mp[i][arr];
            if (!~S) continue;
            for (int j = 0; l + j <= r; j++) {
                if (S >> j & 1) res.push_back(p[l + j]);
            }
            break;
        }
    };
    for (int i = 0; i < n; i += L) {
        solve(i, min(n - 1, i + L - 1));
    }
    ask(res);
    return 0;
}