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

int get_idx(vector<int>& v, int x) {
  auto it = lower_bound(v.begin(), v.end(), x); assert(*it == x);
  return it - v.begin();
}

const int inf = 1e9;
const int MAXN = 2e5 + 123;

struct Iv { int a, b, idx, color; int used; };
vector<int> E[MAXN];
vector<Iv> is;

void euler(int x) {
  for (int e_idx : E[x]) {
    Iv& e = is[ e_idx ];

    if (e.used) continue;
    e.used = true;
    int y = e.a + e.b - x;

    if (x < y) e.color = 0;
    else e.color = 1;

    euler(y);
  }
}

int main(void)
{
  int n; scanf("%d", &n);
  vector<int> rez;

  REP(i, n) { 
    int a, b; scanf("%d %d", &a, &b);
    is.push_back({a, b+1, i, -1, false});
    rez.push_back(a);
    rez.push_back(b+1);
  }
  sort(rez.begin(), rez.end());
  rez.erase(unique(rez.begin(), rez.end()), rez.end());

  REP(i, n) is[i].a = get_idx(rez, is[i].a);
  REP(i, n) is[i].b = get_idx(rez, is[i].b);

  REP(i, n) {
    E[ is[i].a ].push_back(i);
    E[ is[i].b ].push_back(i);
  }
  int last = -1;
  REP(i, (int)rez.size()) {
    if (E[i].size()%2 == 1) {
      if (last == -1) last = i;
      else {
        is.push_back({last, i, inf, -1, false});
        E[ last ].push_back(is.size() - 1);
        E[ i ].push_back(is.size() - 1);
        last = -1;
      }
    }
  }
  REP(i, (int)rez.size()) assert(E[i].size()%2 == 0);
  REP(i, (int)rez.size()) euler(i);


  sort(is.begin(), is.end(), [](Iv a, Iv b) { return a.idx < b.idx; });
  REP(i, n) printf("%d%c", is[i].color, i+1 == n ? '\n' : ' ');

  return 0;
}