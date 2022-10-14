#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "std"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class Dsu {
  vi par, ss, ans;
  
  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
  public:
  Dsu(int n = 0) : par(n), ss(n, 1), ans(n) {
    for (int i = 0; i < n; i++)
      par[i] = ans[i] = i;
  }
  int getAns(int x) { return ans[get(x)]; }
  void mergeTo(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;

    int nv = ans[b];
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
    ans[b] = nv;
  }
};

vb was;
vvi es, esid;

vvi rqs, rqids;
vi rans;

Dsu dsu;

void dfs(int v) {
  was[v] = true;
  for (int i = 0; i < sz(rqs[v]); i++) {
    int b = rqs[v][i];
    if (!was[b]) continue;
    
    int id = rqids[v][i];
    assert(rans[id] < 0);
    rans[id] = dsu.getAns(b);
  }
  
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (was[b]) continue;
    dfs(b);
    dsu.mergeTo(b, v);
  }
}

vi eans;
vi ds;
int dfs2(int v) {
  was[v] = true;
  int res = ds[v];
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (was[b]) continue;
    int cres = dfs2(b);
    eans[esid[v][i]] = cres;
    res += cres;
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n); esid = vvi(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b); esid[a].pb(i);
      es[b].pb(a); esid[b].pb(i);
    }
    
    int k;
    scanf("%d", &k);
    rqs = vvi(n);
    rqids = vvi(n);
    
    vector<pii> rls;
    for (int i = 0; i < k; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      rls.pb(mp(a, b));
      rqs[a].pb(b); rqids[a].pb(i);
      if (a != b) {
        rqs[b].pb(a); rqids[b].pb(i);
      }
    }
    
    was = vb(n, false);
    rans = vi(k, -1);
    dsu = Dsu(n);
    dfs(0);
    
    ds = vi(n, 0);
    for (int i = 0; i < k; i++) {
      ds[rls[i].first]++;
      ds[rls[i].second]++;
      ds[rans[i]] -= 2;
    }
    
    eans = vi(n - 1, 0);
    was = vb(n, false);
    dfs2(0);
    for (int i = 0; i <  n - 1; i++)
      printf("%d%c", eans[i], "\n "[i + 1 < n - 1]);
  }
  return 0;
}