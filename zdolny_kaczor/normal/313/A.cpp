# include <bits/stdc++.h>
using namespace std;
int digs[20];
int main() {
  int n;
  scanf("%d", &n);
  if (n >= 0)
    printf("%d\n", n);
  else {
    n = -n;
    int best = n;
    int l = 0;
    while (n > 0) {
      digs[l] = n % 10;
      n /= 10;
      l++;
    }
    if (l == 1) {
      printf("-%d\n", best);
      return 0;
    }
    for (int i = 0; i < 2; ++i) {
      int curr = 0;
      int last = -1;
      for (int j = l - 1; j >= 0; --j)
        if (i != j) {
          curr = curr * 10 + digs[j];
          if (last == -1)
            last = digs[j];
        }
      best = min(best, curr);
    }
    printf("%d\n", -best);
  }
}