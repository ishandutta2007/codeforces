#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%*d", &l1, &r1, &l2);
    r2 = l2 + 1;
    pair <int, int> ans = {-1, -1};
    for (int x : vector <int>{l1, r1})
      for (int y : vector<int>{r2, l2})
        if (x != y)
          ans = {x, y};
      printf("%d %d\n", ans.first, ans.second);
  }
}