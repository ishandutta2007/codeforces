#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  LL a, b;
  cin >> a >> b;
  int ret(0);
  for (int o = 0; o <= 61; ++ o) {
    for (int l = o + 2; l <= 62; ++ l) {
      LL x = (1ll << l) - 1;
      LL y = x ^ (1ll << o);
      if (y >= a && y <= b) {
        ret ++;
        //cerr << x << " " << y << endl;
      }
    }
  }
  cout << ret << endl;
  return 0;
}