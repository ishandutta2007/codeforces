#include <bits/stdc++.h>
#include <ostream>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

// s[0..res[i]] == s[i..i+res[i]]
template <class S> V<int> z_algo(const S& s) {
    int n = int(s.size());
    V<int> R(n + 1);
    R[0] = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        int& k = R[i];
        k = (j + R[j] <= i) ? 0 : min(j + R[j] - i, R[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + R[j] < i + R[i]) j = i;
    }
    R[0] = n;
    return R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    V<string> w0(n), w1(n);
    for (int i = 0; i < n; i++) {
        cin >> w0[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w1[i];
    }
    V<int> st(n), ed(n);
    for (int i = 0; i < n; i++) {
        int m = int(w0[i].size());
        st[i] = m; ed[i] = -1;
        for (int j = 0; j < m; j++) {
            if (w0[i][j] != w1[i][j]) {
                st[i] = min(st[i], j);
                ed[i] = max(ed[i], j);
            }
        }
    }
    while (true) {
        bool ok = true;
        char c0 = '$', c1 = '$';
        for (int i = 0; i < n; i++) {
            int m = int(w0[i].size());
            if (st[i] == m) continue;
            if (!st[i]) {
                ok = false;
                break;
            }
            if (c0 != '$' && (c0 != w0[i][st[i]-1] || c1 != w1[i][st[i]-1])) {
                ok = false;
                break;
            }
            c0 = w0[i][st[i]-1];
            c1 = w1[i][st[i]-1];
        }
        if (!ok) break;
        for (int i = 0; i < n; i++) {
            int m = int(w0[i].size());
            if (st[i] == m) continue;
            st[i]--;
        }
    }
    while (true) {
        bool ok = true;
        char c0 = '$', c1 = '$';
        for (int i = 0; i < n; i++) {
            int m = int(w0[i].size());
            if (ed[i] == -1) continue;
            if (ed[i] == m-1) {
                ok = false;
                break;
            }
            if (c0 != '$' && (c0 != w0[i][ed[i]+1] || c1 != w1[i][ed[i]+1])) {
                ok = false;
                break;
            }
            c0 = w0[i][ed[i]+1];
            c1 = w1[i][ed[i]+1];
        }
        if (!ok) break;
        for (int i = 0; i < n; i++) {
            if (ed[i] == -1) continue;
            ed[i]++;
        }
    }

    string pred0, pred1;
    for (int i = 0; i < n; i++) {
        int m = int(w0[i].size());
        if (st[i] == m) continue;
        pred0 = w0[i].substr(st[i], ed[i] - st[i] + 1);
        pred1 = w1[i].substr(st[i], ed[i] - st[i] + 1);
        break;
    }
    int k = int(pred0.size());
    //cerr << pred0 << " " << pred1 << endl;
    for (int i = 0; i < n; i++) {
        int m = int(w0[i].size());
        auto u = z_algo(pred0 + w0[i]);
        int w = -1;
        for (int j = k; j < k+m; j++) {
            if (u[j] >= k) {
                w = j - k;
                break;
            }
        }
        string x = w0[i];
        if (w != -1) {
            x = w0[i].substr(0, w) + pred1 + w0[i].substr(w + k);
        }
        if (x != w1[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << pred0 << endl;
    cout << pred1 << endl;
    return 0;
}