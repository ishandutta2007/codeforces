# include <bits/stdc++.h>
using namespace std;
const int B = 1e9 + 44;
int main() {
  printf("YES\n");
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d%*d%*d", &x, &y);
    x += B;
    y += B;
    printf("%d\n", 1 + 2 * (x % 2) + y % 2);
  }
}