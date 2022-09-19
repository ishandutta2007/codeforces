#include <bits/stdc++.h>
using namespace std;
vector <int> seen[3];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    seen[x-1].push_back(i);
  }
  int w = min(seen[0].size(), min(seen[1].size(), seen[2].size()));
  printf("%d\n", w);
  for (int i = 0; i < w; ++i)
    printf("%d %d %d\n", seen[0][i], seen[1][i], seen[2][i]);
}