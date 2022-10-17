#include <bits/stdc++.h>
const int N = 300005;
int n, k, fa[N << 1], sz[N << 1], ans;
std::vector<int> b[N];
char s[N];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int i = 1; i <= k * 2; ++i) {
    sz[i] = i > k;
  }
  for (int i = 1; i <= k; ++i) {
    int c;
    scanf("%d", &c);
    while (c--) {
      int x;
      scanf("%d", &x);
      b[x].push_back(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    auto find = [&](int x) {
      while (fa[x] && fa[fa[x]]) {
        x = fa[x] = fa[fa[x]];
      }
      return fa[x] ? fa[x] : x;
    };
    auto id = [&](int x, bool rev) {
      if (!rev) {
        return x;
      }
      if (x > k) {
        return x - k;
      } else {
        return x + k;
      }
    };
    int st = s[i] - '0';
    if (b[i].size() == 1) {
      int x = find(b[i][0]);
      ans += std::max(sz[id(x, !st)] - sz[id(x, st)], 0);
      sz[id(x, st)] = 1e9;
    } else if (b[i].size() == 2) {
      int x = find(b[i][0]), y = find(b[i][1]);
      auto merge = [&](int x, int y) {
        x = find(x);
        y = find(y);
        fa[y] = x;
        sz[x] += sz[y];
        sz[x] = std::min(sz[x], (int) 1e9);  
        return sz[x];
      };
      if (x ^ id(y, !st)) { 
        ans -= std::min(sz[x], sz[id(x, 1)]);
        ans -= std::min(sz[y], sz[id(y, 1)]);
        ans += std::min(merge(x, id(y, !st)), merge(id(x, 1), id(y, st)));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}