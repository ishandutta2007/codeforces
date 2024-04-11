# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  n *= 3;
  int s[3] = {};
  while (n--) {
    int x;
    scanf("%d", &x);
    s[n % 3] += x;
  }
  int x = s[0] * 147 + s[1] * 123 + s[2];
  if (x)
    printf("NO\n");
  else
    printf("YES\n");
}