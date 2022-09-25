#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

enum class Op : char {
  Nop = 0,
  Flip,
  SetPos,
  SetNeg
};

Op combine(Op a, Op b) {
  if (b == Op::SetNeg || b == Op::SetPos) {
    return b;
  } else if (b == Op::Nop) {
    return a;
  } else {
    if (a == Op::Flip) {
      return Op::Nop;
    } else if (a == Op::Nop) {
      return Op::Flip;
    } else if (a == Op::SetPos) {
      return Op::SetNeg;
    } else if (a == Op::SetNeg) {
      return Op::SetPos;
    } else {
      assert(false);
    }
  }
}

const int base = 1 << 17;
Op t[base * 2];

void push(int v) {
  t[v * 2] = combine(t[v * 2], t[v]);
  t[v * 2 + 1] = combine(t[v * 2 + 1], t[v]);
  t[v] = Op::Nop;
}

void put(int l, int r, Op op, int v = 1, int cl = 0, int cr = base) {
  if (l >= r) {
    return;
  }
  if (l <= cl && cr <= r) {
    t[v] = combine(t[v], op);
    return;
  }
  if (r <= cl || cr <= l) {
    return;
  }
  int cc = (cl + cr) / 2;
  push(v);
  put(l, r, op, v * 2, cl, cc);
  put(l, r, op, v * 2 + 1, cc, cr);
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    char c;
    int x;
    cin >> c >> x;
    if (c == '<') {
      if (x >= 0) {
        put(x, base, Op::SetPos);
        put(0, x, Op::Flip);
      } else {
        put(abs(x) + 1, base, Op::SetPos);
      }
    } else {
      if (x >= 0) {
        put(x + 1, base, Op::SetNeg);
      } else {
        put(abs(x), base, Op::SetNeg);
        put(0, abs(x), Op::Flip);
      }
    }
  }
  for (int i = 1; i < base; ++i) {
    push(i);
  }
  for (int i = 0; i < n; ++i) {
    Op op = t[abs(a[i]) + base];
    if (op == Op::SetPos) {
      a[i] = abs(a[i]);
    } else if (op == Op::SetNeg) {
      a[i] = -abs(a[i]);
    } else if (op == Op::Flip) {
      a[i] *= -1;
    }
    cout << a[i] << ' ';
  }
  cout << '\n';
}