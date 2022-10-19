#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], b[N], c[N], id[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [&](int i, int j) {
    return b[i] > b[j];
  });
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    c[id[i]] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", c[i]);
  }
  return 0;
}