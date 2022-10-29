#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second
const int N = 500006;
const int INF = 0x3f3f3f3f;

ll l[N], r[N], c[N];

pii ans;

int n, m;

void update_ans(ll val, int i) {
    if (val > ans.F) {
        ans.F = val;
        ans.S = i;
    }
}

void show_ans() {
    int i = ans.S;
    printf("%lld\n", ans.F);
    if (ans.F == 0) exit(0);
    for (int j = m + 1; j <= n + m; ++j) {
        if (((min(r[j], r[i])) - max(l[j], l[i])) * c[i] == ans.F) {
            printf("%d %d\n", j - m, i);
            exit(0);
        }
    }
}

struct Treap {
    Treap *lc, *rc;
    int key, pri;
    pii val, mx;
    Treap(int _key, pii _mx): lc(NULL), rc(NULL), key(_key), mx(_mx), val(_mx), pri(rand()){}
};

pii Mx(Treap* t) {
    return t ? t->mx : make_pair(-1ll, 0ll);
}

void pull(Treap* t) {
    if (!t) return;
    t->mx = max(max(Mx(t->lc), Mx(t->rc)), t->val);
}

Treap* merge(Treap* a,Treap* b) {
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

void split(Treap* t,int k, Treap* &a, Treap* &b) {
    if (!t) a = b = NULL;
    else if (t->key <= k) {
        a = t;
        split(t->rc, k, a->rc, b);
        pull(a);
    }
    else {
        b = t;
        split(t->lc, k, a, b->lc);
        pull(b);
    }
}

int main() {
    srand(time(NULL));
    scanf("%d%d", &n, &m);
    vector<int> v;
    for (int i = m + 1; i <= m + n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        v.push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &l[i], &r[i], &c[i]);
        v.push_back(i);
    }
    sort(v.begin(), v.end(), [](const int &a, const int &b) {
        return l[a] < l[b] || l[a] == l[b] && a > b;
    });
    ll rmax = -1;
    for (int i: v) {
        if (1 <= i && i <= m) {
            update_ans((min(rmax, r[i]) - l[i]) * c[i], i);
        }
        else {
            rmax = max(rmax, r[i]);
        }
    }
    sort(v.begin(), v.end(), [](const int &a, const int &b) {
        return r[a] > r[b] || r[a] == r[b] && a > b;
    });
    ll lmin = INF;
    for (int i: v) {
        if (1 <= i && i <= m) {
            update_ans((r[i] - max(l[i], lmin)) * c[i], i);
        }
        else {
            lmin = min(lmin, l[i]);
        }
    }
    //todo: 2 cases
    rmax = -1;
    sort(v.begin(), v.end(), [](const int &a, const int &b) {
        return l[a] < l[b] || l[a] == l[b] && a > b;
    });
    for (int i: v) {
        if (1 <= i && i <= m) {
            if (rmax >= r[i]) {
                update_ans((r[i] - l[i]) * c[i], i);
            }
        }
        else {
            rmax = max(rmax, r[i]);
        }
    }
    Treap* root = NULL;
    for (int i: v) {
        if (1 <= i && i <= m) {
            Treap *tl;
            split(root, r[i], tl, root);
            root = merge(merge(tl, new Treap(r[i], {c[i], i})), root);
        }
        else {
            Treap *tl;
            split(root, r[i] - 1, tl, root);
            if (root != NULL) {
                pii _ = Mx(root);
                update_ans((r[i] - l[i]) * _.F, _.S);
            }
            root = merge(tl, root);
        }
    }
    show_ans();
}