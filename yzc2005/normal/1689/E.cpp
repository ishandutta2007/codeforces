#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
pair<int, vector<int>> solve(vector<int> a) {
    vector<int> par(30, -1);
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    };
    auto merge = [&](int u, int v) {
        u = find(u);
        v = find(v);
        if (u < v) {
            swap(u, v);
        }
        par[u] = v;
    }; 
    for (auto x : a) {
        for (int i = 0, j = -1; i < 30; ++i) {
            if (x >> i & 1) {
                if (par[i] == -1) {
                    par[i] = i;
                }
                if (~j) {
                    merge(i, j);
                }
                j = i;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 30; ++i) {
        if (par[i] == i) {
            ++ans;
        }
    }
    if (ans == 1 && par[0] == -1) {
        return make_pair(0, a);
    }
    for (int i = 1; i < 30; ++i) {
        if (par[i] == i) {
            for (auto &x : a) {
                if (x >> i & 1) {
                    ++x;
                    break;
                }
            }
        }
    }
    return make_pair(ans, a);
}
void solve() {
    int n, offset = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for (auto &x : a) {
        scanf("%d", &x);
        if (x == 0) {
            ++x;
            ++offset;
        }
    }
    auto ans = solve(a);
    --ans.first;
    for (auto &x : a) {
        if (x > 1) {
            --x;
            ans = min(ans, solve(a));
            ++x;
        }        
    }
    ++ans.first;
    printf("%d\n", offset + ans.first);
    for (auto x : ans.second) {
        cout << x << " ";
    }
    cout << "\n";
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0; 
}