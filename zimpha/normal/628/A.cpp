#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, b, p;
  cin >> n >> b >> p;
  int x = 0, y = n * p;
  while (n != 1) {
    int k = 1;
    while (k < n) k <<= 1;
    x += b * k + k / 2;
    n = n - k / 2;
  }
  cout << x << " " << y << endl;
  return 0;
}