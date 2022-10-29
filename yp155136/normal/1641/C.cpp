#include <bits/stdc++.h>
using namespace std;

struct Val {
  int lmax, rmax, sum;
  Val(int _l, int _r, int _s): lmax(_l), rmax(_r), sum(_s){}
};

Val combine(Val a, Val b) {
  Val ret = Val(0, 0, 0);
  ret.sum = a.sum + b.sum;
  ret.lmax = (a.sum == a.lmax ? a.sum + b.lmax : a.lmax);
  ret.rmax = (b.sum == b.rmax ? b.sum + a.rmax : b.rmax);
  return ret;
}

struct Node {
  Node *lc, *rc;
  Val v;
  Node(): lc(NULL), rc(NULL), v(Val(0, 0, 1)){}
  void pull() {
    v = combine(lc->v, rc->v);
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

void modify(Node* node, int L, int R, int pos) {
  if (L == R) {
    node->v = Val(1, 1, 1);
    return;
  }
  int mid = (L + R) >> 1;
  if (pos <= mid) modify(node->lc, L, mid, pos);
  else modify(node->rc, mid + 1, R, pos);
  node->pull();
  return;
}

Val query(Node* node, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    return node->v;
  }
  int mid = (L + R) >> 1;
  if (mid + 1 <= l) return query(node->rc, mid + 1, R, l, r);
  if (r <= mid) return query(node->lc, L, mid, l, r);
  return combine(query(node->lc, L, mid, l, r), query(node->rc, mid + 1, R, l, r));
}

typedef pair<int, int> pii;
#define F first
#define S second

const int _zero = 0;

struct Treap {
  Treap *lc, *rc;
  int val, mx;
  int key, pri;
  Treap(int _key, int _val): lc(NULL), rc(NULL), val(_val), mx(_val), key(_key), pri(rand()){}
};

int Mx(Treap* t) {
  return t ? t->mx : _zero;
}

void pull(Treap* t) {
  if (!t) return;
  t->mx = max(max(Mx(t->lc), Mx(t->rc)), t->val);
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

void split(Treap* t, int k, Treap* &a, Treap* &b) {
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

Treap *troot;
Node* root;
int n, q;

void change_tr(int pos, int val) {
  Treap *tl, *tr;
  split(troot, pos - 1, tl, troot);
  split(troot, pos, troot, tr);
  troot->val = max(troot->val, val);
  pull(troot);
  troot = merge(merge(tl, troot), tr);
}

bool yes(int pos) {
  int ql = (pos == 1 ? 1 : pos - query(root, 1, n, 1, pos - 1).rmax);
  int qr = (pos == n ? n : pos + query(root, 1, n, pos + 1, n).lmax);
  Treap *tl, *tr;
  split(troot, pos - 1, tl, troot);
  split(troot, qr, troot, tr);
  bool ans = false;
  if (Mx(troot) >= ql && Mx(troot) <= pos) {
    ans = true;
  }
  troot = merge(merge(tl, troot), tr);
  return ans;
}

int main () {
  cin >> n >> q;
  root = Build(1, n);
  set<int> maybe_yes;
  for (int i = 1; i <= n; ++i) {
    troot = merge(troot, new Treap(i, 0));
    maybe_yes.insert(i);
  }
  maybe_yes.insert(n + 1);
  for (int i = 1; i <= q; ++i) {
    int t; cin >> t;
    if (t == 0) {
      int l, r, x; cin >> l >> r >> x;
      if (x == 0) {
        auto iter = maybe_yes.lower_bound(l);
        vector<int> del;
        while ((*iter) <= r) {
          del.push_back(*iter);
          modify(root, 1, n, *iter);
          ++iter;
        }
        for (int j : del) {
          maybe_yes.erase(j);
        }
      }
      else if (x == 1) {
        change_tr(r, l);
      }
    }
    else {
      int pos; cin >> pos;
      if (maybe_yes.find(pos) == maybe_yes.end()) {
        cout << "NO" << '\n';
      }
      else if (yes(pos)) {
        cout << "YES" << '\n';
      }
      else {
        cout << "N/A" << '\n';
      }
    }
  }
}