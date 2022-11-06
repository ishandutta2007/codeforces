#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <deque>

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

const int MAXN = 1e5 + 123;

deque< vector<int> > groups[MAXN];
int used_in_group[MAXN];
int good[MAXN];

vector<int> A[MAXN];

int main(void)
{
  int R, S; scanf("%d %d", &R, &S);

  auto cmpf = [](int a, int b) {
    return make_pair(-good[a], a) < make_pair(-good[b], b);
  };
  set<int, decltype(cmpf)> pq(cmpf);

  memset(good, 0, sizeof good);
  REP(i, R) {
    static map<int, vector<int> > M; M.clear();
    REP(j, S) {
      int x; scanf("%d", &x); A[i].push_back(x);
      if (x != -1) {
        M[x].push_back(j);
      } else {
        ++good[j];
      }
    }
    for (auto& p : M) groups[i].push_back(p.second);
    if (!groups[i].empty()) for (int idx : groups[i].front()) ++good[idx];
    used_in_group[i] = 0;
  }
  REP(i, S) pq.insert(i);

  vector<int> recon;
  REP(iter, S) {
    int ex = *pq.begin(); pq.erase(pq.begin());
    if (good[ex] != R) break;
    recon.push_back(ex);

    REP(i, R) {
      if (A[i][ex] != -1) {
        assert(!groups[i].empty());        
        if (++used_in_group[i] == (int)groups[i].front().size()) {
          used_in_group[i] = 0;
          groups[i].pop_front();
          if (!groups[i].empty()) {
            for (int idx : groups[i].front()) {
              assert(pq.count(idx));
              pq.erase(idx);
              ++good[idx];
              pq.insert(idx);
            }
          }
        }
      }

    }
  }

  if ((int)recon.size() == S) REP(i, S) printf("%d%c", recon[i]+1, i+1 == S ? '\n' : ' ');
  else puts("-1");
  
  return 0;
}