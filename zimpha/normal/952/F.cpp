#include <cstring>
#include <cstdio>

char s[100000];

int main() {
  scanf("%s", s);
  int ret = 0;
  for (int i = 0; s[i];) {
    if (i == 0 || s[i] == '-' || s[i] == '+') {
      int v = s[i] - '0', j = i + 1;
      for (j = i + 1; '0' <= s[j] && s[j] <= '9'; ++j) v = v * 10 + s[j] - '0';
      if (i == 0 || s[i] == '+') ret += v;
      else ret -= v;
      i = j;
    }
  }
  printf("%d\n", ret);
  return 0;
}