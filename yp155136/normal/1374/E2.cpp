#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 200006;

int t[N], mask[N];

vector<int> v[4];
vector<int> pre[4];

struct Treap {
    Treap *lc, *rc;
    int sum, sz, key, id, pri;
    pii key2;
    Treap(){}
    Treap(int _key, int _id): lc(NULL), rc(NULL), sum(_key), sz(1), key(_key), pri(rand()), id(_id), key2(make_pair(_key, _id)){}
};

int Sz(Treap* t) {
    return t ? t->sz : 0;
}

int Sum(Treap* t) {
    return t ? t->sum : 0;
}

void pull(Treap* t) {
    if (!t) return;
    t->sz = Sz(t->lc) + Sz(t->rc) + 1;
    t->sum = Sum(t->lc) + Sum(t->rc) + t->key;
}

Treap* merge(Treap* a, Treap* b) {
    if (!a || !b) return a ? a : b;
    else if (a->pri > b->pri) {
        a->rc = merge(a->rc, b);
        pull(a);
        return a;
    }
    else {
        b->lc = merge(a, b->lc);
        pull(b);
        return b;
    }
}

void split_by_key(Treap* t, pii k, Treap* &a, Treap* &b) {
    if (!t) a = b = NULL;
    else if (t->key2 <= k) {
        a = t;
        split_by_key(t->rc, k, a->rc, b);
        pull(a);
    }
    else {
        b = t;
        split_by_key(t->lc, k, a, b->lc);
        pull(b);
    }
}

void split_by_sz(Treap* t, int k, Treap* &a, Treap* &b) {
    if (!t) a = b = NULL;
    else if (Sz(t->lc) + 1 <= k) {
        a = t;
        split_by_sz(t->rc, k - Sz(t->lc) - 1, a->rc, b);
        pull(a);
    }
    else {
        b = t;
        split_by_sz(t->lc, k, a, b->lc);
        pull(b);
    }
}

Treap* root;

void addd(int id) {
    Treap *tl;
    split_by_key(root, make_pair(t[id], id), tl, root);
    root = merge(tl, merge(new Treap(t[id], id), root));
}

void dell(int id) {
    Treap *tl, *tr;
    split_by_key(root, make_pair(t[id], id - 1), tl, root);
    split_by_key(root, make_pair(t[id], id), root, tr);
    root = merge(tl, tr);
}

ll Q(int sz) {
    if (Sz(root) < sz) {
        return (1ll << 40);
    }
    Treap *tl;
    split_by_sz(root, sz, tl, root);
    ll ret = Sum(tl);
    root = merge(tl, root);
    return ret;
}

void dfs(Treap* t) {
    if (!t) return;
    dfs(t->lc);
    cout << t->id << ' ';
    dfs(t->rc);
}

void Q2(int sz) {
    Treap *tl;
    split_by_sz(root, sz, tl, root);
    dfs(tl);
    exit(0);
}

int main () {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        int a, b; scanf("%d%d%d", &t[i], &a, &b);
        mask[i] = ((a << 1) | b);
        v[ mask[i] ].push_back(i);
    }
    for (int i = 0; i < 4; ++i) {
        v[i].push_back(0);
        sort(v[i].begin(), v[i].end(), [](const int &x, const int &y) {
            return t[x] < t[y];
        });
        for (int j: v[i]) {
            if (j == 0) {
                pre[i].push_back(0);
            }
            else {
                pre[i].push_back(pre[i].back() + t[j]);
            }
        }
    }
    if (v[3].size() + min(v[1].size(), v[2].size()) < k) {
        puts("-1");
        return 0;
    }
    if (min(k, (int)v[3].size()) + 2 * min(0, k - (int)v[3].size()) > m) {
        puts("-1");
        return 0;
    }
    ll ans = (1ll << 50);
    root = NULL;
    for (int i = 1; i < (int)v[0].size(); ++i) {
        addd(v[0][i]);
    }
    for (int i = k + 1; i < (int)v[1].size(); ++i) {
        addd(v[1][i]);
    }
    for (int i = k + 1; i < (int)v[2].size(); ++i) {
        addd(v[2][i]);
    }
    for (int i = 1; i < (int)v[3].size(); ++i) {
        addd(v[3][i]);
    }
    // enumerate number of 11
    for (int i = 0; i <= max(m, k); ++i) {
        if (i < v[3].size() && k - i < (int)min(v[1].size(), v[2].size())) {
            // cout << "i = " << i << endl;
            int other = max(0, k - i);
            // cout << "other = " << other << endl;
            // cout << "root sz = " << Sz(root) << endl;
            int left = m - i - 2 * other;
            if (left >= 0) {
                ll val = pre[3][i] + pre[1][other] + pre[2][other] + Q(left);
                ans = min(ans, val);
            }
        }
        if (i + 1 < v[3].size()) {
            dell(v[3][i + 1]);
        }
        if (k - i < (int)v[1].size() && k - i > 0) {
            addd(v[1][k - i]);
        }
        if (k - i < (int)v[2].size() && k - i > 0) {
            addd(v[2][k - i]);
        }
    }
    if (ans > (1ll << 31)) {
        puts("-1");
        return 0;
    }
    printf("%lld\n", ans);
    root = NULL;
    for (int i = 1; i < (int)v[0].size(); ++i) {
        addd(v[0][i]);
    }
    for (int i = k + 1; i < (int)v[1].size(); ++i) {
        addd(v[1][i]);
    }
    for (int i = k + 1; i < (int)v[2].size(); ++i) {
        addd(v[2][i]);
    }
    for (int i = 1; i < (int)v[3].size(); ++i) {
        addd(v[3][i]);
    }
    // enumerate number of 11
    for (int i = 0; i <= max(m, k); ++i) {
        if (i < v[3].size() && k - i < (int)min(v[1].size(), v[2].size())) {
            // cout << "i = " << i << endl;
            int other = max(0, k - i);
            // cout << "other = " << other << endl;
            // cout << "root sz = " << Sz(root) << endl;
            int left = m - i - 2 * other;
            if (left >= 0) {
                ll val = pre[3][i] + pre[1][other] + pre[2][other] + Q(left);
                if (val == ans) {
                    for (int j = 1; j <= i; ++j) cout << v[3][j] << ' ';
                    for (int j = 1; j <= other; ++j) cout << v[1][j] << ' ';
                    for (int j = 1; j <= other; ++j) cout << v[2][j] << ' ';
                    Q2(left);

                }
            }
        }
        if (i + 1 < v[3].size()) {
            dell(v[3][i + 1]);
        }
        if (k - i < (int)v[1].size() && k - i > 0) {
            addd(v[1][k - i]);
        }
        if (k - i < (int)v[2].size() && k - i > 0) {
            addd(v[2][k - i]);
        }
    }
}