#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 2e5 + 123;

int dad[MAXN];
llint weight[MAXN];

int v, e, n_build, n_rf;

int find_dad(int x) {
  if (dad[x] == -1) return x;
  return dad[x] = find_dad(dad[x]);
}

const llint inf = 1e9;
int eA = -1, eB = -1;

int main(void)
{
  scanf("%d %d %d %d", &v, &e, &n_build, &n_rf);
  REP(i, v) { dad[i] = -1; weight[i] = 0; }
  REP(i, e) {
    int a, b, L; scanf("%d %d %d", &a, &b, &L); --a, --b;
    eA = a; eB = b;
    int ad = find_dad(a);
    int bd = find_dad(b);
    if (ad == bd) {
      weight[ad] += L;
    } else {
      dad[ad] = bd;
      weight[bd] += weight[ad];
      weight[bd] += L;
      weight[bd] = min(weight[bd], inf);
    }
  }

  bool ok = true;
  typedef pair<llint, llint> par;
  auto cmpf = [](par a, par b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
  };
  set<par, decltype(cmpf) > pq(cmpf);
  REP(i, v) if (dad[i] == -1) {
    pq.insert(make_pair(weight[i], i));
  }

  vector<par> output;
  llint cost = 0;
  
  while (n_build > 0 && (int)pq.size() > n_rf) {
    par a = *pq.begin(); pq.erase(pq.begin());
    par b = *pq.begin(); pq.erase(pq.begin());

    llint new_w = min(a.first + b.first + 1, inf);
    cost += new_w;
    output.push_back(par(eA = a.second, eB = b.second));
    pq.insert(make_pair(min(inf, a.first+b.first+new_w), a.second));
    --n_build;
  }

  while (eA != -1 && n_build > 0) {
    output.push_back(par(eA, eB));
    cost += 1000;
    --n_build;
  }

  if (n_build > 0) ok = false;
  if ((int)pq.size() != n_rf) ok = false;

  if (!ok) {
    puts("NO");
  } else {
    puts("YES");
    for (par p : output) {
      printf("%d %d\n", (int)p.first + 1, (int)p.second + 1);
    }
  }

  return 0;
}