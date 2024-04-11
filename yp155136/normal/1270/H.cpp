#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int C = 1000000;
const int N = 500006;
const int INF = 0x3f3f3f3f;

int a[N];

pii operator+(const pii &p1, const pii &p2) {
    if (p1.F == p2.F) return {p1.F, p1.S + p2.S};
    else return min(p1, p2);
}

struct Node {
    Node *lc, *rc;
    pii val; //(min, cnt)
    int tag;
    Node(): lc(NULL), rc(NULL), val({0, 0}), tag(0){}
    void pull() {
        val = lc->val + rc->val;
    }
};

Node* Build(int L, int R) {
    Node* node = new Node();
    if (L == R) return node;
    int mid = (L + R) >> 1;
    node->lc = Build(L, mid);
    node->rc = Build(mid + 1, R);
    node->pull();
    return node;
}

void push(Node* node, int L, int R) {
    if (L == R) node->tag = 0;
    if (node->tag == 0) return;
    node->lc->tag += node->tag;
    node->rc->tag += node->tag;
    node->lc->val.F += node->tag;
    node->rc->val.F += node->tag;
    node->tag = 0;
    return;
}

void modifyS(Node* node, int L, int R, int pos, int del) {
    if (L == R) {
        node->val.S += del;
        return;
    }
    push(node, L, R);
    int mid = (L + R) >> 1;
    if (pos <= mid) modifyS(node->lc, L, mid, pos, del);
    else modifyS(node->rc, mid + 1, R, pos, del);
    node->pull();
    return;
}

void modifyF(Node* node, int L, int R, int l, int r, int del) {
    if (L > r || l > R) return;
    else if (l <= L && R <= r) {
        node->val.F += del;
        node->tag += del;
        return;
    }
    push(node, L, R);
    int mid = (L + R) >> 1;
    modifyF(node->lc, L, mid, l, r, del);
    modifyF(node->rc, mid + 1, R, l, r, del);
    node->pull();
    return;
}

Node* root;

void query(Node* node, int L, int R) {
    if (L == R) {
        if (L <= 51) cout << node->val.F << " , " << node->val.S << endl;
        return;
    }
    push(node, L, R);
    int mid = (L + R) >> 1;
    query(node->lc, L, mid);
    query(node->rc, mid + 1, R);
}

void goF(int pos, int del) {
    int l = min(a[pos], a[pos + 1]);
    int r = max(a[pos], a[pos + 1]);
    //cout << "add l = " << l << " , r = " << r - 1 << " , val = " << del << endl;
    modifyF(root, 0, C, l, r - 1, del);
}

void goS(int pos, int del) {
    modifyS(root, 0, C, a[pos], del);
}

int main () {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    reverse(a + 1, a + n + 1);
    a[0] = 0, a[n + 1] = C + 1;
    root = Build(0, C);
    for (int i = 1; i <= n; ++i) {
        goS(i, 1);
    }
    for (int i = 0; i <= n; ++i) {
        goF(i, 1);
    }
    while (q--) {
        int pos, val; scanf("%d%d", &pos, &val);
        pos = n - pos + 1;
        goS(pos, -1);
        goF(pos, -1);
        goF(pos - 1, -1);
        a[pos] = val;
        goS(pos, 1);
        goF(pos, 1);
        goF(pos - 1, 1);
        //puts("finish gaoing");
        //cout << "val.F = " << root->val.F << endl;
        printf("%d\n", root->val.S);
        //query(root, 0, C);
    }
}