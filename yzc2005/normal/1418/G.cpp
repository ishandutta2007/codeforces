#include <bits/stdc++.h>
const int N = 500005;
using ull = unsigned long long;
int n, a[N], s[N], pre[N], last[N];
ull w[N], h[N];
std::unordered_map<ull, int> cnt;
int main() {
  srand(time(0));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pre[i] = last[a[i]];
    last[a[i]] = i;
    w[i] = 1ull * rand() ^ (1ull * rand() << 15) ^ (1ull * rand() << 30) ^ (1ull * rand() << 45);
  }
  cnt[0] = 1;
  ull cur = 0, ans = 0;
  for (int i = 1, l = 1; i <= n; ++i) {
    int prev = s[a[i]];
    s[a[i]] = (s[a[i]] + 1) % 3;
    cur += (s[a[i]] - prev) * w[a[i]]; 
    h[i] = cur;
    int L = pre[pre[pre[i]]];
    for (int j = l; j <= L; ++j) {
      --cnt[h[j - 1]];
    } 
    l = std::max(l, L + 1);
    ans += cnt[h[i]];
    ++cnt[h[i]];
  }
  printf("%llu\n", ans);
  return 0;
}