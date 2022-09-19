# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int c = 0, a = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    c -= x;
    c += y;
    a = max(a, c);
  }
  assert(c == 0);
  printf("%d\n", a);
}