# include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, a;
  scanf("%d%d%d", &l, &r, &a);
  printf("%d\n", min(l + r + a, min(2 * (l + a), 2 * (r + a))) / 2 * 2);
}