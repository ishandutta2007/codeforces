#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, p[N];
vector<int> g[N];
int d[N], mnd[N], mxd[N];
int sz[N];
int dp[N];

int val[N], cnt[N];

void init(int pos) {
  val[pos] = 0;
  cnt[val[pos]]++;
}

void add(int pos, int x) {
  cnt[val[pos]]--;
  val[pos] ^= x;
  cnt[val[pos]]++;
}
int get(int x = 0) {
  while (cnt[x])
    x++;
  return x;
}
void clear(int l, int r) {
  for (int i = l; i <= r; i++)
    cnt[val[i]]--, val[i] = 0;
}

void pre_dfs(int v, int depth = 0) {
  d[v] = depth;
  mnd[v] = n;
  mxd[v] = 0;
  sz[v] = 1;

  bool leaf = 1;
  for (auto to : g[v]) {
    pre_dfs(to, depth + 1);
    sz[v] += sz[to];
    mnd[v] = min(mnd[v], mnd[to]);
    mxd[v] = max(mxd[v], mxd[to]);
    leaf = 0;
  }
  if (leaf)
    mnd[v] = mxd[v] = d[v];
}

void add_dfs(int v, int mnd) {
  if (d[v] <= mnd + 1)
    add(d[v], dp[v]);
  for (auto to : g[v])
    add_dfs(to, mnd);
}

int dfs(int v) {
  pii mx = {0, 0};
  for (auto to : g[v])
    mx = max(mx, {sz[to], to});

  for (auto to : g[v]) {
    if (to != mx.s) {
      dfs(to);
      clear(d[to], mnd[to] + 1);
    }
  }

  if (mx.s){
    dfs(mx.s);
    clear(mnd[v] + 2, mnd[mx.s] + 1);
  }else{
    init(d[v] + 1);
  }

  for (auto to : g[v])
    if (to != mx.s)
      add_dfs(to, mnd[v]);

  if(g[v].size() > 1)
    dp[v] = get(0);
  else
    dp[v] = get(dp[mx.s]);

  // cerr << v << " " << dp[v] << endl;
  // for(int i = d[v] + 1; i <= mnd[v] + 1; i++)
  //   cerr << val[i] << " ";
  // cerr << endl;
  // for(int i = 0; i < n; i++)
  //   cerr << cnt[i] << " ";
  // cerr << endl;

  init(d[v]);
  add(d[v], dp[v]);

  return dp[v];
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    if (p[i])
      g[p[i]].pb(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!p[i]) {
      pre_dfs(i);
      ans ^= dfs(i);
      clear(d[i], mnd[i] + 1);
    }
  if (ans)
    printf("YES\n");
  else
    printf("NO\n");

  for (int i = 1; i <= n; i++)
    g[i].clear();
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}