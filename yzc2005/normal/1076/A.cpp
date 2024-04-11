#include <bits/stdc++.h>
std::string s;
int main() {
  int n; std::cin >> n >> s;
  for (int i = 0; i < n; ++i)
    if (s[i] > s[i + 1] || i == n - 1) {
      for (int j = 0; j < i; ++j) printf("%c", s[j]);
      for (int j = i + 1; j < n; ++j) printf("%c", s[j]);
      return 0;
    }
  return std::cout << s, 0;
}