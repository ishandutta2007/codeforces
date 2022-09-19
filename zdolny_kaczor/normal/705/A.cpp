# include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    if (i)
      printf(" that ");
    if (i % 2)
      printf("I love");
    else
      printf("I hate");
  }
  printf(" it\n");
}