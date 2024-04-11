#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N], b[N], id[N]; 
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    for (int j = 1; j < i; ++j) {
      cnt += a[i] < a[j]; 
    }
    id[i] = i;
  }
  sort(id + 1, id + n + 1, [&](int i, int j) {
    return a[i] != a[j] ? a[i] > a[j] : i > j;
  });
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    sort(id + 1, id + i);
    for (int j = 1; j < i && id[j] < id[i]; ++j) {
      if (a[id[j]] > a[id[i]]) {
        printf("%d %d\n", id[j], id[i]);
      }
    }
  }
  return 0;
}