#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int main() {
  cin >> s;
  int n = s.length();
  vector<int> res(n);
  int l = 0, r = n - 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'l') {
      res[r--] = i;
    } else {
      res[l++] = i;
    }
  }
  for (auto i : res) printf("%d\n", i + 1);
}