#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, k, p[N], sz[N];
int pp(int v) {
  if (p[v] == v)
    return v;
  return p[v] = pp(p[v]);
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    p[i] = i, sz[i] = 1;
  for (int i = 1; i <= m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);

    v = pp(v);
    u = pp(u);
    if (v == u) {
      k++;
    } else {
      sz[v] += sz[u];
      p[u] = v;
    }
    vector<int> vec;
    for (int i = 1; i <= n; i++)
      if (p[i] == i)
        vec.pb(sz[i]);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int ans = 0;
    for (int i = 0; i <= k && i < vec.size(); i++)
      ans += vec[i];
    printf("%d\n", ans - 1);
  }
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}