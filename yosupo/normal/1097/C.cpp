#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

int check(string s) {
    int he = 0;
    for (char c: s) {
        if (c == '(') he++;
        else he--;
        if (he < 0) return -1;
    }
    return he;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int zero = 0;
    using P = pair<int, int>;
    map<int, P> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int u = check(s);
        if (u == 0) {
            zero++;
            continue;
        }
        if (u != -1) {
            mp[u].first++;
            continue;
        }
        reverse(s.begin(), s.end());
        string t;
        for (char c: s) {
            if (c == '(') t.push_back(')');
            else t.push_back('(');
        }
        u = check(t);
        if (u != -1) {
            mp[u].second++;
            continue;
        }
    }

    int ans = zero / 2;
    for (auto p: mp) {
        ans += min(p.second.first, p.second.second);
    }
    cout << ans << endl;
    return 0;
}