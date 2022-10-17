#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve0(int n, const vector<vector<int>> &tmp) {
    if (n == 0) {
        return tmp;
    }
    
    auto b = solve0(n - 1, tmp);
    auto a = b;
    for (int i = (int) b.size() - 1; i >= 0; --i) {
        a.push_back(b[i]);
    }

    for (int i = 0; i < (int) a.size(); ++i) {
        a[i].push_back(i & 1);
    }
    a.push_back(vector<int>(a.back().size(), 0));
    a.back().back() = 1;

    return a;
}

vector<vector<int>> solve2(int n, const vector<vector<int>> &tmp) {
    if (n == 0) {
        return tmp;
    }

    auto b = solve2(n - 1, tmp);
    auto a = b;
    a.push_back(vector<int>(a.back().size(), 0));
    for (int i = 0; i < (int) b.size(); ++i) {
        a.push_back(b[i]);
    }

    swap(a[b.size()], a[b.size() + (b.size() + 1) / 2]);
    for (int i = 0, j = a.size() - 1; i < (int) b.size(); ++i, --j) {
        a[i].push_back(i & 1);
        a[j].push_back(!(i & 1));
    }
    a[b.size()].push_back(0);
    a[b.size() + (b.size() + 1) / 2].back() = 1;

    return a;
} 

vector<vector<int>> solve1(int n, const vector<vector<int>> &tmp) {
    if (n == 0) {
        return tmp;
    }

    auto b = solve1(n - 1, tmp);

    if (n == 1) {
        vector<vector<int>> a;
        for (int i = 0; i < (int) b.size(); ++i) {
            a.push_back(b[i])   ;
            a.back().push_back(!(i & 1));
        }
        for (int i = 0; i < (int) b.size(); ++i) {
            a.push_back(b[i]);
            a.back().push_back(i & 1);
        }
        
        a.push_back(vector<int>(a.back().size(), 0));
        a.back().back() = 1;

        return a;
    } else {
        auto a = b;
        for (int i = (int) b.size() - 1; i >= 0; --i) {
            a.push_back(b[i]);
        }

        for (int i = 0; i < (int) a.size(); ++i) {
            a[i].push_back(i & 1);
        }
        a.push_back(vector<int>(a.back().size(), 0));
        a.back().back() = 1;

        return a;
    }
}

void solve() {
    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    vector<int> rev(m);
    for (int i = 0; i < m; ++i) {
        rev[ord[i]] = i;
    }

    vector<vector<int>> ans;

    sort(b.begin(), b.end());
    if (b.back() == 1) {
        ans = solve0(m - 1, {{1}});
    } else if (b.back() >= 4) {
        cout << "-1\n";
        return;
    } else if (b.back() == 3) {
        if (m > 1 && b[m - 2] != 1) {
            cout << "-1\n";
            return;
        }
        ans = solve2(m - 1, {{3}, {1}, {2}});
    } else if (b.back() == 2) {
        if (m > 2 && b[m - 3] != 1) {
            cout << "-1\n";
            return;
        }
        if (m > 1 && b[m - 2] == 2) {
            ans = solve1(m - 2, {{1, 2}, {0, 1}, {2, 2}, {1, 0}, {2, 1}, {0, 2}, {1, 1}, {2, 0}});
        } else {
            ans = solve1(m - 1, {{1}, {2}});
        }
    }

    for (auto a : ans) {
        reverse(a.begin(), a.end());
        for (int i = 0; i < m; ++i) {
            cout << a[rev[i]] << " \n"[i == m - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}