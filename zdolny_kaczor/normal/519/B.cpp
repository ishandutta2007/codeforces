# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0, c = 0;
  for (int _ = 0; _ < n; ++_) {
    int x;
    scanf("%d", &x);
    a ^= x;
  }
  for (int _ = 0; _ < n - 1; ++_) {
    int x;
    scanf("%d", &x);
    b ^= x;
  }
  for (int _ = 0; _ < n - 2; ++_) {
    int x;
    scanf("%d", &x);
    c ^= x;
  }
  printf("%d %d\n", a^b, b^c);
}