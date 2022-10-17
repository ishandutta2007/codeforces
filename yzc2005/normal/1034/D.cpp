#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, k, f[N];
set<pair<int, int>> s;
set<pair<int, int>>::iterator it, tmp;
vector<pair<int, int>> op[N];
int main() {
  scanf("%d%d", &n, &k);
  s.insert({1, 0});
  s.insert({1e9, 0});
  for (int i = 1; i <= n; ++i) {
    int l, r, x;
    scanf("%d%d", &l, &r);
    tmp = (it = s.upper_bound({l, n}))--;
    op[i].push_back({x = it->second, it->first - tmp->first});
    if (it->first < l) {
      op[i].push_back({x, l - it->first});
    } else {
      s.erase(it);
    }
    s.insert({l, i});
    op[i].push_back({i, r - l});
    while (tmp->first < r) {
      it = tmp++;
      op[i].push_back({x = it->second, it->first - tmp->first});
      s.erase(it);
    }
    if (tmp->first > r) {
      op[i].push_back({x, tmp->first - r});
      s.insert({r, x});
    }
  }
  long long ans;
  int l = 1, r = 1e9; 
  while (l <= r) {
    int mid = l + r >> 1;
    memset(f, 0, sizeof(f));
    long long sum = 0, tot = 0, val = 0, cur = 0;
    for (int i = 1, j = 1; i <= n; ++i) { 
      for (auto opt : op[i]) {
        val += 1ll * min(opt.first, j - 1) * opt.second;
        f[opt.first] += opt.second;
        if (opt.first >= j) {
          cur += opt.second;
        }
      }
      while (j <= i && cur >= mid) {
        val += cur;
        cur -= f[j++];
      } 
      sum += val;
      tot += j - 1;
    } 
    if (tot >= k) {
      ans = sum - (tot - k) * mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}