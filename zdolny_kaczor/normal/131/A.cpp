# include <bits/stdc++.h>
using namespace std;
int main() {
  char in[101];
  scanf("%s", in);
  bool c1 = true, c2 = true;
  for (int i = 0; in[i]; ++i) {
    if (in[i] & 32) {
      c1 = false;
      c2 = c2 && (i == 0);
    }
    else {
      c2 = c2 && (i != 0);
    }
  }
  if (c1 || c2)
    for (int i = 0; in[i]; ++i)
      in[i] ^= 32;
  printf("%s\n", in);
}