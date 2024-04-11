#include <bits/stdc++.h>
const int N = 500005, M = 1 << 20;
int n, a[N], b[N], d[M];
int cnt, head[M], to[M * 2], nxt[M * 2], id[M * 2];
int p[N * 2], top;
bool vis[M];
inline void add(int u, int v, int w) {
  ++d[u];
  to[++cnt] = v;
  nxt[cnt] = head[u];
  id[cnt] = w;
  head[u] = cnt;
}
void dfs(int u) {
  for (int &i = head[u]; i; i = nxt[i]) {
    if (!vis[i / 2]) {
      vis[i / 2] = 1;
      int val = id[i];
      dfs(to[i]);
      p[++top] = val ^ 1;
      p[++top] = val;
    }
  }
}
inline bool check(int mid) {
  cnt = 1;
  top = 0;
  int m = 1 << mid;
  std::memset(head, 0, m * 4);
  std::memset(d, 0, m * 4);
  for (int i = 1; i <= n; ++i) {
    int A = a[i] & (m - 1), B = b[i] & (m - 1);
    add(A, B, i * 2);
    add(B, A, i * 2 + 1);
  }
  std::memset(vis, false, cnt);
  bool flag = 0;
  for (int i = 0; i < m; ++i) {    
    if (d[i] & 1) {
      return false;
    }
    if (head[i]) {
      if (flag) {
        return false;
      }
      flag = 1;
      dfs(i);
    }
  }
  return true;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i];
  }
  int l = 1, r = 20, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  check(ans);
  std::cout << ans << "\n";
  for (int i = 1; i <= n * 2; ++i) {
    std::cout << p[i] - 1 << " ";
  }
  return 0;
}