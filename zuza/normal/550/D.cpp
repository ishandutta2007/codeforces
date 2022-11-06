#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int nv = 0;
vector<pair<int, int> > out;

void solve(int k, int a) {
  int r = (k-1) / 2; 
  vector<int> vs = {a};
  REP(i, k+1) vs.push_back(nv++);
  REP(i, vs.size()) REP(j, r) out.push_back({vs[i], vs[(i+j+1)%vs.size()]});
  REP(i, r+1) out.push_back({vs[i+1], vs[i+1+r+1]});
}

int main(void) {
  int k; scanf("%d", &k);
  if (k%2 == 0) {
    puts("NO");
  } else {
    if (k == 1) {
      nv = 2;
      out.push_back({0, 1});
    } else {
      int a = nv++; solve(k, a);
      int b = nv++; solve(k, b);
      out.push_back({a, b});
    }

    printf("YES\n");
    printf("%d %d\n", nv, (int)out.size());
    for (auto p : out) printf("%d %d\n", p.first+1, p.second+1);
  }
  
  return 0;
}