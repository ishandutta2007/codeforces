#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int n;
vector<ll> k;
vvi es;
vb was;

ll dfs(int v) {
  was[v] = true;

  vector<pair<ll, int> > chi;
  for (int i = 0; i < es[v].size(); i++) {
    int b = es[v][i];
    if (!was[b]) {
      was[b] = true;
      chi.pb(mp(dfs(b), b));
    }
  }
  sort(chi.begin(), chi.end()); reverse(chi.begin(), chi.end());

  ll ans = 1; k[v]--;
  for (int i = 0; i < chi.size() && k[v]; i++) {
    ans += chi[i].first + 1;
    k[v]--;
  }
  for (int i = 0; i < chi.size() && k[v]; i++) {
    int b = chi[i].second;
    ll cnt = min(k[b], k[v]);
    ans += 2 * cnt;
    k[b] -= cnt;
    k[v] -= cnt;
  }
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    k = vector<ll>(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &k[i]);

    es = vvi(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }
    int st;
    scanf("%d", &st), st--;
    k[st]++;

    was = vb(n, false);
    ll ans = dfs(st) - 1;
    printf("%I64d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}