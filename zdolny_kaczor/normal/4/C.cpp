# include <bits/stdc++.h>
using namespace std;
map <unsigned long long, int> a;
char in[40];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", in);
    unsigned long long hash = 0;
    for (int k = 0; in[k]; ++k)
      hash = ((hash * 12345) ^ in[k]) ^ (hash % 1000007);
    int n = a[hash]++;
    if (n == 0)
      printf("OK\n");
    else
      printf("%s%d\n", in, n);
  }
}