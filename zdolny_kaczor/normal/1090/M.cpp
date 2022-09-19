#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d%*d", &n);
  int curr = 0;
  int ans = 0;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (last == x) {
      curr = 1;
      last = x;
    }
    else {
      last = x;
      curr++;
    }
    ans = max(curr, ans);
  }
  printf("%d\n", ans);
}