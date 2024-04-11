// test
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 2e18;
mt19937_64 eng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100005;
int n, d, q, x[N];
char s[N];

struct query {
    int t, k, id;
    bool operator < (const query &rhs) const {
        return t > rhs.t;
    }
};
ll ans[N];

int root, tot, ch[N][2], siz[N];
ll pri[N], val[N], sum[N];

void push_up(int p) {
    siz[p] = siz[ch[p][0]] + siz[ch[p][1]] + 1;
    sum[p] = sum[ch[p][0]] + sum[ch[p][1]] + val[p];
}

void split_sum(int p, ll k, int &x, int &y) {
    if (!p) {
        x = y = 0;
        return;
    }
    ll cur = sum[p] - sum[ch[p][1]];
    if (cur <= k) {
        x = p;
        split_sum(ch[p][1], k - cur, ch[x][1], y);
    } else {
        y = p;
        split_sum(ch[p][0], k, x, ch[y][0]);
    }
    push_up(p);
}

void split_size(int p, int k, int &x, int &y) {
    if (!p) {
        x = y = 0;
        return;
    }
    int cur = siz[p] - siz[ch[p][1]];
    if (cur <= k) {
        x = p;
        split_size(ch[p][1], k - cur, ch[x][1], y);
    } else {
        y = p;
        split_size(ch[p][0], k, x, ch[y][0]);
    }
    push_up(p);
}

int merge(int p, int q) {
    if (!p || !q) {
        return p | q;
    }
    if (pri[p] > pri[q]) {
        ch[p][1] = merge(ch[p][1], q);
        push_up(p);
        return p;
    } else {
        ch[q][0] = merge(p, ch[q][0]);
        push_up(q);
        return q;
    }
}

int new_node(ll x) {
    int u = ++tot;
    val[u] = sum[u] = x;
    siz[u] = 1;
    pri[u] = eng();
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    cin >> s;

    vector<ll> a, b;
    int offset = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '0') {
            ++offset;
            b.push_back(x[i] - offset);
        } else {
            a.push_back(x[i] - offset);
        }
    }
    a.push_back(inf);
    a.push_back(inf * 2);

    vector<query> queries;
    for (int i = 1; i <= q; ++i) {
        int t, k;
        cin >> t >> k;
        queries.push_back({t, k, i});
    }
    sort(queries.begin(), queries.end());

    ll pos = a[0] - d;
    root = new_node(d);
    ll cur = 0;

    auto get_rk = [&](ll x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };

    auto calc = [&](ll cur_val, int k) {
        int u = root;
        int cur = 0;
        int len = siz[root];
        while (u) {
            int nxt = cur + siz[ch[u][0]] + 1;
            ll nxt_val = cur_val + sum[ch[u][0]] + val[u];
            if (nxt + get_rk(nxt_val) <= k) {
                cur = nxt;
                cur_val = nxt_val;
                u = ch[u][1];
            } else {
                u = ch[u][0];
            }
        }

        int pos = cur;
        ll pos_val = pos ? cur_val : -1;

        if (pos == len) {
            int l = len, r = a.size() - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (mid + 1 + get_rk(a[mid]) <= k) {
                    pos = mid + 1;
                    pos_val = a[mid];
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return max(pos_val, (b.empty() || pos == k) ? -1 : b[k - pos - 1]) + k - pos;
    };

    for (int len = 1; len < (int) a.size() && !queries.empty(); ) {
        ll round = (a[len] - 1 - pos) / (d + len - 1) - 1;

        while (!queries.empty()) {
            auto tmp = queries.back();
            ll rr = tmp.t - cur;
            if (rr > round * len) {
                break;
            }
            queries.pop_back();
            ll pos1 = pos + (rr / len) * (d + len - 1);
            int x, y;
            split_size(root, rr % len, x, y);
            pos1 += sum[x];
            root = merge(y, x);
            ans[tmp.id] = calc(pos1, tmp.k);
            split_size(root, len - rr % len, y, x);
            root = merge(x, y);
        }

        cur += round * len;
        pos += round * (d + len - 1);

        while (!queries.empty()) {
            auto tmp = queries.back();
            ll rr = tmp.t - cur;
            if (rr >= len) {
                break;
            }
            int x, y;
            split_size(root, rr, x, y);
            if (pos + sum[x] + d + len - 1 >= a[len]) {
                root = merge(x, y);
                break;
            }
            queries.pop_back();
            ll pos1 = pos + sum[x];
            root = merge(y, x);
            ans[tmp.id] = calc(pos1, tmp.k);
            split_size(root, len - rr, y, x);
            root = merge(x, y);
        }

        if (len == (int) a.size() - 1) {
            break;
        }

        int x, y;
        split_sum(root, a[len] - 1 - (pos + d + len - 1), x, y);
        cur += siz[x];
        pos += sum[x];
        root = merge(y, x);

        split_size(root, 1, x, y);
        pos += val[x];
        ll last = pos + sum[y];
        ++cur;
        while (pos + d + len - 1 >= a[len]) {
            int z = new_node(a[len] - last);
            y = merge(y, z);
            last = a[len++];
        }
        val[x] = sum[x] = pos + d + len - 1 - last;
        root = merge(y, x);

        while (!queries.empty()) {
            auto tmp = queries.back();
            if (tmp.t > cur) {
                break;
            }
            queries.pop_back();
            ans[tmp.id] = calc(pos, tmp.k);
        }
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}