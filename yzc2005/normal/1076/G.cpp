#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, q;
bool a[N];
struct node {
  int v[6];
  node operator + (const node &rhs) {
    node res;
    for (int i = 0; i <= m; ++i) {
      res.v[i] = v[rhs.v[i]];
    }
    return res;
  }
} t[N << 2][2], tr[2];
bool rev[N << 2];
void pushup(int p) {
  for (int i = 0; i < 2; ++i) {
    t[p][i] = t[p << 1][i] + t[p << 1 | 1][i];
  }
}
void build(int p, int l, int r) {
  if (l == r) {
    t[p][0] = tr[a[l]];
    t[p][1] = tr[a[l] ^ 1];
    return;
  }
  int mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void tag(int p) {
  rev[p] ^= 1;
  std::swap(t[p][0], t[p][1]);
}
void pushdown(int p) {
  if (rev[p]) {
    tag(p << 1);
    tag(p << 1 | 1);
    rev[p] = 0;
  }
}
void modify(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) {
    tag(p);
    return;
  }
  int mid = l + r >> 1;
  pushdown(p);
  if (mid >= ll) {
    modify(p << 1, l, mid, ll, rr);
  }
  if (mid < rr) {
    modify(p << 1 | 1, mid + 1, r, ll, rr);
  }
  pushup(p);
}
node query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return t[p][0];
  int mid = l + r >> 1;
  pushdown(p);
  if (mid >= ll && mid < rr) {
    return query(p << 1, l, mid, ll, rr) + query(p << 1 | 1, mid + 1, r, ll, rr);
  } 
  if (mid >= ll) {
    return query(p << 1, l, mid, ll, rr);
  }
  return query(p << 1 | 1, mid + 1, r, ll, rr);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i <= m; ++i) tr[0].v[i] = min(m, i + 1);
  tr[1] = tr[0], tr[1].v[m] = 0;
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    a[i] = x & 1;
  }
  build(1, 1, n);
  while (q--) {
    int op, l, r; 
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      long long d;
      scanf("%lld", &d);
      if (d & 1) {
        modify(1, 1, n, l, r);
      }
    } else {
      auto res = query(1, 1, n, l, r);
      printf("%d\n", res.v[m] ? 1 : 2);  
    }
  }
  return 0;
}