# include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string in = "hello#";
  int i = 0;
  for (auto c : s) {
    if (c == in[i])
      i++;
  }
  if (i == 5)
    printf("YES\n");
  else
    printf("NO\n");
}