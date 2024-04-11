#include <bits/stdc++.h>
using namespace std;
int h, m, x, a;
int main() {
  scanf("%d:%d%d", &h, &m, &a);
  x = h * 60 + m + a, x %= 1440;
  h = x / 60, m = x % 60;
  printf("%02d:%02d\n", h, m);
}