#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

namespace Treap {
mt19937 rr(random_device{}());

struct Node {
  Node *l, *r, *p;
  int cnt, prior;
  int val;
  ll sum;
  int uax;

  Node(int val) : l(nullptr), r(nullptr), p(nullptr), cnt(1), prior(rr()), val(val), sum(val), uax(0) {
  }

  Node() : Node(0) {}

  void apply(int upd) {
    if (upd > 0) {
      val = uax = upd;
      sum = cnt * ll(upd);
    }
  }

  void push() {
    if (l) {
      l->apply(uax);
    }
    if (r) {
      r->apply(uax);
    }
    uax = 0;
  }

  int pos() const {
    return l ? l->cnt : 0;
  }

  Node* update() {
    if (l) {
      l->p = this;
    }
    if (r) {
      r->p = this;
    }
    cnt = pos() + 1 + (r ? r->cnt : 0);
    sum = val + (l ? l->sum : 0) + (r ? r->sum : 0);
    return this;
  }
};

pair<Node*, Node*> split(Node* t, int k) {
  if (!t) {
    return {nullptr, nullptr};
  }
  t->push();
  if (k <= t->pos()) {
    auto res = split(t->l, k);
    t->l = res.second;
    return {res.first, t->update()};
  } else {
    auto res = split(t->r, k - t->pos() - 1);
    t->r = res.first;
    return {t->update(), res.second};
  }
}

pair<Node*, Node*> split_sum(Node* t, ll s) {
  if (!t) {
    return {nullptr, nullptr};
  }
  t->push();
  ll lsum = t->l ? t->l->sum : 0;
  if (s < lsum + t->val) {
    auto res = split_sum(t->l, s);
    t->l = res.second;
    return {res.first, t->update()};
  } else {
    auto res = split_sum(t->r, s - lsum - t->val);
    t->r = res.first;
    return {t->update(), res.second};
  }
}

pair<Node*, Node*> split_val(Node* t, int val) {
  if (!t) {
    return {nullptr, nullptr};
  }
  t->push();
  if (val >= t->val) {
    auto res = split_val(t->l, val);
    t->l = res.second;
    return {res.first, t->update()};
  } else {
    auto res = split_val(t->r, val);
    t->r = res.first;
    return {t->update(), res.second};
  }
}

Node* merge(Node* l, Node* r) {
  if (!l) {
    return r;
  }
  if (!r) {
    return l;
  }
  if (l->prior > r->prior) {
    l->push();
    l->r = merge(l->r, r);
    return l->update();
  } else {
    r->push();
    r->l = merge(l, r->l);
    return r->update();
  }
}

Node* insert(Node* to, Node* t, int k) {
  auto a = split(to, k);
  return merge(a.first, merge(t, a.second));
}

Node* erase(Node* from, int l, int r) {
  auto a = split(from, r);
  auto b = split(a.first, l);
  return merge(b.first, a.second);
}

}  // namespace Treap

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;

  Treap::Node* root = nullptr;
  vector<Treap::Node> nodes(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nodes[i] = Treap::Node(x);
    root = merge(root, &nodes[i]);
  }

  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    int res = 0;
    if (t == 1) {
      auto [l, r] = Treap::split(root, x);
      auto [l1, r1] = Treap::split_val(l, y);
      if (r1) {
        r1->apply(y);
      }
      l = Treap::merge(l1, r1);
      root = Treap::merge(l, r);
    } else {
      --x;
      auto [l, r] = Treap::split(root, x);
      while (r) {
        {
          auto [l1, r1] = Treap::split_sum(r, y);
          if (l1) {
            res += l1->cnt;
            y -= l1->sum;
            //cerr << "eat " << l1->cnt << ' ' << l1->sum << '\n';
          }
          l = Treap::merge(l, l1);
          r = r1;
        }
        {
          auto [l1, r1] = Treap::split_val(r, y);
          //if (l1) {
            //cerr << "skip " << l1->cnt << '\n';
          //}
          l = Treap::merge(l, l1);
          r = r1;
        }
      }
      root = Treap::merge(l, r);
      cout << res << '\n';
    }
    assert(root && root->cnt == n);
  }
}