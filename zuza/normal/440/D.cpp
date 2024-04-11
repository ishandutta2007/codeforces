#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 412;
const int inf = 1e9;

struct Edge {
  int a, b, idx;
};

vector<Edge> E[MAXN];
int dp[MAXN][MAXN][2];
int subtree[MAXN];

struct Recon {
  int asz, bsz, ahave, bhave, take;
};
Recon recon[MAXN][MAXN][2];
vector<int> recon_idxs;

void solve(int x, int dad, int K) {
  subtree[x] = 1;
  for (auto& e : E[x]) if (e.b != dad) solve(e.b, e.a, K);

  int (&f)[MAXN][2] = dp[x];
  REP(a, MAXN) REP(b, 2) f[a][b] = inf;
  f[1][0] = 0;

  for (auto& e : E[x]) {
    if (e.b == dad) continue;
    static int nf[MAXN][2];
    REP(a, MAXN) REP(b, 2) nf[a][b] = inf;

    int (&dpB)[MAXN][2] = dp[e.b];

    REP(asz, subtree[x]+1) REP(ahave, 2) {
      if (f[asz][ahave] >= inf) continue;

      REP(bsz, subtree[e.b]+1) REP(bhave, 2) {
        auto upd = [&](int nxsz, int nxhave, int cost, bool take) {
          if (nf[nxsz][nxhave] > cost) {
            nf[nxsz][nxhave] = cost;
            recon[e.idx][nxsz][nxhave] = {asz, bsz, ahave, bhave, take};
          }
        };
      
        upd(asz, ahave || bhave || (bsz==K), f[asz][ahave] + dpB[bsz][bhave] + 1, true);
        upd(asz+bsz, ahave || bhave, f[asz][ahave] + dpB[bsz][bhave], false);
      }
    }

    subtree[x] += subtree[e.b];
    REP(a, subtree[x]+1) REP(b, 2) f[a][b] = nf[a][b];
  }
}

void reconstruct(int x, int dad, int best_a, int best_b, int K) {
  for (int it = (int)E[x].size() - 1; it >= 0; --it) {
    auto& e = E[x][it];
    if (e.b == dad) continue;

    auto r = recon[e.idx][best_a][best_b];
    if (r.take) recon_idxs.push_back(e.idx);
    reconstruct(e.b, e.a, r.bsz, r.bhave, K);
    tie(best_a, best_b) = make_tuple(r.asz, r.ahave);
  }
}

int main(void)
{
  int n, k; scanf("%d %d", &n, &k);
  REP(i, n-1) {
    int a, b; scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back({a, b, i});
    E[b].push_back({b, a, i});
  }

  solve(0, -1, k);
  int ans = inf;
  int best_a = -1, best_b = -1;
  REP(a, subtree[0]+1) REP(b, 2) {
    if (a == k || b) {
      if (dp[0][a][b] < ans) {
        ans = dp[0][a][b];
        best_a = a;
        best_b = b;
      }
    }
  }

  recon_idxs.clear();
  printf("%d\n", ans);
  if (ans > 0) {
    reconstruct(0, -1, best_a, best_b, k);
    assert((int)recon_idxs.size() == ans);
    REP(i, ans) printf("%d%c", recon_idxs[i]+1, i+1 == ans ? '\n' : ' ');
  } else {
    putchar('\n');
  }
  return 0;
}