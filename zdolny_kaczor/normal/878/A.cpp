#include <bits/stdc++.h>
int main(){
  int n;
  int ze=0, je=1023;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char c; int x;
    scanf(" %c%d", &c, &x);
    if (c=='^') ze^= x, je^=x;
    if (c == '|') ze |= x, je |= x;
    if (c=='&') ze &= x, je &= x;
  }
  printf("2\n& %d\n^ %d\n", ze^je, ze);
}