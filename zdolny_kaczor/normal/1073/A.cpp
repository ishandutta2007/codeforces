#include <bits/stdc++.h>
using namespace std;
char in[1010];
int main() {
  int n;
  scanf("%d%s", &n, in);
  for (int i = 1; i < n; ++i) {
    if (in[i - 1] != in[i])
      return 0 * printf("YES\n%c%c\n", in[i - 1], in[i]);
  }
  printf("NO\n");
}