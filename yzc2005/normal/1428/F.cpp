#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
char s[N];
long long ans;
int l[N << 2], r[N << 2], val[N << 2], mx[N << 2];
long long sum[N << 2];
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l[p] + r[p] >> 1)
void build(int p, int L, int R) {
  l[p] = L;
  r[p] = R;
  if (L != R) {
    build(ls, L, mid);
    build(rs, mid + 1, R);
  }  
}
inline void tag(int p, int v) {
  val[p] = mx[p] = v;
  sum[p] = 1ll * (r[p] - l[p] + 1) * v;
}
inline void pushdown(int p) {
  if (val[p]) {
    tag(ls, val[p]);
    tag(rs, val[p]);
    val[p] = 0;
  }
}
void modify(int p, int L, int R, int v) {
  if (L > R) {
    return;
  }
  if (l[p] >= L && r[p] <= R) {
    tag(p, v);
    return;
  }
  pushdown(p);
  if (mid >= L) {
    modify(ls, L, R, v);
  } 
  if (mid < R) {
    modify(rs, L, R, v);
  }
  sum[p] = sum[ls] + sum[rs];
  mx[p] = max(mx[ls], mx[rs]);
}
int find(int p, int v) {
  if (l[p] == r[p]) {
    return l[p];
  }
  pushdown(p);
  if (mx[rs] >= v) {
    return find(rs, v);
  } else {
    return find(ls, v);
  }
  sum[p] = sum[ls] + sum[rs];
  mx[p] = max(mx[ls], mx[rs]);
}
int main() {
  scanf("%d%s", &n, s + 1);
  build(1, 1, n);
  for (int i = 1, r; i <= n; i = r) {
    for (r = i; r <= n && s[r] == s[i]; ++r);
    if (s[i] == '0') {
      ans += 1ll * sum[1] * (r - i);
    } else {
      for (int j = i, len = 1; j < r; ++j, ++len) {
        modify(1, find(1, len), i - 1, len);
        ans += sum[1] + 1ll * len * (len + 1) / 2;
      }
      for (int j = r - 1, len = 1; j >= i; --j, ++len) {
        modify(1, j, j, len);
      } 
    }
  }  
  printf("%lld\n", ans);
  return 0;
}