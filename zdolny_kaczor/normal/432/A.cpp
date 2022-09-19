#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int c = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x + k <= 5) c++;
  }
  printf("%d\n", c / 3);
}