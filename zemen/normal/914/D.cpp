#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

const int base = 1 << 19;
int t[base * 2];

void put(int v, int val) {
  v += base;
  t[v] = val;
  while (v > 1) {
    v /= 2;
    t[v] = gcd(t[v * 2], t[v * 2 + 1]);
  }
}

int findl(int v, int g, int x) {
  if (v >= base) {
    return v - base;
  }
  int ng = gcd(t[v * 2], g);
  if (ng % x != 0) {
    return findl(v * 2, g, x);
  } else {
    return findl(v * 2 + 1, ng, x);
  }
}

int findr(int v, int g, int x) {
  if (v >= base) {
    return v - base;
  }
  int ng = gcd(t[v * 2 + 1], g);
  if (ng % x != 0) {
    return findr(v * 2 + 1, g, x);
  } else {
    return findr(v * 2, ng, x);
  }
}

bool ask(int l, int r, int x) {
  l += base;
  r += base - 1;
  vector<int> tl, tr;
  while (l <= r) {
    tl.push_back(l);
    tr.push_back(r);
    if (l % 2) {
      l = (l / 2) + 1;
    } else {
      l /= 2;
    }
    if (r % 2) {
      r /= 2;
    } else {
      r = (r / 2) - 1;
    }
  }
  reverse(tr.begin(), tr.end());
  tl.insert(tl.end(), tr.begin(), tr.end());
  int pl = 1e9;
  int g = 0;
  for (auto y : tl) {
    int ng = gcd(g, t[y]);
    if (ng % x) {
      pl = findl(y, g, x);
      break;
    }
    g = ng;
  }
  int pr = -1e9;
  g = 0;
  reverse(tl.begin(), tl.end());
  for (auto y : tl) {
    int ng = gcd(g, t[y]);
    if (ng % x) {
      pr = findr(y, g, x);
      break;
    }
    g = ng;
  }
  //cerr << pl << ' ' << pr << '\n';
  if (pl >= pr) {
    return true;
  }
  return false;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    t[i + base] = a[i];
  }
  for (int i = base - 1; i > 0; --i) {
    t[i] = gcd(t[i * 2], t[i * 2 + 1]);
  }

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      --l;
      cout << (ask(l, r, x) ? "YES" : "NO") << '\n';
    } else {
      int v, x;
      scanf("%d%d", &v, &x);
      --v;
      put(v, x);
    }
  }
}