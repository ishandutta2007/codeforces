#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

//int f(int a) {
  //int res = 0;
  //for (int b = 1; b < a; ++b) {
    //res = max(res, __gcd(a & b, a ^ b));
  //}
  //return res;
//}

map<int, int> pre = {
  {3, 1},
  {7, 1},
  {15, 5},
  {31, 1},
  {63, 21},
  {127, 1},
  {255, 85},
  {511, 73},
  {1023, 341},
  {2047, 89},
  {4095, 1365},
  {8191, 1},
  {16383, 5461},
  {32767, 4681},
  {65535, 21845},
  {131071, 1},
  {262143, 87381},
  {524287, 1},
  {1048575, 349525},
  {2097151, 299593},
  {4194303, 1398101},
  {8388607, 178481},
  {16777215, 5592405},
  {33554431, 1082401},
};

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  //for (int i = 2; i <= 25; ++i) {
    //int x = (1 << i) - 1;
    //pre[x] = f(x);
    //cerr << "{" << x << ", " << f(x) << "},\n";
  //}

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a;
    cin >> a;
    if (pre.count(a)) {
      cout << pre[a] << '\n';
    } else {
      auto it = pre.lower_bound(a);
      assert(it != pre.end());
      cout << it->first << '\n';
    }
  }
}