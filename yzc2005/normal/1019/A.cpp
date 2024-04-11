#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18;

const int N = 3005;
int n, m, p[N], pp[N], c[N];
vector<int> v[N];
ll ans = inf;
bool vis[N];

ll solve(int mid) {
  memset(vis, false, sizeof vis);
  int cnt = count(p + 1, p + n + 1, 1);
  if (mid < cnt) return inf;
  ll ans = 0;
  for (int i = 2; i <= m; ++i) {
    if (v[i].size() < mid) continue;
    for (int j = 0; j <= v[i].size() - mid; ++j) {
      ans += c[v[i][j]], ++cnt;
      vis[v[i][j]] = true;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt >= mid) break;
    if (vis[pp[i]] || p[pp[i]] == 1) continue;
    ans += c[pp[i]], ++cnt;
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &p[i], &c[i]); 
    v[p[i]].emplace_back(i);
  }
  for (int i = 1; i <= m; ++i) sort(v[i].begin(), v[i].end(), [&](int i, int j) {return c[i] < c[j];});
  iota(pp + 1, pp + n + 1, 1);
  sort(pp + 1, pp + n + 1, [&](int i, int j) {return c[i] < c[j];});
  for (int i = 1; i <= n; ++i) ans = min(ans, solve(i));
  printf("%lld\n", ans); 
  return 0;
}