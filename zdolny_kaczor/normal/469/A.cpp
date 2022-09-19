# include <bits/stdc++.h>
using namespace std;
bool poss[101];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2; ++i) {
    int x;
    scanf("%d", &x);
    while (x--) {
      int a;
      scanf("%d", &a);
      poss[a] = true;
    }
  }
  bool all = true;
  for (int i = 1; i <= n; ++i)
    if (!poss[i])
      all = false;
  puts(all ? "I become the guy." : "Oh, my keyboard!");
}