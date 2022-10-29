#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int a[MAXN], b[MAXN];
int n, m, d[MAXN], f[MAXN];

bool check(int k) {
  for (int i = 0; i < n; ++i) G[i].clear();
  for (int i = 0; i < n; ++i) f[i] = d[i] = 0;
  for (int i = 0; i < k; ++i) {
    G[a[i]].push_back(b[i]);
    d[b[i]]++;
  }
  queue<int> Q;
  for (int i = 0; i < n; ++i) if (d[i] == 0) {
    Q.push(i); f[i] = 1;
  }
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (auto &v: G[u]) {
      f[v] = max(f[v], f[u] + 1);
      if (--d[v] == 0) Q.push(v);
    }
  }
  return *max_element(f, f + n) == n;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", a + i, b + i);
    --a[i]; --b[i];
  }
  if (!check(m)) {
    puts("-1");
    return 0;
  }
  int l = 1, r = m;
  while (l < r) {
    int m = (l + r - 1) >> 1;
    if (check(m)) r = m;
    else l = m + 1;
  }
  cout << l << endl;
  return 0;
}