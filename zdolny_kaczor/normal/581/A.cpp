# include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d %d\n", min(a, b), abs(a - b) / 2);
}