#include <bits/stdc++.h>
const int N = 5e5 + 5;
int n, a[N], b[N], c[N], o[N], ans;
std::set<int> segs, nums, pts;
int main() {
  scanf("%d", &n), segs.insert(0), segs.insert(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), o[i] = i, segs.insert(i), nums.insert(i);
  std::sort(o + 1, o + n + 1, [&](int i, int j) {return a[i] > a[j];});
  if (n == 1) return printf("0\n%d\n", a[1]), 0;
  for (int i = 1; i <= n; ++i) {
    int pos = o[i], cur = a[pos];
    c[pos] = 1; // 0 -> 1
    auto update = [&](int l, int r) {
      for (auto it = nums.lower_bound(l), pre = it; it != nums.end() && *it < r; b[*it] = cur, ++it, nums.erase(pre), pre = it);
    };
    auto check = [&](int l, int r) { // [l, r)
      ans = std::max(ans, r - l);
      int mid = (l + r) / 2;
      if (c[l] == 1) update(l, mid);
      if (c[r - 1] == 1) update(mid, r);
    };    
    auto insert = [&](int x) {
      segs.insert(x);
      pts.insert(x);
    };
    auto erase = [&](int x) {
      segs.erase(x);
      pts.insert(x);
    };
    auto it = segs.lower_bound(pos), tmp = it;
    if (*it == pos) {
      int r = *(++it);
      if (pos + 1 == r) {
        bool L = pos > 1 && c[pos] != c[pos - 1], R = pos < n && c[pos] != c[pos + 1];
        if (L && R) erase(*tmp), erase(*it);
        else if (L) erase(*tmp), insert(++pos);
        else if (R) erase(*it);
      } else {
        insert(pos + 1);
        if (pos > 1) erase(pos);
      }
    } else if (*it == pos + 1) {
      insert(pos);
      if (pos < n) erase(*it);
    } else {
      int r = *it, l = *(--it);
      insert(pos), insert(pos + 1);
    }
    if (cur != a[o[i + 1]]) {
      for (auto x : pts) {
        auto it = segs.find(x);
        if (it != segs.end()) {
          auto tmp = it;
          check(x, *(++it));
          check(*(--tmp), x);
        } else {
          auto it = segs.upper_bound(x);
          int r = *it, l = *(--it);
          check(l, r);
        }
      }
      pts.clear();
    };
  }
  printf("%d\n", (ans - 1) / 2);
  for (int i = 1; i <= n; ++i) printf("%d%c", b[i], " \n"[i == n]);
  return 0;
}