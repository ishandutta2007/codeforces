#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    mt19937_64 mt(114514);
    ull hs[100][5];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            hs[i][j] = mt();
        }
    }
    int n, m;
    cin >> n >> m;
    map<ull, int> mp;
    for (int ph = 0; ph < n; ph++) {
        string s;
        cin >> s;
        int k = int(s.size());
        ull h = 0;
        for (int i = 0; i < k; i++) {
            h ^= hs[i][s[i] - 'a'];
        }
        mp[h]++;
    }

    for (int ph = 0; ph < m; ph++) {
        string s;
        cin >> s;
        int k = int(s.size());
        set<ull> used;
        function<int(int, int, ull)> dfs = [&](int p, int i, ull h) {
            if (p == k) {
                if (used.count(h)) return 0;
                used.insert(h);
                return mp[h];
            }
            if (s[p] != '?') return dfs(p+1, i+1, h ^ hs[i][s[p] - 'a']);
            int ans = dfs(p+1, i, h);
            for (char c = 'a'; c <= 'e'; c++) {
                ans += dfs(p+1, i+1, h ^ hs[i][c - 'a']);
            }
            return ans;
        };
        cout << dfs(0, 0, 0) << endl;
    }
    return 0;
}