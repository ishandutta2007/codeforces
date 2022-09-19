# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int spec = 3;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == spec) {
      printf("NO\n");
      return 0;
    }
    spec ^= x;
  }
  printf("YES\n");
  return 0;
}