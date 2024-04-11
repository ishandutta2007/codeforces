#include <bits/stdc++.h>
#include <unordered_set>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000500;

int n, q, a[N], ans[N];
vector<int> g[N];
vector<array<int, 3>> gq[N];

int cnt[N], lb[N], pos[N], val[N];

void add(int x, int k) {  
  // cerr << x << " " << k << endl;
  // for(int i = 1; i <= n; i++)
  //   cerr << cnt[i] << " ";
  // cerr << endl;
  // for(int i = 1; i <= n; i++)
  //   cerr << val[i] << " ";
  // cerr << endl;
  // for(int i = 1; i <= n; i++)
  //   cerr << pos[i] << " ";
  // cerr << endl;
  // for(int i = 0; i <= n; i++)
  //   cerr << lb[i] << " ";
  // cerr << endl;
  
  if (k == 1) {
    int y = val[lb[cnt[x] + 1] - 1];
    swap(val[pos[x]], val[pos[y]]);
    swap(pos[x], pos[y]);
    cnt[x]++;
    lb[cnt[x]]--;
  } else {
    int y = val[lb[cnt[x]]];
    swap(val[pos[x]], val[pos[y]]);
    swap(pos[x], pos[y]);
    lb[cnt[x]]++;
    cnt[x]--;
  }
}
int get(int l, int k) {
  int x = lb[l] + k -1;
  if(x > n)
    return - 1;
  // cerr << "Q" << l << " " << k << " " << val[x] << endl;
  return val[x];
}
void dfs(int v) {
  add(a[v], 1);
  for (auto it : gq[v])
    ans[it[2]] = get(it[0], it[1]);
  for (auto to : g[v])
    dfs(to);
  add(a[v], -1);
}
void solve() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    g[p].pb(i);
  }
  for (int i = 1; i <= n; i++)
    pos[i] = val[i] = i;
  lb[0] = 1;
  for (int i = 1; i <= n; i++)
    lb[i] = n + 1;

  for (int i = 1; i <= q; i++) {
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    gq[v].pb({l, k, i});
  }
  dfs(1);
  for (int i = 1; i <= q; i++)
    printf("%d ", ans[i]);
  printf("\n");

  for (int i = 0; i <= n; i++) {
    g[i].clear();
    gq[i].clear();
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--)
    solve();
}