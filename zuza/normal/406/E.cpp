#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;
struct S { int prvi, f; }; // pazi na F!

const int inf = 1e9 + 123;

llint L;
int n_s;
llint best_val = 0, combs = 0;
vector<S> V;

void solve() {
  auto upd = [](llint val, llint kol) {
    if (kol == 0) return;
    if (val > best_val) {
      best_val = val;
      combs = 0;
    }
    if (val == best_val) combs += kol;
  };

  // count 000

  int min_0 = inf, max_0 = -inf;
  int kol_min = 0, kol_max = 0;
  int cnt_0 = 0, cnt_1 = 0;
  llint sol_000 = 0;

  REP(i, n_s) {
    cnt_0 += (V[i].prvi == 0);
    cnt_1 += (V[i].prvi == 1);
    if (V[i].prvi != 0) continue;

    if (V[i].f < min_0) { min_0 = V[i].f; kol_min = 0; }
    if (V[i].f == min_0) { ++kol_min; }

    if (V[i].f > max_0) { max_0 = V[i].f; kol_max = 0; }
    if (V[i].f == max_0) { ++kol_max; }
  }

  llint prije_min = 0;
  llint poslije_max = kol_max;
  REP(i, n_s) {
    if (V[i].prvi != 0) continue;
    poslije_max -= (V[i].f == max_0);
    sol_000 += poslije_max * prije_min;
    prije_min += (V[i].f == min_0);
  }

  upd(max_0 - min_0, sol_000);

  // count 010
  { int l_0 = 0, r_0 = cnt_0;
    REP(i, n_s) {
      r_0 -= (V[i].prvi == 0);
      if (V[i].prvi == 1) {
        upd(2*L, (llint)l_0 * r_0);
      }
      l_0 += (V[i].prvi == 0);
    }
  }
  ////// count 001
  { int left_0 = cnt_0;
    int close_1 = inf, kol_close = 0;
    for (int i = n_s-1; i >= 0; --i) {
      if (V[i].prvi == 1) {
        if (V[i].f < close_1) { close_1 = V[i].f; kol_close = 0; } // !
        if (V[i].f == close_1) ++kol_close;
      }

      if (V[i].prvi == 0) { // srednji 0
        --left_0;
        upd(2*L - 2LL*(close_1 - V[i].f), (llint)left_0 * kol_close);
      }
    }
  }
  // count 100
  { int r_0 = cnt_0;
    int close_1 = 0, kol_close = 0;
    REP(i, n_s) {
      if (V[i].prvi == 1) {
        if (V[i].f > close_1) { close_1 = V[i].f; kol_close = 0; }
        if (V[i].f == close_1) ++kol_close;
      }

      if (V[i].prvi == 0) {
        --r_0;
        upd(2*L - 2*(V[i].f - close_1), (llint)r_0 * kol_close);
      }
    }
  }
  
}

int main(void)
{
  scanf(LLD " %d", &L, &n_s);

  V.resize(n_s);
  REP(i, n_s) {
    int prvi, f; scanf("%d %d", &prvi, &f);
    V[i] = { prvi, f };
  }

  sort(V.begin(), V.end(), [](S a, S b) {
      return a.f < b.f;
    });

  //  REP(i, n_s) printf("%d %d\n", V[i].prvi, V[i].f); putchar('\n');

  solve();

  REP(i, n_s) V[i].prvi ^= 1;
  solve();
  printf(LLD "\n", combs);

  return 0;
}