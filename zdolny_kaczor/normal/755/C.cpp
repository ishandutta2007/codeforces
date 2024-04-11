# include <bits/stdc++.h>
using namespace std;
int main() {
  set <int> a;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == i)
      a.insert(i + 1e7);
    a.insert(x);
  }
  printf("%d\n", (int) a.size() / 2);
}