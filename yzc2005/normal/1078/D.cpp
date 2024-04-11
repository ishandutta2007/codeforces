#include <bits/stdc++.h>
const int N = 300005, K = 19;
int n, a[N];
std::pair<int, int> range[K][N];  
std::pair<int, int> merge(std::pair<int, int> x, std::pair<int, int> y) {
  return {std::min(x.first, y.first), std::max(x.second, y.second)};
}
struct SegmentTree {
  std::pair<int, int> range[N * 4];
  void build(int p, int l, int r, int k) {
    if (l == r) {
      range[p] = ::range[k][l];
      return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid, k);
    build(p << 1 | 1, mid + 1, r, k);
    range[p] = merge(range[p << 1], range[p << 1 | 1]);
  }
  std::pair<int, int> query(int p, int l, int r, int L, int R) {
    if (l >= L && r <= R) {
      return range[p];
    }
    int mid = l + r >> 1;
    if (mid >= L && mid < R) {
      return merge(query(p << 1, l, mid, L, R), query(p << 1 | 1, mid + 1, r, L, R));
    } else if (mid >= L) {
      return query(p << 1, l, mid, L, R);
    } else {
      return query(p << 1 | 1, mid + 1, r, L, R);
    }
  }
} rmq[K];
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i + n] = a[i + n * 2] = a[i]; 
  }
  for (int i = 1; i <= n * 3; ++i) {
    range[0][i] = {std::max(1, i - a[i]), std::min(n * 3, i + a[i])};
  }
  for (int k = 0; k < K; ++k) {
    rmq[k].build(1, 1, n * 3, k);
    if (k + 1 < K) {
      for (int i = 1; i <= n * 3; ++i) {
        range[k + 1][i] = rmq[k].query(1, 1, n * 3, range[k][i].first, range[k][i].second);
      }
    }
  }
  for (int i = n + 1; i <= n * 2; ++i) {
    int ans = 0;
    std::pair<int, int> range = {i, i};
    for (int k = K - 1; ~k; --k) {
      std::pair<int, int> newRange = rmq[k].query(1, 1, n * 3, range.first, range.second);
      if (newRange.second - newRange.first + 1 < n) {
        range = newRange;
        ans |= 1 << k;
      }
    }
    printf("%d ", ans + 1);
  }
  return 0;
}