#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int n; scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++ i) {
    scanf("%d", &b[i]);
  }
  map<int, PII> mp;
  mp[0] = PII(-1, -1);
  LL sa(0), sb(0);
  for (int i = 0, j = 0; i < n; ++ i, ++ j) {
    sa += a[i];
    while (j < n && sb + b[j] <= sa) {
      sb += b[j]; ++ j;
    }
    j --;
    if (mp.count(sa - sb)) {
      int na = mp[sa - sb].first;
      int nb = mp[sa - sb].second;
      printf("%d\n", i - na);
      for (int x = na + 1; x <= i; ++ x) printf("%d ", x + 1);
      puts("");
      printf("%d\n", j - nb);
      for (int x = nb + 1; x <= j; ++ x) printf("%d ", x + 1);
      puts("");
      break;
    }
    mp[sa - sb] = PII(i, j);
  }
  return 0;
}