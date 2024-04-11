# include <bits/stdc++.h>
using namespace std;
void output(int n, int base) {
  if (n == 0) return;
  output(n / base, base);
  printf("%d", n % base);
}
int main() {
  int k;
  scanf("%d", &k);
  for (int i = 1; i < k; ++i) {
    for (int j = 1; j < k; ++j) {
      output(i * j, k);
      printf(" ");
    }
    printf("\n");
  }
}