#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

struct BIT {
  int a[N], n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i <= n; ++i) {
      a[i] = 0;
    }
  }
  void update(int pos, int val) {
    for (int i = pos; i <= n; i += i & (-i)) {
      a[i] += val;
    }
  }
  int query(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & (-i)) {
      ret += a[i];
    }
    return ret;
  }
  int queryLR(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit;


struct Treap {
  Treap *lc, *rc;
  int pri, key, sz;
  Treap(){}
  Treap(int _key): lc(NULL), rc(NULL), pri(rand()), key(_key), sz(1){}
};

int Sz(Treap *t) {
  return t ? t->sz : 0;;
}

void pull(Treap* t) {
  if (!t) return;
  t->sz = Sz(t->lc) + Sz(t->rc) + 1;
  return;
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

void split(Treap *t, int k, Treap* &a, Treap* &b) {
  if (!t) a = b = NULL;
  else if (Sz(t->lc) + 1 <= k) {
    a = t;
    split(t->rc, k - Sz(t->lc) - 1, a->rc, b);
    pull(a);
  }
  else {
    b = t;
    split(t->lc, k, a, b->lc);
    pull(b);
  }
}

void split1(Treap *t, int k, Treap* &a, Treap* &b) {
  if (!t) a = b = NULL;
  else if (t->key <= k) {
    a = t;
    split1(t->rc, k, a->rc, b);
    pull(a);
  }
  else {
    b = t;
    split1(t->lc, k, a, b->lc);
    pull(b);
  }
}

deque<int> G[26];

typedef long long ll;

void go() {
  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;
  for (int i = 0; i < 26; ++i) {
    G[i].clear();
  }
  bit.init(n);
  for (int i = 0; i < n; ++i) {
    G[s1[i] - 'a'].push_back(i);
  }
  Treap* root = NULL;
  for (int i = 0; i < n; ++i) {
    root = merge(root, new Treap(i));
    bit.update(i + 1, 1);
  }
  ll ans = (1ll << 60);
  ll tmp = 0;
  for (int i = 0; i < n; ++i) {
    Treap *lc;
    split(root, 1, lc, root);
    char c = s1[lc->key];
    root = merge(lc, root);
    if (c < s2[i]) {
      ans = min(ans, tmp);
      cout << ans << endl;
      return;
    }
    else {
      // case 1 --> find 1st bigger
      int _ = n + 2;
      for (int j = s2[i] - 'a' - 1; j >= 0; --j) {
        if (!G[j].empty()) {
          _ = min(G[j][0], _);
        }
      }
      if (_ != n + 2) {
        int pos = bit.queryLR(1, (_ + 1) - 1);
        ans = min(ans, tmp + pos);
      }
      // case 2 --> find same
      if (G[s2[i] - 'a'].empty()) break;
      _ = G[s2[i] - 'a'][0];
      tmp += bit.queryLR(1, (_ + 1) - 1);
      bit.update(_ + 1, -1);
      G[s2[i] - 'a'].pop_front();
      Treap *lc, *rc;
      split1(root, _ - 1, lc, root);
      split1(root, _, root, rc);
      root = merge(lc, rc);
    }
  }
  if (ans == (1ll << 60)) {
    cout << -1 << endl;
  }
  else {
    cout << ans << endl;
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}