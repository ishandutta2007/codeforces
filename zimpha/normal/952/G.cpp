#include <cstdio>

unsigned char s[100];

int main() {
  scanf("%s", s);
  for (int it = 0; it < 256; ++it) printf("..");
  puts("");
  for (int i = 0; s[i]; ++i) {
    s[i] = 256 - s[i];
    for (int it = 0; it < s[i]; ++it) {
      printf(".X");
    }
    for (int it = s[i]; it < 256; ++it) {
      printf("..");
    }
    puts("");
    printf(".X");
    for (int it = 1; it < 256; ++it) printf("..");
    puts("");
    printf("..");
    for (int it = s[i]; it < 256; ++it) {
      printf(".X");
    }
    for (int it = 256 - s[i] + 1; it < 256; ++it) {
      printf("..");
    }
    puts("");
    for (int it = 0; it < 256; ++it) printf("..");
    puts("");
  }
  return 0;
}