#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mid ((l + r) / 2)
#define ls (k << 1)
#define rs (k << 1 | 1)
namespace SEG {
vector<vector<pair<int, int>>> mn;
void init(int n) { mn.resize(4 * n); }

void ins(int k, int l, int r, int p, pair<int, int> v) {
    while (!mn[k].empty() && mn[k].back().first <= v.first) {
        mn[k].pop_back();
    }
    mn[k].push_back(v);
    if (l == r) return;
    mid >= p ? ins(ls, l, mid, p, v) : ins(rs, mid + 1, r, p, v);
}

pair<int, int> query(int k, int l, int r, int ql, int qr, int lim) {
    pair res{INT_MAX, 0};
    if (l >= ql && r <= qr) {
        auto it = lower_bound(mn[k].rbegin(), mn[k].rend(), make_pair(lim, 0));
        if (it != mn[k].rend()) return pair{it->second, it->first};
        return res;
    }
    if (mid >= ql) res = query(ls, l, mid, ql, qr, lim);
    if (mid < qr) res = min(res, query(rs, mid + 1, r, ql, qr, lim));
    return res;
}
} // namespace SEG

namespace SEG2 {
vector<int> mn, tag;
void init(int n) { mn.resize(4 * n), tag = mn; }

void apply(int k, int v) {
    mn[k] += v, tag[k] += v;
}

void pushdown(int k) {
    if (tag[k]) apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) return apply(k, v);
    pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    mn[k] = min(mn[ls], mn[rs]);
}

int find_l(int k, int l, int r, int p) {
    if (mn[k]) return -1;
    if (l == r) return l;
    pushdown(k);
    if (mid >= p) {
        int t = find_l(ls, l, mid, p);
        if (~t) return t;
    }
    return find_l(rs, mid + 1, r, p);
}
} // namespace SEG

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> g(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> c[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }
    vector<ll> ps(d.begin(), d.end());
    partial_sum(ps.begin(), ps.end(), ps.begin());
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        val[i] = (ps[i] + c[i]) % t;
    }
    auto foo = val;
    sort(foo.begin(), foo.end());
    foo.resize(unique(foo.begin(), foo.end()) - foo.begin());
    SEG::init(foo.size());
    vector<ll> need(n);
    for (int i = n - 1; ~i; i--) {
        int pos = lower_bound(foo.begin(), foo.end(), val[i]) - foo.begin();
        auto mn = SEG::query(1, 0, foo.size() - 1, pos, foo.size() - 1, val[i]);
        if (pos) {
            mn = min(mn, SEG::query(1, 0, foo.size() - 1, 0, pos - 1, val[i] - t));
        }
        int j = mn.first;
        if (j != INT_MAX) {
            need[i] = ps[j] - ps[i] + t - (val[j] - val[i] + t) % t + need[j];
        } else {
            need[i] = ps.back() - ps[i];
        }
        SEG::ins(1, 0, foo.size() - 1, pos, pair{val[i] - g[i], i});
    }
    auto bar = val;
    bar.insert(bar.end(), {0, t - 1});
    for (int i = 0; i < n; i++) {
        bar.push_back(max(0, min(t - 1, val[i] - 1)));
        bar.push_back(max(0, min(t - 1, val[i] + 1)));
        bar.push_back(max(0, min(t - 1, val[i] - g[i])));
        bar.push_back(max(0, min(t - 1, val[i] - g[i] + 1)));
        bar.push_back(max(0, min(t - 1, val[i] - g[i] + 2)));
        bar.push_back(max(0, min(t - 1, val[i] - g[i] + t)));
        bar.push_back(max(0, min(t - 1, val[i] - g[i] + t + 1)));
        bar.push_back(max(0, min(t - 1, val[i] - g[i] + t + 2)));
    }
    sort(bar.begin(), bar.end());
    bar.resize(unique(bar.begin(), bar.end()) - bar.begin());
    SEG2::init(bar.size());
    ll ans = LLONG_MAX;
    for (int i = 0; i < n && !SEG2::mn[1]; i++) {
        int offset = SEG2::find_l(1, 0, bar.size() - 1, 0);
        int r = bar[offset];
        if (r <= val[i] && val[i] - r >= g[i]) {
            ans = min(ans, ps[i] + t - (val[i] - r) + need[i]);
        }
        int pos = upper_bound(bar.begin(), bar.end(), val[i]) - bar.begin();
        offset = SEG2::find_l(1, 0, bar.size() - 1, pos);
        if (~offset) {
            int r = bar[offset];
            if (r > val[i] && val[i] - r + t >= g[i]) {
                ans = min(ans, ps[i] + t - (val[i] - r + t) + need[i]);
            }
        }
        pos = upper_bound(bar.begin(), bar.end(), val[i] - g[i]) - bar.begin();
        if (pos) SEG2::add(1, 0, bar.size() - 1, 0, pos - 1, 1);
        pos = upper_bound(bar.begin(), bar.end(), val[i]) - bar.begin();
        int pos2 = upper_bound(bar.begin(), bar.end(), val[i] - g[i] + t) - bar.begin();
        if (pos < pos2) SEG2::add(1, 0, bar.size() - 1, pos, pos2 - 1, 1);
    }
    if (!SEG2::mn[1]) {
        ans = min(ans, ps.back());
    }
    cout << ans << "\n";
    return 0;
}