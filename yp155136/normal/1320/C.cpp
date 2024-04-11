#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    Node *lc, *rc;
    ll mx, tag;
    Node(): lc(NULL), rc(NULL), mx(0), tag(0){}
    void pull() {
        mx = max(lc->mx, rc->mx);
    }
};

Node* Build(int L, int R) {
    Node* node = new Node();
    if (L == R) {
        return node;
    }
    int mid = (L + R) >> 1;
    node->lc = Build(L, mid);
    node->rc = Build(mid + 1, R);
    return node;
}

void push(Node* node, int L, int R) {
    if (L == R) node->tag = 0;
    if (node->tag == 0) return;
    node->lc->mx += node->tag;
    node->rc->mx += node->tag;
    node->lc->tag += node->tag;
    node->rc->tag += node->tag;
    node->tag = 0;
    return;
}

void modify(Node* node, int L, int R, int l, int r, int v) {
    if (l > r) return;
    else if (l > R || L > r) return;
    else if (l <= L && R <= r) {
        node->tag += v;
        node->mx += v;
        return;
    }
    push(node, L, R);
    int mid = (L + R) >> 1;
    modify(node->lc, L, mid, l, r, v);
    modify(node->rc, mid + 1, R, l, r, v);
    node->pull();
    return;
}

const int N = 200006;
int a[N], ca[N];
int b[N], cb[N];
int x[N], y[N], z[N];

vector<int> v1[N], v2[N];

int w1[N], w2[N];

int main() {
    int n, m, p; scanf("%d%d%d", &n, &m, &p);
    vector<int> xx, yy;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &ca[i]);
        xx.push_back(a[i]);
        w1[i - 1] = -1000000007;
    }
    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(xx.begin(), xx.end(), a[i]) - xx.begin();
        w1[ a[i] ] = max(w1[ a[i] ], -ca[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &b[i], &cb[i]);
        yy.push_back(b[i]);
        w2[i - 1] = -1000000007;
    }
    sort(yy.begin(), yy.end());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());
    for (int i = 1; i <= m; ++i) {
        b[i] = lower_bound(yy.begin(), yy.end(), b[i]) - yy.begin();
        v1[ b[i] ].push_back(i);
        w2[ b[i] ] = max(w2[ b[i] ], -cb[i]);
    }
    int nn = (int)xx.size() - 1;
    Node* root = Build(0, nn);
    for (int i = 1; i <= p; ++i) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        x[i] = upper_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
        y[i] = upper_bound(yy.begin(), yy.end(), y[i]) - yy.begin();
        v2[ y[i] ].push_back(i);
    }
    for (int i = 0; i <= nn; ++i) {
        modify(root, 0, nn, i, i, w1[i]);
    }
    ll ans = -(1ll << 50);
    for (int i = 0; i < (int)yy.size(); ++i) {
        /* for (int j: v1[i]) {
            modify(root, 0, nn, 0, nn, -cb[j]);
        } */
        modify(root, 0, nn, 0, nn, w2[i]);
        for (int j: v2[i]) {
            modify(root, 0, nn, x[j], nn, z[j]);
        }
        ans = max(ans, root->mx);
        /* 
        for (int j: v1[i]) {
            modify(root, 0, nn, 0, nn, cb[j]);
        }
        */
        modify(root, 0, nn, 0, nn, -w2[i]);
    }
    printf("%lld\n", ans);
}