#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, k, p, inv[N], res[2][2];
vector<int> segs, tmp;

void dfs(int l, int r, int k) {
  if (l == r || k == 1) {
    segs.emplace_back(r - l + 1);
    tmp.emplace_back(r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  dfs(l, mid, k - 1);
  dfs(mid + 1, r, k - 1);
}

int calc(int a, int b) {
  int ans = 0;
  for (int i = 3; i <= a + b; ++i) {
    int inf = max(i - b, 1), suf = min(a, i - 1);
    assert(inf <= suf);
    ans = (ans + 1ll * (suf - inf + 1) * (i - 2) % p * inv[i]) % p;
  }
  return 1ll * ans * inv[2] % p;
}

int main() {
  scanf("%d%d%d", &n, &k, &p);
  inv[0] = inv[1] = 1;
  for (int i = 2; i < N; ++i) inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
  dfs(1, n, k);
  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  int ans = 0, m = tmp.size();
  assert(m <= 2);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      res[i][j] = calc(tmp[i], tmp[j]);
  int cnt[2] = {0, 0};
  for (int i = int(segs.size()) - 1; ~i; --i) {
    int cur = segs[i], ind = (cur != tmp[0]) ? 1 : 0;
    ans = (ans + 1ll * cur * (cur - 1) % p * inv[4]) % p;
    for (int j = 0; j < m; ++j) ans = (ans + 1ll * res[ind][j] * cnt[j]) % p;
    ++cnt[ind];
  }
  printf("%d\n", ans);
  return 0;
}