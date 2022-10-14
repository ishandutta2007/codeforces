#include <bits/stdc++.h>

char str[210000];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", str);
    int l = strlen(str);
    int balance = 0;
    if (str[l - 1] == 'A') {
      puts("NO");
      goto end;
    }
    for (int i = 0; i < l; ++i) {
      if (str[i] == 'A')
        ++balance;
      else {
        if (balance == 0) {
          puts("NO");
          goto end;
        } else {
          --balance;
        }
      }
    }
    puts("YES");
  end:;
  }
}