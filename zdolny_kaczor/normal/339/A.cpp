# include <bits/stdc++.h>
using namespace std;
int main() {
  vector <int> a;
  int n;
  while (scanf("%d", &n) != EOF) {
    a.push_back(n);
    getchar();
  }
  sort(a.begin(), a.end());
  bool first = true;
  for (auto x : a) {
    if (!first)
      putchar('+');
    first = false;
    printf("%d", x);
  }
}