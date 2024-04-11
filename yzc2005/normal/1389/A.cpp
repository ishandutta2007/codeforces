#include <bits/stdc++.h>
using namespace std;
int main() {
  int T; scanf("%d", &T); while (T--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (r & 1) --r;
    if (r / 2 >= l) printf("%d %d\n", r / 2, r);
    else puts("-1 -1");
  }
  return 0;
}