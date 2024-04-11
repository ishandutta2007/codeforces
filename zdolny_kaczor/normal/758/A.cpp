# include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0, m = 0, n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    s += x;
    if (m < x)
      m = x;
  }
  printf("%d\n", n * m - s);
}