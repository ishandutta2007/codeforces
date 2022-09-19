# include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  bool small = false, large = false, digit = false;
  for (auto c : a) {
    if (c >= '0' && c <= '9')
      digit = true;
    if (c >= 'A' && c <= 'Z')
      large = true;
    if (c >= 'a' && c <= 'z')
      small =true;
  }
  bool good = small && large && digit && a.size() >= 5;
  if (good)
    printf("Correct");
    else
    printf("Too weak");
}