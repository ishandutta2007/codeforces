#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, k, a[N];

void solve() {
  memset(a, 0, sizeof a);
  scanf("%d%d", &n, &k);
  vector<pair<int, int>> cur;
  for (int i = 1; i <= k; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    a[x] = 1, a[y] = -1;
    cur.emplace_back(x, y);
  }
  vector<int> rest;
  for (int i = 1; i <= 2 * n; ++i)
    if (a[i] == 0) rest.emplace_back(i);
  k = n - k;
  for (int i = 0; i < k; ++i) cur.emplace_back(rest[i], rest[i + k]);
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      auto x = cur[i], y = cur[j];
      if (x.first > y.first) swap(x, y);
      ans += y.first < x.second && y.second > x.second;
    }
  printf("%d\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while (t--) solve();
  return 0;
}