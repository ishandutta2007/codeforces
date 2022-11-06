#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int base, lim;
vector<int> L, R;

vector<int> read_v() {
  int sz; scanf("%d", &sz);
  vector<int> ans(sz);
  REP(i, sz) scanf("%d", &ans[i]);
  return ans;
}

map<vector<int>, int> v2s;
map<int, vector<int> > s2v;
vector< vector<int> > spec;
vector< int> spec_val;

const int MAXN = 210;
const int mod = 1e9 + 7;

int next_state[MAXN][22];
int state_add[MAXN];

vector<int> substring(const vector<int>&v, int a, int b) {
  vector<int> ans;
  FOR(i, a, b) ans.push_back(v[i]);
  return ans;
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vect) {
  os << "{";
  for (typename vector<T>::const_iterator it = vect.begin(); it != vect.end(); ++it) {
    os << *it;
    if (next(it) != vect.end()) os << ", ";
  }  
  return os << "}";
}

int dp[201][201][501];

int solve(int x, int s, int k, int down, int up, int it, int first) {
  if (k > lim) return 0;

  if (x == 0) return 1;
  if (!first && !down && !up) if (dp[x][s][k] != -1) return dp[x][s][k];
  int ans = 0;

  for (int d = 0; d < base; ++d) {
    if (down && d < L[it]) continue;
    if (up && d > R[it]) continue;
    int nx_first = first && (d == 0);
    int nxs = nx_first ? 0 : next_state[s][d];
    ans += solve(x-1, nxs, k + state_add[nxs],
                 down && d == L[it],
                 up && d == R[it], it+1, nx_first);
    if (ans >= mod) ans -= mod;
  }

  if (!first && !down && !up) dp[x][s][k] = ans;
  return ans;
}

int main(void)
{
  int ns; scanf("%d %d %d", &ns, &base, &lim);

  L = read_v();
  R = read_v();
  while (L.size() < R.size()) L.insert(L.begin(), 0);

  REP(i, ns) {
    vector<int> s = read_v();
    spec.push_back(s);
    int val; scanf("%d", &val);
    spec_val.push_back(val);

    int sz = s.size();
    REP(j, sz+1) {
      auto cand = substring(s, 0, j);
      if (v2s.count(cand) == 0) {
        int cnt = (int)v2s.size();
        v2s[cand] = cnt;
        s2v[cnt] = cand;
      }
    }
  }

  assert((int)v2s.size() <= MAXN);

  for (auto& p : v2s) {
    REP(d, base) {
      vector<int> cand = p.first; cand.push_back(d);
      int maks = 0;

      REP(is, ns) {
        int ub = min(spec[is].size(), cand.size());

        REP(L, ub+1) {
          if (substring(cand, cand.size()-L, cand.size()) ==
              substring(spec[is], 0, L))
            maks = max(maks, L);
        }
      }

      vector<int> suf = substring(cand, cand.size()-maks, cand.size());
      next_state[p.second][d] = v2s[suf];
      //      TRACE(p.first _ d _ suf);
    }
  }
  REP(i, (int)s2v.size()) {
    vector<int>& cand = s2v[i];    
    REP(j, ns) {
      int sz = spec[j].size();

      if (spec[j].size() <= cand.size())
        if (substring(cand, cand.size()-sz, cand.size()) == spec[j])
          state_add[i] += spec_val[j];
    }

  }

  assert(v2s[vector<int>()] == 0);
  memset(dp, -1, sizeof dp);
  int ans = solve((int)L.size(), 0, 0, true, true, 0, true);
  printf("%d\n", ans);

  return 0;
}