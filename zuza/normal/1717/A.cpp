#include <iostream>
using namespace std;

typedef long long llint;

int gcd(int a, int b) {
  if (b == 0) return a;
  if (a < b) return gcd(b, a);
  return gcd(b, a%b);
}

int lcm(int a, int b) { return a/gcd(a,b)*b; }

int main() {
  int ntc; cin >> ntc;
  
  for (int tc = 0; tc < ntc; ++tc) {
    llint cnt = 0;
    int n; cin >> n;

    for (int x : {1, 2, 3})
      for (int y : {1, 2, 3}) {
        if (x*y > 3) continue;
        int upper_limit_g = min(n / x, n / y);
        cnt += upper_limit_g;
      }

    cout << cnt << endl;
  }

  return 0;
}