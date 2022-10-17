#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int tt, n, q, L[N], R[N];
string s, t;
int val[N << 2], len[N << 2], lazy[N << 2];
void pull(int p) {
  val[p] = val[p << 1] + val[p << 1 | 1];
}
void build(int p, int l, int r) {
  lazy[p] = -1;
  len[p] = r - l + 1;
  if (l == r) {
    val[p] = s[l] == '0';
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pull(p);
}
void tag(int p, int v) {
  lazy[p] = v;
  val[p] = v == 0 ? len[p] : 0;
}
void push(int p) {
  if (~lazy[p]) {
    tag(p << 1, lazy[p]);
    tag(p << 1 | 1, lazy[p]);
    lazy[p] = -1;
  }
}
void cover(int p, int l, int r, int ll, int rr, int v) {
  if (l >= ll && r <= rr) {
    tag(p, v);
    return;
  }
  int mid = l + r >> 1;
  push(p);
  if (mid >= ll) {
    cover(p << 1, l, mid, ll, rr, v);
  }
  if (mid < rr) {
    cover(p << 1 | 1, mid + 1, r, ll, rr, v);
  }
  pull(p);
}
int query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) {
    return val[p];
  }
  int mid = l + r >> 1;
  push(p);
  int res = 0;
  if (mid >= ll) {
    res += query(p << 1, l, mid, ll, rr);
  }
  if (mid < rr) {
    res += query(p << 1 | 1, mid + 1, r, ll, rr);
  }
  return res;
}
int main() {
  cin >> tt;
  while (tt--) {
    cin >> n >> q >> t >> s;
    build(1, 0, n - 1);
    bool flag = 1;
    for (int i = 0; i < q; ++i) {
      cin >> L[i] >> R[i];
    }
    while (q--) {
      int l = L[q], r = R[q];
      --l;
      --r;
      int cnt0 = query(1, 0, n - 1, l, r);
      int len = r - l + 1;
      int cnt1 = len - cnt0;
      if (cnt0 < cnt1) {
        cover(1, 0, n - 1, l, r, 1);
      } else if (cnt0 > cnt1) {
        cover(1, 0, n - 1, l, r, 0);
      } else {
        flag = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      bool s0 = query(1, 0, n - 1, i, i);
      bool t0 = t[i] == '0';
      if (s0 != t0) {
        flag = 0;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << endl;
  }
  return 0;
}