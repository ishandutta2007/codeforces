#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    putchar('a' + i / 2 % 2);
  printf("\n");
}