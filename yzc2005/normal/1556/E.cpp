#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], b[N];
long long sum[N], suf[N];
struct ST {
  long long mn[N << 2], mx[N << 2];
  void build(int p, int l, int r, long long *a) {
    if (l == r) {
      mn[p] = mx[p] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid, a);
    build(p << 1 | 1, mid + 1, r, a);
    mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
  }
  long long query_min(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return mn[p];
    int mid = (l + r) >> 1;
    long long res = 1e18;
    if (mid >= ll) res = min(res, query_min(p << 1, l, mid, ll, rr));
    if (mid < rr) res = min(res, query_min(p << 1 | 1, mid + 1, r, ll, rr));
    return res;   
  }
  long long query_max(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return mx[p];
    int mid = (l + r) >> 1;
    long long res = -1e18;
    if (mid >= ll) res = max(res, query_max(p << 1, l, mid, ll, rr));
    if (mid < rr) res = max(res, query_max(p << 1 | 1, mid + 1, r, ll, rr));
    return res;
  }
} t1, t2;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]), a[i] = b[i] - a[i];
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = n; i; --i) suf[i] = suf[i + 1] + a[i];
  t1.build(1, 1, n, sum);
  t2.build(1, 1, n, suf);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    if (sum[r] != sum[l - 1]) puts("-1");
    else {
      if (t1.query_min(1, 1, n, l, r) < sum[l - 1]) puts("-1");
      else if (t2.query_max(1, 1, n, l, r) > suf[r + 1]) puts("-1");
      else {
        long long ans1 = t1.query_max(1, 1, n, l, r) - sum[l - 1];
        long long ans2 = suf[r + 1] - t2.query_min(1, 1, n, l, r);
        printf("%lld\n", max(ans1, ans2));
      }
    }
  }
  return 0;
}