#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[20000], n;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++ i) cin >> a[i];
  int has(0), d(1), p(0), ret(0);
  for (int _ = 0; _ < n; ) {
    bool flag(0);
    for (int i = 0; i < n && i * d + p >= 0 && i * d + p < n; ++ i) {
      if (a[i * d + p] != -1 && has >= a[i * d + p]) {
        a[i * d + p] = -1; p = i * d + p;
        has ++; flag = 1; break;
      }
    }
    if (!flag) ++ ret, d *= -1;
    else ++ _;
  }
  cout << ret << endl;
  return 0;
}