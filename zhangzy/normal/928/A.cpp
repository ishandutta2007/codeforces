#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

const char *key = "0oo01ii11ll1illi";

bool Check(const char *s, const char *t) {
  int n = strlen(s), m = strlen(t);
  if (n != m) return false;
  for (int i = 0; i < n; ++i) {
    char a = tolower(s[i]), b = tolower(t[i]);
    bool bad = false;
    if (a == b) {
      bad = true;
    } else {
      for (int k = 0; k < 8; ++k) {
        if (key[k << 1] == a && key[k << 1 | 1] == b) {
          bad = true;
          break;
        }
      }
    }
    if (!bad) return false;
  }
  return true;
}

int main(void) {
  char s[51];
  scanf("%s", s);
  int n;
  scanf("%d", &n);
  while (n--) {
    char t[51];
    scanf("%s", t);
    if (Check(s, t)) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}