#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  string b, s, t;
  cin >> b;
  for (int i = 0; i < 2; ++i) if (b[i] != 'X') s += b[i];
  cin >> b;
  for (int i = 1; i >= 0; --i) if (b[i] != 'X') s += b[i];
  cin >> b;
  for (int i = 0; i < 2; ++i) if (b[i] != 'X') t += b[i];
  cin >> b;
  for (int i = 1; i >= 0; --i) if (b[i] != 'X') t += b[i];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      int cnt = 0;
      for (int k = 0; k < 3; ++k) {
        cnt += s[(i + k) % 3] == t[(j + k) % 3];
      }
      if (cnt == 3) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}