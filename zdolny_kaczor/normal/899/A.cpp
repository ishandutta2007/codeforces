# include <bits/stdc++.h>
using namespace std;
int cou[3];
int main() {
  int n;
  scanf("%d", &n);
  for (int _ = 0; _ < n; ++_) {
    int x;
    scanf("%d", &x);
    cou[x]++;
  }
  printf("%d\n", min(cou[2], cou[1]) + max(0, (cou[1] - cou[2]) / 3));
}