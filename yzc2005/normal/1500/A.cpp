#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 2500005;
int n, a[N], p[N];
pair<int, int> v[M];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), p[i] = i;
  sort(p + 1, p + n + 1, [&](int i, int j) {return a[i] < a[j];});
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int d = a[p[i]] - a[p[j]];
      if (!v[d].first) v[d] = {p[j], p[i]};
      else {
        int x, y; tie(x, y) = v[d];
        if (p[j] == x || p[j] == y || p[i] == x || p[i] == y) continue;
        return printf("YES\n%d %d %d %d\n", x, p[i], y, p[j]), 0;
      }
    }
  }
  return puts("NO"), 0;
}