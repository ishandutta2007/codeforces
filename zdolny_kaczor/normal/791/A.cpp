# include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int res = 0;
  scanf("%d%d", &a, &b);
  while (a <= b) {
    a *= 3;
    b *= 2;
    res++;
  }
  printf("%d\n", res);
}