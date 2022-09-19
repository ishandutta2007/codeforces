# include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d", &a);
  a += b;
  int c = a - b;
  if (c  % 2 == 0 && c > 2)
    printf("YES\n");
  else
    printf("NO\n");
}