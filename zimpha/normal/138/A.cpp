#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

const std::vector<std::string> type = { "aaaa", "aabb", "abab", "abba" };

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<std::vector<std::string>> rhyme(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      static char s[10000 + 10];
      scanf("%s", s);
      int m = strlen(s);
      std::string suffix;
      int rest = k;
      for (int x = m - 1; x >= 0 && rest > 0; --x) {
        if (s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o' || s[x] == 'u') {
          --rest;
        }
        suffix.push_back(s[x]);
      }
      if (rest) {
        puts("NO");
        return 0;
      }
      rhyme[i].push_back(suffix);
    }
  }
  for (int i = 0; i < 4; ++i) {
    bool valid = true;
    for (int j = 0; j < n && valid; ++j) {
      for (int x = 0; x < 4 && valid; ++x) {
        for (int y = x + 1; y < 4 && valid; ++y) {
          if (type[i][x] == type[i][y] && rhyme[j][x] != rhyme[j][y]) {
            valid = false;
          }
        }
      }
    }
    if (valid) {
      puts(type[i].c_str());
      return 0;
    }
  }
  puts("NO");
  return 0;
}