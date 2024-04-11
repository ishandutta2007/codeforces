#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000006;

struct BIT {
    ll a[N];
    int n;
    void init(int _n) {
        memset(a, 0, sizeof(a));
        n = _n + 2;
    }
    void update(int pos, int val) {
        pos += 1;
        for (int i = pos; i <= n; i += i & (-i)) {
            a[i] += val;
        }
    }
    ll query(int pos) {
        ll ret = 0;
        for (int i = pos; i > 0; i -= i & (-i)) {
            ret += a[i];
        }
        return ret;
    }
    ll queryLR(int l, int r) {
        ++l, ++r;
        return query(r) - query(l - 1);
    }
} bit;

typedef pair<int, int> pii;
#define F first
#define S second

vector<int> st[N];
vector<int> ed[N];

vector<pii> ys[N];

int main () {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int y, x1, x2; scanf("%d%d%d", &y, &x1, &x2);
        st[x1].push_back(y);
        ed[x2].push_back(y);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y1, y2; scanf("%d%d%d", &x, &y1, &y2);
        ys[x].push_back(make_pair(y1, y2));
    }
    int nn = 1000000;
    ys[nn].push_back(make_pair(0, nn));
    bit.init(nn);
    bit.update(0, 1);
    bit.update(nn, 1);
    long long ans = 0;
    set<int> wait_list;
    for (int i = 0; i <= nn; ++i) {
        if (i == 0) {
            for (int j: st[i]) {
                bit.update(j, 1);
            }
        }
        else {
            for (int j: st[i]) {
                wait_list.insert(j);
            }
        }
        for (pii p: ys[i]) {
            ans += bit.queryLR(p.F, p.S) - 1;
        }
        for (pii p: ys[i]) {
            vector<int> dels;
            for (auto iter = wait_list.lower_bound(p.F); iter != wait_list.end(); ++iter) {
                if (*iter > p.S) break;
                bit.update((*iter), 1);
                dels.push_back(*iter);
            }
            for (int i: dels) {
                wait_list.erase(i);
            }
        }
        for (int j: ed[i]) {
            bit.update(j, -1);
        }
    }
    printf("%lld\n", ans);
}