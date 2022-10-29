#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  long long ret = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (i && ((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0) ret += i;
    if ((s[i] - '0') % 4 == 0) ++ret;
  }
  cout << ret << endl;
  return 0;
}