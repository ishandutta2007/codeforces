# include <bits/stdc++.h>
using namespace std;
const int MN = 51;
char in[MN];
int main() {
  int n, t;
  scanf("%d%d%s", &n, &t, in);
  for (int i = 0; i < t; ++i) {
    for (int i = 0; i < n - 1; ++i)
      if (in[i] == 'B' && in[i + 1] == 'G') {
        swap(in[i], in[i + 1]);
        i++;
      }
  }
  printf("%s\n", in);
}