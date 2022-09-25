#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

mt19937 rr;

struct Node {
    Node *l, *r;
    int x, upd, cnt, y;

    Node(int x): l(0), r(0), x(x), upd(0), cnt(1), y(rr()) {}
};

void push(Node *t) {
    int upd = t->upd;
    if (t->l) {
        t->l->x += upd;
        t->l->upd += upd;
    }
    if (t->r) {
        t->r->x += upd;
        t->r->upd += upd;
    }
    t->upd = 0;
}

void update(Node *t) {
    t->cnt = 1;
    if (t->l)
        t->cnt += t->l->cnt;
    if (t->r)
        t->cnt += t->r->cnt;
}

int cnt(Node *t) {
    return t ? t->cnt : 0;
}

pair<Node *, Node *> split1(Node *t, int k) {
    if (!t)
        return {0, 0};
    push(t);
    if (k > cnt(t->l)) {
        auto p = split1(t->r, k - cnt(t->l) - 1);
        t->r = p.first;
        update(t);
        return {t, p.second};
    } else {
        auto p = split1(t->l, k);
        t->l = p.second;
        update(t);
        return {p.first, t};
    }
}

pair<Node *, Node *> split(Node *t, int k) {
    if (!t)
        return {0, 0};
    push(t);
    if (t->x < k) {
        auto p = split(t->r, k);
        t->r = p.first;
        update(t);
        return {t, p.second};
    } else {
        auto p = split(t->l, k);
        t->l = p.second;
        update(t);
        return {p.first, t};
    }
}

Node *merge(Node *l, Node *r) {
    if (!r)
        return l;
    if (!l)
        return r;
    push(l);
    push(r);
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

Node *root = new Node(0);

void apply(int l, int r) {
    Node *a, *b, *c;
    tie(a, b) = split(root, l);
    tie(b, c) = split(b, r);
    if (b) {
        b->x++;
        b->upd++;
    }
    if (c) {
        Node *x, *y;
        tie(x, c) = split1(c, 1);
        if (b) {
            tie(b, y) = split1(b, cnt(b) - 1);
            y->x = min(y->x, x->x);
            b = merge(b, y);
        }
    }
    //cerr << cnt(a) << ' ' << cnt(b) << ' ' << cnt(c) << '\n';
    root = merge(a, new Node(l));
    root = merge(root, b);
    root = merge(root, c);
}

void print(Node *t) {
    if (!t)
        return;
    push(t);
    print(t->l);
    cerr << t->x << ' ';
    print(t->r);
    update(t);
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        int l, r;
        scanf("%d%d", &l, &r);
        apply(l, r);
        //cerr << cnt(root) << ": ";
        //print(root);
        //cerr << '\n';
    }
    cout << root->cnt - 1 << '\n';
}