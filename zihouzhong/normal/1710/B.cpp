#include <bits/stdc++.h>
using namespace std;

template <class comp> struct rmq {
    vector<vector<long long>> st;
    rmq(const vector<long long> &arr) : st(__lg(arr.size()) + 1) {
        st[0] = arr;
        for (int k = 1; k < st.size(); k++) {
            st[k] = st[k - 1];
            for (int i = 0; i + (1 << k) <= st[k].size(); i++) {
                long long x = st[k - 1][i + (1 << (k - 1))];
                st[k][i] = comp()(st[k][i], x) ? st[k][i] : x;
            }
        }
    }

    long long query(int l, int r) {
        int k = __lg(r - l + 1);
        long long x = st[k][l], y = st[k][r - (1 << k) + 1];
        return comp()(x, y) ? x : y;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> a(n);
        vector<int> val;
        for (auto &p : a) {
            cin >> p[0] >> p[1];
            val.push_back(p[0] - p[1]);
            val.push_back(p[0]);
            val.push_back(p[0] + p[1]);
        }
        sort(val.begin(), val.end());
        val.resize(unique(val.begin(), val.end()) - val.begin());
        vector<int> inc(val.size());
        for (auto &p : a) {
            int i = lower_bound(val.begin(), val.end(), p[0] - p[1]) - val.begin();
            int j = lower_bound(val.begin(), val.end(), p[0]) - val.begin();
            int k = lower_bound(val.begin(), val.end(), p[0] + p[1]) - val.begin();
            inc[i]++, inc[j] -= 2, inc[k]++;
        }
        partial_sum(inc.begin(), inc.end(), inc.begin());
        vector<long long> sum(inc.size()), pre(inc.size());
        long long cur = 0, mx = 0;
        for (int i = 0; i + 1 < inc.size(); i++) {
            cur += 1LL * inc[i] * (val[i + 1] - val[i]);
            mx = max(mx, cur);
            sum[i] = cur, pre[i] = mx;
        }
        vector<long long> suf(inc.size());
        for (int i = (int)inc.size() - 2; ~i; i--) {
            suf[i] = max(suf[i + 1], sum[i]);
        }
        vector<long long> x;
        for (int i = 0; i + 1 < inc.size(); i++) {
            x.push_back(sum[i] - val[i + 1]);
        }
        rmq<greater<>> T1(x);
        for (int i = 0; i + 1 < inc.size(); i++) {
            x[i] = sum[i] + val[i + 1];
        }
        rmq<greater<>> T2(x);
        for (auto &p : a) {
            int i = lower_bound(val.begin(), val.end(), p[0] - p[1]) - val.begin();
            int j = lower_bound(val.begin(), val.end(), p[0]) - val.begin();
            int k = lower_bound(val.begin(), val.end(), p[0] + p[1]) - val.begin();
            long long mx = i ? pre[i - 1] : 0;
            mx = max(mx, T1.query(i, j - 1) + val[i]);
            mx = max(mx, T2.query(j, k - 1) - 2 * val[j] + val[i]);
            mx = max(mx, suf[k]);
            cout << (mx <= m ? "1" : "0");
        }
        cout << "\n";
    }
    return 0;
}