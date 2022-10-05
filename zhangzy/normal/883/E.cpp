#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50;

int n;
char s[maxn + 1], t[maxn + 1];
bool guessed[26];
bool succ[26];
bool appear[26];

int main(void) {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    if (s[i] != '*') {
      guessed[s[i] - 'a'] = true;
    }
  }
  for (int i = 0; i < 26; ++i) {
    succ[i] = !guessed[i];
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    scanf("%s", t);
    bool match = true;
    memset(appear, 0, sizeof appear);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        if (guessed[t[i] - 'a']) {
          match = false;
          break;
        }
        appear[t[i] - 'a'] = true;
      } else {
        if (s[i] != t[i]) {
          match = false;
          break;
        }
      }
    }
    if (!match) {
      continue;
    }
    for (int i = 0; i < 26; ++i) {
      if (!appear[i]) {
        succ[i] = false;
      }
    }
  }
  printf("%d\n", count(succ, succ + 26, true));
  return 0;
}