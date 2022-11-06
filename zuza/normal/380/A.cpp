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

typedef long long llint;

int main(void)
{
  const int MAXOPER = 1e5 + 123;
  const int MAXN = 1e5 + 123;

  vector<llint> V;
  llint sz = 0;

  static llint sz_after[MAXOPER];
  static int oper_tip[MAXOPER];
  static int oper_l[MAXOPER];
  static int oper_c[MAXOPER];
  static int oper_x[MAXOPER];  

  int n_oper; scanf("%d", &n_oper);
  REP(i_oper, n_oper) {
    int tip; scanf("%d", &tip);
    oper_tip[i_oper] = tip;

    if (tip == 1) {
      int x; scanf("%d", &x);
      oper_x[i_oper] = x;
      if ((int)V.size() < MAXN) V.push_back(x);
      ++sz;
    } else { // tip == 2
      int l, c; scanf("%d %d", &l, &c);
      oper_l[i_oper] = l;
      oper_c[i_oper] = c;
      REP(i, c) {
        if ((int)V.size() >= MAXN) break;
        REP(j, l) {
          if ((int)V.size() >= MAXN) break;
          V.push_back(V[j]);
        }
      }
      sz += l*c;
    }

    sz_after[i_oper] = sz;
  }

  int n_q; scanf("%d", &n_q);
  REP(i_q, n_q) {
    llint idx; cin >> idx; --idx;
    int o_idx = upper_bound(sz_after, sz_after + n_oper, idx) - sz_after;
    llint sol;
    if (oper_tip[o_idx] == 1) sol = oper_x[o_idx];
    else {
      sol = V[(idx - sz_after[o_idx-1]) % oper_l[o_idx]];
    }

    cout << sol;
    if (i_q+1 < n_q) cout << " "; else cout << endl;
  }

  return 0;
}