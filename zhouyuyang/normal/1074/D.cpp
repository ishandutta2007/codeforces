#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int q;
  scanf("%d", &q);
  int last = 0;
  map<int, pair<int, int>> p;

  function<pair<int, int>(int)> find = [&](int x) {
    if (p.find(x) == p.end()) {
      return make_pair(x, 0);
    } else {
      pair<int, int> f = find(p[x].first);
      return p[x] = make_pair(f.first, f.second ^ p[x].second);
    }
  };

  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r, value;
      scanf("%d %d %d", &l, &r, &value);
      l ^= last;
      r ^= last;
      value ^= last;
      if (l > r) {
        swap(l, r);
      }
      ++r;
      pair<int, int> fl = find(l), fr = find(r);
      if (fl.first != fr.first) {
        p[fl.first] = make_pair(fr.first, fl.second ^ fr.second ^ value);
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      l ^= last;
      r ^= last;
      if (l > r) {
        swap(l, r);
      }
      ++r;
      pair<int, int> fl = find(l), fr = find(r);
      if (fl.first == fr.first) {
        printf("%d\n", last = fl.second ^ fr.second);
      } else {
        puts("-1");
        last = 1;
      }
    }
  }
  return 0;
}