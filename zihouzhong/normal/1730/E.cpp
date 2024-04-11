#include <bits/stdc++.h>
using namespace std;

const int C = 1e6;
vector<int> pos[C + 1], d[C + 1];

__attribute__((constructor)) void init() {
    for (int i = 1; i <= C; i++) {
        for (int j = i; j <= C; j += i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (auto &v : pos) {
        v.clear();
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vector<int> l(n), r(n);
    {
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
            l[i] = st.empty() ? 0 : st.back() + 1;
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; ~i; i--) {
            while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
            r[i] = st.empty() ? n - 1 : st.back() - 1;
            st.push_back(i);
        }
    }
    vector<int> pre(n);
    iota(pre.begin(), pre.end(), 0);
    auto nxt = pre;
    auto find1 = [&](int x) {
        while (x != pre[x]) x = pre[x] = pre[pre[x]];
        return x;
    };
    auto find2 = [&](int x) {
        while (x != nxt[x]) x = nxt[x] = nxt[nxt[x]];
        return x;
    };
    vector<bool> mark(n);
    long long ans = 0;
    for (int x = C; x; x--) if (!pos[x].empty()) {
        for (int y = x + x; y <= C; y += x) {
            for (int i : pos[y]) {
                int lb = max(find1(i), l[i]);
                int rb = min(find2(i), r[i]);
                ans -= 1LL * (i - lb + 1) * (rb - i + 1);
            }
        }
        for (int i : pos[x]) {
            mark[i] = 1;
            if (i && mark[i - 1]) pre[i]--, nxt[i - 1]++;
            if (i + 1 < n && mark[i + 1]) nxt[i]++, pre[i + 1]--;
        }
        for (int y = x; y <= C; y += x) {
            for (int i : pos[y]) {
                int lb = max(find1(i), l[i]);
                int rb = min(find2(i), r[i]);
                ans += 1LL * (i - lb + 1) * (rb - i + 1);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}