#include <cstdio>
#include <vector>

const int N = 2e5 + 10;

char s[N];

int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    int a, b;
    scanf("%d%d%s", &a, &b, s);
    int n = a + b;
    bool valid = true;
    std::vector<int> pos;
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] == '?' && s[n - 1 - i] == '?') {
        pos.push_back(i);
      } else if (s[i] != '?' && s[n - 1 - i] !='?') {
        valid &= s[i] == s[n - 1 - i];
      } else if (s[i] != '?') {
        s[n - 1 - i] = s[i];
      } else {
        s[i] = s[n - 1 - i];
      }
    }
    if (!valid) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') --a;
      if (s[i] == '1') --b;
    }
    if (n % 2 == 1 && s[n / 2] == '?') {
      if (a % 2 == 1) --a, s[n / 2] = '0';
      else if (b % 2 == 1) --b, s[n / 2] = '1';
    }
    if (a < 0 || b < 0 || a % 2 == 1 || b % 2 == 1) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < a / 2 + b / 2; ++i) {
      int p = pos[i];
      if (i < a / 2) {
        s[p] = s[n - 1 - p] = '0';
      } else {
        s[p] = s[n - 1 - p] = '1';
      }
    }
    puts(s);
  }
  return 0;
}