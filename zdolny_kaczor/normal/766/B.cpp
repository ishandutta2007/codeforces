# include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 44;
int o[MN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", o + i);
  for (int i = 0; i < 1e6; ++i) {
    int a = rand() % n, b = rand() % n, c = rand() % n;
    if (a != b && b != c && c != a && o[a] + o[b] > o[c] &&
    o[b] + o[c] > o[a] && o[a] + o[c] > o[b]) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}