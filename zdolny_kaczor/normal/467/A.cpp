# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a + 2 <= b)
      c++;
  }
  printf("%d\n", c);
}