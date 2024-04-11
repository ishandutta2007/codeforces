# include <bits/stdc++.h>
using namespace std;
int give_odd() {
  static int x = -1;
  x += 2;
  return x;
}
int give_even() {
  static int x = 0;
  x += 2;
  return x;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < n; ++k) {
      printf("%d ", (abs(i - n / 2) + abs(k - n / 2) <= n / 2) ? give_odd() : give_even());
      for (int j = rand() % 5; j >= 0; --j)
        putchar(' ');
      if (rand() % 5 == 4)
        while (rand() % 4 != 3)
          printf("\n");
    }
}