# include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, k;
  scanf("%d%d%d", &k, &n, &w);
  printf("%d\n", max(0, k * w * (w + 1) / 2 - n));
}