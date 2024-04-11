#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int n, k, p[N];
char a[N], b[N], t[N]; 

vector<pair<int, int>> solve(char *s) {
  vector<pair<int, int>> ans;
  int cnt = count(s + 1, s + n + 1, '1');
  if (k == 0 || k > cnt) {
    return ans;
  }
  int rest = 2 * n;
  auto get_pos = [&]() {
    int cur = 0;
    for (int i = 1; i <= n; ++i) 
      if (s[i] == '1') p[++cur] = i;
    p[++cur] = n + 1;
  };
  auto do_reverse = [&](int l, int r) {
    reverse(s + l, s + r + 1);
    ans.emplace_back(l, r);
    get_pos();
    --rest;
  }; 
  get_pos();
  for (int i = cnt + 1; i >= k + 1; --i) 
    do_reverse(p[i - k], p[i] - 1);
  if (k == cnt) {
    for (int i = 1; i <= n; ++i) t[i] = s[i];
    reverse(t + p[1], t + p[k] + 1);
    if (strcmp(t + 1, s + 1) > 0) do_reverse(p[1], p[k]);
    return ans;
  }
  if (k % 2 == 0) {
    while (rest > 1) {
      do_reverse(p[1] + 1, p[k + 1]);
      do_reverse(p[1], p[k + 1] - 1);
    }
  } else {
    while (rest > 1) {
      do_reverse(p[1], p[k + 1] - 1);
      do_reverse(p[2], p[k + 1]);
    }
  }
  return ans;
}

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s%s", a + 1, b + 1);
  int cnt = count(a + 1, a + n + 1, '1');
  if (cnt != count(b + 1, b + n + 1, '1')) {
    puts("-1");
    return;
  } 
  auto ansa = solve(a), ansb = solve(b);
  for (int i = 1; i <= n; ++i) {
    if (a[i] != b[i]) {
      puts("-1");
      return;
    }
  }
  printf("%d\n", ansa.size() + ansb.size());
  for (auto p : ansa) printf("%d %d\n", p.first, p.second);
  reverse(ansb.begin(), ansb.end());
  for (auto p : ansb) printf("%d %d\n", p.first, p.second);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}